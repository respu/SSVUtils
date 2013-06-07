// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "SSVUtils/FileSystem/FileSystem.h"
#include "SSVUtils/Utils/UtilsString.h"

using namespace std;

namespace ssvu
{
	namespace FileSystem
	{
		void fillFiles(vector<string>& mResult, const string& mPath)										{ FillHelper<Mode::NON_RECURSIVE, Type::FILES>::fill(mResult, mPath); }
		void fillFilesByExtension(vector<string>& mResult, const string& mPath, const string& mExtension)	{ FillHelper<Mode::NON_RECURSIVE, Type::FILES, Pick::BY_FILE_EXTENSION>::fill(mResult, mPath, mExtension); }
		void fillFilesByName(vector<string>& mResult, const string& mPath, const string& mName)				{ FillHelper<Mode::NON_RECURSIVE, Type::FILES, Pick::BY_FILE_NAME>::fill(mResult, mPath, mName); }
		void fillFolders(vector<string>& mResult, const string& mPath)										{ FillHelper<Mode::NON_RECURSIVE, Type::FOLDERS>::fill(mResult, mPath); }
		void fillAll(vector<string>& mResult, const string& mPath)											{ FillHelper<Mode::NON_RECURSIVE, Type::ALL>::fill(mResult, mPath); }

		void recursiveFillFiles(vector<string>& mResult, const string& mPath)										{ FillHelper<Mode::RECURSIVE, Type::FILES>::fill(mResult, mPath); }
		void recursiveFillFilesByExtension(vector<string>& mResult, const string& mPath, const string& mExtension)	{ FillHelper<Mode::RECURSIVE, Type::FILES, Pick::BY_FILE_EXTENSION>::fill(mResult, mPath, mExtension); }
		void recursiveFillFilesByName(vector<string>& mResult, const string& mPath, const string& mName)			{ FillHelper<Mode::RECURSIVE, Type::FILES, Pick::BY_FILE_NAME>::fill(mResult, mPath, mName); }
		void recursiveFillFolders(vector<string>& mResult, const string& mPath)										{ FillHelper<Mode::RECURSIVE, Type::FOLDERS>::fill(mResult, mPath); }
		void recursiveFillAll(vector<string>& mResult, const string& mPath)											{ FillHelper<Mode::RECURSIVE, Type::ALL>::fill(mResult, mPath); }

		vector<string> getFiles(const string& mPath)										{ vector<string> result; fillFiles(result, mPath); return result; }
		vector<string> getFilesByExtension(const string& mPath, const string& mExtension)	{ vector<string> result; fillFilesByExtension(result, mPath, mExtension); return result; }
		vector<string> getFilesByName(const string& mPath, const string& mName)				{ vector<string> result; fillFilesByName(result, mPath, mName); return result; }
		vector<string> getFolders(const string& mPath)										{ vector<string> result; fillFolders(result, mPath); return result; }
		vector<string> getAll(const string& mPath)											{ vector<string> result; fillAll(result, mPath); return result; }

		vector<string> getRecursiveFiles(const string& mPath)										{ vector<string> result; recursiveFillFiles(result, mPath); return result; }
		vector<string> getRecursiveFilesByExtension(const string& mPath, const string& mExtension)	{ vector<string> result; recursiveFillFilesByExtension(result, mPath, mExtension); return result; }
		vector<string> getRecursiveFilesByName(const string& mPath, const string& mName)			{ vector<string> result; recursiveFillFilesByName(result, mPath, mName); return result; }
		vector<string> getRecursiveFolders(const string& mPath)										{ vector<string> result; recursiveFillFolders(result, mPath); return result; }
		vector<string> getRecursiveAll(const string& mPath)											{ vector<string> result; recursiveFillAll(result, mPath); return result; }
	}
}

