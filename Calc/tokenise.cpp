#include "tokenise.h"

#include <cctype>

namespace {
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
}

std::vector<calc::Token> calc::tokenise(std::string data) {
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
