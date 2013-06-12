// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_TOKENIZER_TOKEN
#define SSVU_TOKENIZER_TOKEN

#include <string>

namespace ssvu
{
	class Token
	{
		private:
			std::string type, value;

		public:
			Token(const std::string& mType, const std::string& mValue);
			std::string getType() const;
			std::string getValue() const;
	};
}

#endif
