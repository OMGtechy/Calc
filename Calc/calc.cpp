#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <tuple>
#include <memory>
#include <set>
#include <deque>

#include "tokenise.h"

namespace calc {
    struct Expression {
        virtual ~Expression() = default;       
    };

    struct BinaryOperation : public Expression {
        std::unique_ptr<Expression> lhs, rhs;
        std::string operation;
    };

    struct Number : public Expression {
        Number(std::string lexeme_)
            : lexeme(lexeme_) {
    
        }

        std::string lexeme;
    };

    std::unique_ptr<Expression> parse(const std::vector<Token>& tokens) {
        std::vector<std::string> binaryOperations;
        std::deque<std::unique_ptr<Expression>> expressions;

        for(const auto token : tokens) {
            switch(std::get<TokenType>(token)) {
            case TokenType::Operator:
                // TODO: check for unary operations
                binaryOperations.push_back(std::get<std::string>(token));
                break;
            case TokenType::Number:
                expressions.push_back(std::make_unique<Number>(std::get<std::string>(token)));
                break;
            }
        }

        const std::set<std::string> operatorsInOrderOfPrecendence[] {
            { std::string("*"), std::string("/") },
            { std::string("+"), std::string("-") }
        };

        for(const auto operatorSet : operatorsInOrderOfPrecendence) {
            for(auto iter = binaryOperations.begin(); iter != binaryOperations.end();) {
                if(operatorSet.find(*iter) != operatorSet.cend()) {
                    auto binaryOperation = std::make_unique<BinaryOperation>();
                    const auto index = std::distance(binaryOperations.begin(), iter);

                    // TODO: check there are expressions left to take!
                    binaryOperation->lhs = std::move(expressions[index]);
                    expressions.erase(expressions.begin() + index);
            
                    binaryOperation->rhs = std::move(expressions[index]);
                    expressions.erase(expressions.begin() + index);

                    binaryOperation->operation = *iter;

                    expressions.insert(expressions.begin() + index, std::move(binaryOperation));

                    iter = binaryOperations.erase(iter);
                } else {
                    ++iter;
                }
            }
        }

        if(expressions.size() != 1) {
            throw; // errrorororor
        }

        return std::move(expressions.front());
    }

    double evaluate(const Expression&);

    double evaluateBinaryOperation(const Expression& lhs, const std::string& operation, const Expression& rhs) {
             if(operation == "*") return evaluate(lhs) * evaluate(rhs);
        else if(operation == "+") return evaluate(lhs) + evaluate(rhs);
        else if(operation == "-") return evaluate(lhs) - evaluate(rhs);
        else if(operation == "/") return evaluate(lhs) / evaluate(rhs);
        else throw; // errorororororo
    }

    double evaluate(const Expression& expression) {
        if(auto* binaryOperation = dynamic_cast<const BinaryOperation*>(&expression)) {
            return evaluateBinaryOperation(*binaryOperation->lhs, binaryOperation->operation, *binaryOperation->rhs.get());
        } else if(auto numericExpression = dynamic_cast<const Number*>(&expression)) {
            // TODO: add decimal value support
            return atoi(numericExpression->lexeme.c_str());
        } else {
            throw; // errrororor
        }
    }
}

int main() {
    using namespace calc;

    std::cout << evaluate(*parse(tokenise("1 / 3"))) << std::endl;
    std::cin.get();
}
