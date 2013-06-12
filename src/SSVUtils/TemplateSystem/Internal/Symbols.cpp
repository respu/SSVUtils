// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "SSVUtils/TemplateSystem/Internal/Symbols.h"
#include "SSVUtils/Utils/UtilsContainers.h"

using namespace std;

namespace ssvu
{
	namespace TemplateSystem
	{
		namespace Internal
		{
			const string keyLeft{"{{"};
			const string keyRight{"}}"};
			const string sectionStartLeft{"{{#"};
			const string sectionStartRight{"}}"};
			const string sectionEndLeft{"{{/"};
			const string sectionEndRight{"}}"};
			const vector<string> symbols{keyLeft, keyRight, sectionStartLeft, sectionStartRight, sectionEndLeft, sectionEndRight};
			const vector<char> initialChars{keyLeft[0], keyRight[0], sectionStartLeft[0], sectionStartRight[0], sectionEndLeft[0], sectionEndRight[0]};
			vector<char> validChars;

			string getKey(const string& mString) { return keyLeft + mString + keyRight; }
			string getSectionStart(const string& mString) { return sectionStartLeft + mString + sectionStartRight; }
			string getSectionEnd(const string& mString) { return sectionEndLeft + mString + sectionEndRight; }
			TokenType matchTokenType(const string& mValue)
			{
				if(mValue == keyLeft)					return TokenType::KeyLeft;
				else if(mValue == keyRight)				return TokenType::KeyRight;
				else if(mValue == sectionStartLeft)		return TokenType::SectionStartLeft;
				else if(mValue == sectionStartRight)	return TokenType::SectionStartRight;
				else if(mValue == sectionEndLeft)		return TokenType::SectionEndLeft;
				else if(mValue == sectionEndRight)		return TokenType::SectionEndRight;
				return TokenType::Other;
			}
			bool isKeyword(const vector<char>& mCurrentToken) { return contains(symbols, string{begin(mCurrentToken), end(mCurrentToken)}); }
			bool isInitialChar(char mChar) { return contains(initialChars, mChar); }
			bool isValidChar(char mChar)
			{
				if(validChars.empty()) for(const auto& s : symbols) for(const auto& c : s) if(!contains(validChars, c)) validChars.push_back(c);
				return contains(validChars, mChar);
			}
			const vector<string> getSymbols() { return symbols; }
		}
	}
}
