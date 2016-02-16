#pragma once

#include <tuple>
#include <string>
#include <vector>

namespace calc {
    enum class TokenType {
        None,
        Operator,
        Number
    };

    using Token = std::tuple<std::string, TokenType>;

    std::vector<Token> tokenise(std::string data);
}