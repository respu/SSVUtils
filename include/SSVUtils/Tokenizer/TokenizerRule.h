// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_TOKENIZER_RULE
#define SSVU_TOKENIZER_RULE

#include <vector>
#include <functional>

namespace ssvu
{
	class TokenizerRule
	{


		public:
			bool isInitial(char mChar) const;
			bool isValid(char mChar) const;
			bool isKeyword(const std::vector<char>& mCurrentToken) const;

		public:
			std::function<bool(char)> onIsInitial;
			std::function<bool(char)> onIsValid;
			std::function<bool(const std::vector<char>&)> onIsKeyword;
	};
}

#endif
