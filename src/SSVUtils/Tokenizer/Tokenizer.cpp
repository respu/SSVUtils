// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

//#include "SSVUtils/Tokenizer/Token.h"
//#include "SSVUtils/Tokenizer/Tokenizer.h"

using namespace std;

namespace ssvu
{
	/*bool Tokenizer::isIgnored(char mChar) const { return onIsIgnored != nullptr && onIsIgnored(mChar); }
	string Tokenizer::matchType(const string& mValue) const { return onMatchType != nullptr ? onMatchType(mValue) : ""; }

	void Tokenizer::emitToken(vector<char>& mCurrentToken, vector<Token>& mTarget) const
	{
		if(mCurrentToken.empty()) return;

		string value{begin(mCurrentToken), end(mCurrentToken)};
		mTarget.push_back({matchType(value), value});
		mCurrentToken.clear();
	}

	void Tokenizer::computeToken(string::const_iterator& mIterator, vector<char>& mCurrentToken, vector<Token>& mTarget) const
	{
		for(const auto& r : rules)
		{
			if(!r.isInitial(*mIterator)) continue;
			for(; !isIgnored(*mIterator) && r.isValid(*mIterator) && !r.isKeyword(mCurrentToken); ++mIterator) mCurrentToken.push_back(*mIterator);

			emitToken(mCurrentToken, mTarget);
			--mIterator; return;
		}
	}
	vector<Token> Tokenizer::tokenize(const string& mString) const
	{
		vector<Token> result;
		vector<char> currentToken;

		for(auto itr(begin(mString)); itr != end(mString); ++itr)
		{
			if(isIgnored(*itr)) emitToken(currentToken, result);
			else computeToken(itr, currentToken, result);
		}

		return result;
	}

	void Tokenizer::addRule(const TokenizerRule& mRule) { rules.push_back(mRule); }*/
}
