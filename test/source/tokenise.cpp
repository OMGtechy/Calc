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
    along with Calc.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "tokenise.h"

namespace CalcTest {
    using calc::tokenise;
    using calc::TokenType;

    /*
	TEST_CLASS(TokeniseTest) {
	public:
		TEST_METHOD(TokeniseEmptyString) {
			const auto tokens = tokenise("");
            Assert::AreEqual(size_t(0), tokens.size());
        }

        TEST_METHOD(TokeniseSinglePositiveNumber) {
            const auto tokens = tokenise("4");
            Assert::AreEqual(size_t(1), tokens.size());

            const auto token = tokens[0];
            Assert::AreEqual(std::get<TokenType>(token), TokenType::Number);
            Assert::AreEqual(std::get<std::string>(token), std::string("4"));
        }

        TEST_METHOD(TokeniseSingleNegativeNumber) {
            const auto tokens = tokenise("-4");
            Assert::AreEqual(size_t(2), tokens.size());

            {
                const auto token = tokens[0];
                Assert::AreEqual(std::get<TokenType>(token), TokenType::Operator);
                Assert::AreEqual(std::get<std::string>(token), std::string("-"));
            }

            {
                const auto token = tokens[1];
                Assert::AreEqual(std::get<TokenType>(token), TokenType::Number);
                Assert::AreEqual(std::get<std::string>(token), std::string("4"));
            }
        }

        TEST_METHOD(TokeniseSingleAdd) {
            const auto tokens = tokenise("+");
            Assert::AreEqual(size_t(1), tokens.size());

            const auto token = tokens[0];
            Assert::AreEqual(std::get<TokenType>(token), TokenType::Operator);
            Assert::AreEqual(std::get<std::string>(token), std::string("+"));
        }

        TEST_METHOD(TokeniseSingleSubtract) {
            const auto tokens = tokenise("-");
            Assert::AreEqual(size_t(1), tokens.size());

            const auto token = tokens[0];
            Assert::AreEqual(std::get<TokenType>(token), TokenType::Operator);
            Assert::AreEqual(std::get<std::string>(token), std::string("-"));
        }

        TEST_METHOD(TokeniseSingleMultiply) {
            const auto tokens = tokenise("*");
            Assert::AreEqual(size_t(1), tokens.size());

            const auto token = tokens[0];
            Assert::AreEqual(std::get<TokenType>(token), TokenType::Operator);
            Assert::AreEqual(std::get<std::string>(token), std::string("*"));
        }

        TEST_METHOD(TokeniseSingleDivide) {
            const auto tokens = tokenise("/");
            Assert::AreEqual(size_t(1), tokens.size());

            const auto token = tokens[0];
            Assert::AreEqual(std::get<TokenType>(token), TokenType::Operator);
            Assert::AreEqual(std::get<std::string>(token), std::string("/"));
        }

        TEST_METHOD(TokeniseBinaryAdd) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryMultiply) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinarySubtract) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryDivide) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryAddAdd) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryAddSubtract) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryAddMultiply) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryAddDivide) {
            Assert::Fail(L"Not implemented!");
        }
        TEST_METHOD(TokeniseBinarySubtractAdd) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinarySubtractSubtract) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinarySubtractMultiply) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinarySubtractDivide) {
            Assert::Fail(L"Not implemented!");
        }
        TEST_METHOD(TokeniseBinaryMultiplyAdd) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryMultiplySubtract) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryMultiplyMultiply) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryMultiplyDivide) {
            Assert::Fail(L"Not implemented!");
        }
        TEST_METHOD(TokeniseBinaryDivideAdd) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryDivideSubtract) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryDivideMultiply) {
            Assert::Fail(L"Not implemented!");
        }

        TEST_METHOD(TokeniseBinaryDivideDivide) {
            Assert::Fail(L"Not implemented!");
        }
	};
    */
}
