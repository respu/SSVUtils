// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "SSVUtils/Tokenizer/TokenizerRule.h"

using namespace std;

namespace ssvu
{
	bool TokenizerRule::isInitial(char mChar) const { return onIsInitial != nullptr && onIsInitial(mChar); }
	bool TokenizerRule::isValid(char mChar) const { return onIsValid != nullptr && onIsValid(mChar); }
	bool TokenizerRule::isKeyword(const vector<char>& mCurrentToken) const { return onIsKeyword != nullptr && onIsKeyword(mCurrentToken); }
}
