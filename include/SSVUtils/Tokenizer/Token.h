// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_TOKENIZER_TOKEN
#define SSVU_TOKENIZER_TOKEN

#include <string>

namespace ssvu
{
	template<typename T> class Token
	{
		private:
			T type;
			std::string value;

		public:
			Token(T&& mType, const std::string& mValue) : type{mType}, value{mValue} { }
			T getType() const { return type; }
			std::string getValue() const { return value; }
	};
}

#endif
