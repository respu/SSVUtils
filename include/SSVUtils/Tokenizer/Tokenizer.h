// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_TOKENIZER
#define SSVU_TOKENIZER

#include <string>
#include <vector>
#include <functional>
#include "SSVUtils/Tokenizer/Token.h"
#include "SSVUtils/Tokenizer/TokenizerRule.h"

namespace ssvu
{
	template<typename T> class Tokenizer
	{
		public:
			std::function<bool(char)> onIsIgnored;
			std::function<T(const std::string&)> onMatchType;

		private:
			std::vector<TokenizerRule> rules;

			bool isIgnored(char mChar) const { return onIsIgnored != nullptr && onIsIgnored(mChar); }
			void emitToken(std::vector<char>& mCurrentToken, std::vector<Token<T>>& mTarget) const
			{
				if(mCurrentToken.empty()) return;

				std::string value{std::begin(mCurrentToken), std::end(mCurrentToken)};
				mTarget.push_back({onMatchType(value), value});
				mCurrentToken.clear();
			}
			void computeToken(std::string::const_iterator& mIterator, std::vector<char>& mCurrentToken, std::vector<Token<T>>& mTarget) const
			{
				for(const auto& r : rules)
				{
					if(!r.isInitial(*mIterator)) continue;
					for(; !isIgnored(*mIterator) && r.isValid(*mIterator) && !r.isKeyword(mCurrentToken); ++mIterator) mCurrentToken.push_back(*mIterator);

					emitToken(mCurrentToken, mTarget);
					--mIterator; return;
				}
			}

		public:
			std::vector<Token<T>> tokenize(const std::string& mString) const
			{
				std::vector<Token<T>> result;
				std::vector<char> currentToken;

				for(auto itr(std::begin(mString)); itr != std::end(mString); ++itr)
				{
					if(isIgnored(*itr)) emitToken(currentToken, result);
					else computeToken(itr, currentToken, result);
				}

				return result;
			}
			void addRule(const TokenizerRule& mRule) { rules.push_back(mRule); }
	};
}

#endif
