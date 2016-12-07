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
