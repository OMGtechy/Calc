#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <tuple>
#include <memory>
#include <set>
#include <deque>

enum class TokenType {
    None,
    Operator,
    Number
};

using Token = std::tuple<std::string, TokenType>;

constexpr bool isMultiplication(const char character) {
    return character == '*';
}

constexpr bool isAddition(const char character) {
    return character == '+';
}

constexpr bool isSubtraction(const char character) {
    return character == '-';
}

constexpr bool isDivision(const char character) {
    return character == '/';
}

constexpr bool isOperator(char character) {
    return isMultiplication(character)
        || isAddition(character)
        || isSubtraction(character)
        || isDivision(character);
}

auto tokenise(std::string data) {
    data += '\x03';

    std::vector<Token> tokens;

    TokenType currentTokenType = TokenType::None;
    std::string currentLexeme;

    for(auto iter = data.cbegin(); iter != data.cend();) {
        switch(currentTokenType) {
        case TokenType::None:
            if(std::isdigit(*iter)) {
                currentTokenType = TokenType::Number;
                continue;
            } else if(isOperator(*iter)) {
                currentTokenType = TokenType::Operator;
                continue;
            }
            break;
        case TokenType::Operator:
            // TODO: this will accept strings like +*-/ ... it shouldn't
            if(isOperator(*iter)) {
                currentLexeme += *iter;
            } else {
                tokens.push_back(decltype(tokens)::value_type(currentLexeme, currentTokenType));
                currentLexeme = "";
                currentTokenType = TokenType::None;
                continue;
            }
            break;
        case TokenType::Number:
            if(std::isdigit(*iter)) {
                currentLexeme += *iter;
            } else {
                tokens.push_back(decltype(tokens)::value_type(currentLexeme, currentTokenType));
                currentLexeme = "";
                currentTokenType = TokenType::None;
                continue;
            }
            break;
        }

        ++iter;
    }

    return tokens;
}

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

double evaluate(Expression*);

// TODO: const correctness + should these be references?
double evaluateBinaryOperation(Expression* lhs, std::string operation, Expression* rhs) {
         if(operation == "*") return evaluate(lhs) * evaluate(rhs);
    else if(operation == "+") return evaluate(lhs) + evaluate(rhs);
    else if(operation == "-") return evaluate(lhs) - evaluate(rhs);
    else if(operation == "/") return evaluate(lhs) / evaluate(rhs);
    else throw; // errorororororo
}

// TODO: should this be a reference or * const?
double evaluate(Expression* expression) {
    if(auto* binaryOperation = dynamic_cast<BinaryOperation*>(expression)) {
        return evaluateBinaryOperation(binaryOperation->lhs.get(), binaryOperation->operation, binaryOperation->rhs.get());
    } else if(auto numericExpression = dynamic_cast<Number*>(expression)) {
        // TODO: add decimal value support
        return atoi(numericExpression->lexeme.c_str());
    } else {
        throw; // errrororor
    }
}

int main() {
    std::cout << evaluate(parse(tokenise("1 / 3")).get()) << std::endl;
    std::cin.get();
}
