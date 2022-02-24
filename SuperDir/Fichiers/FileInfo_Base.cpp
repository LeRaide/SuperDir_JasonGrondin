#include "FileInfo_Base.h"
#include <cassert>
#include <string.h>

FileInfo_Base::~FileInfo_Base()
{
}

void FileInfo_Base::Init(const char* aFolder, const char* aFile)
{
	assert(NULL != aFolder);
    unsigned int lLen = strlen(aFolder);
	strcpy_s(mFolder, lLen + 1, aFolder);

	assert(NULL != aFile);
	lLen = strlen(aFile);
	strcpy_s(mFile, lLen + 1, aFile);
}

FileInfo_Base::FileInfo_Base()
{
}


