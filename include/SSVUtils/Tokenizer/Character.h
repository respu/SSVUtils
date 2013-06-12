// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_TOKENIZER_CHARACTER
#define SSVU_TOKENIZER_CHARACTER

#include <string>

namespace ssvu
{
	struct Character
	{
		std::string& source;
		char character;
		unsigned int position;
	};
}

#endif
