// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_TOKENIZER
#define SSVU_TOKENIZER

#include <string>
#include <vector>
#include <functional>
#include "SSVUtils/Tokenizer/TokenizerRule.h"

namespace ssvu
{
	class Token;

	class Tokenizer
	{
		private:
			std::vector<TokenizerRule> rules;

			void emitToken(std::vector<char>& mCurrentToken, std::vector<Token>& mTarget) const;
			bool isIgnored(char mChar) const;
			std::string matchType(const std::string& mValue) const;

		public:
			std::function<bool(char)> onIsIgnored;
			std::function<std::string(const std::string&)> onMatchType;
			std::vector<Token> tokenize(const std::string& mString) const;
			void addRule(const TokenizerRule& mRule);
	};
}

#endif
