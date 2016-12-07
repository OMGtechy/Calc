/*
    This file is part of Calc.

    Calc is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Calc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

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
