// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "SSVUtils/Tokenizer/Token.h"

using namespace std;

namespace ssvu
{
	Token::Token(const string& mType, const string& mValue) : type{mType}, value{mValue} { }
	string Token::getType() const { return type; }
	string Token::getValue() const { return value; }
}
