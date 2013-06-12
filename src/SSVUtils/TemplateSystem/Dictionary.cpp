// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "SSVUtils/TemplateSystem/Dictionary.h"
#include "SSVUtils/String/Utils.h"
#include "SSVUtils/Tokenizer/Token.h"
#include "SSVUtils/Log/Log.h"

using namespace std;
using namespace ssvu::TemplateSystem::Internal;

namespace ssvu
{
	namespace TemplateSystem
	{
		Dictionary::Dictionary()
		{
			tokenizer.onIsIgnored = [](char mChar){ return iscntrl(mChar) || isspace(mChar); };
			tokenizer.onMatchType = [](const string& mValue){ return Internal::matchTokenType(mValue); };

			TokenizerRule symbolRule, restRule;
			symbolRule.onIsInitial = [](char mChar){ return Internal::isInitialChar(mChar); };
			symbolRule.onIsValid = [](char mChar){ return Internal::isValidChar(mChar); };
			symbolRule.onIsKeyword = [](const vector<char> mCurrentToken){ return Internal::isKeyword(mCurrentToken); };

			restRule.onIsInitial = [](char mChar){ return !Internal::isValidChar(mChar); };
			restRule.onIsValid = [](char mChar){ return !Internal::isValidChar(mChar); };

			tokenizer.addRule(symbolRule);
			tokenizer.addRule(restRule);
		}
		Dictionary::Dictionary(initializer_list<pair<string, string>> mPairs) : Dictionary() { for(const auto& p : mPairs) replacements.insert(p); }

		void Dictionary::expandSections(string& mString) const
		{
			for(const auto& p : sectionDictionaries)
			{
				const string sectionStart{getSectionStart(p.first)}, sectionEnd{getSectionEnd(p.first)};
				const auto outerSectionStartIndex(mString.find(sectionStart));
				const auto innerSectionEndIndex(mString.find(sectionEnd));
				const auto innerSectionStartIndex(outerSectionStartIndex + sectionStart.length());
				const auto outerSectionEndIndex(innerSectionEndIndex + sectionEnd.length());

				const string innerSection{mString.substr(innerSectionStartIndex, innerSectionEndIndex - innerSectionStartIndex)};
				string innerSectionResult{""};

				for(const auto& d : p.second) innerSectionResult += d.getExpanded(innerSection);

				mString.replace(outerSectionStartIndex, outerSectionEndIndex - outerSectionStartIndex, innerSectionResult);
			}
		}
		void Dictionary::expandReplacements(string& mString) const
		{
			for(const auto& p : replacements) replaceAll(mString, getKey(p.first), p.second);
		}
		void Dictionary::cleanUpUnexpanded(string& mString) const
		{
			vector<Token<Internal::TokenType>> tokens{tokenizer.tokenize("{{a[[sdga{{15dgaa{{1{")};
			for(auto& t : tokens) log(t.getValue(), toStr((int)t.getType()));
		}

		string Dictionary::getExpanded(string mString) const
		{
			expandSections(mString);
			expandReplacements(mString);
			cleanUpUnexpanded(mString);

			// TODO: cleanup unexpanded sections/replacements?
			// TODO: newline stripping options?

			return mString;
		}

		string& Dictionary::operator[](const string& mKey) { return replacements[mKey]; }
		void Dictionary::operator+=(const pair<string, Dictionary>& mPair) { sectionDictionaries[mPair.first].push_back(mPair.second); }
	}
}
