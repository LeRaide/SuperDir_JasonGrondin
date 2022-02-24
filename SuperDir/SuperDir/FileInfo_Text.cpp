#include "FileInfo_Text.h"
#include <cstddef>
#include <xpolymorphic_allocator.h>
#include <iostream>

FileInfo_Text::~FileInfo_Text()
{
}

void FileInfo_Text::RetrieveInformation()
{
	FILE* lFile;
	char lFileName[1024];
	

	strcpy_s(lFileName, mFolder);
	strcpy_s(lFileName, "\\");
	strcpy_s(lFileName, mFile);

	int lRet = fopen_s(&lFile, lFileName, "r");
	char lLine[1024];
	while (NULL != fgets(lLine, sizeof(lLine), lFile))
	{
		lLineCount++;
	}
	fclose(lFile);
}

FileInfo_Text::FileInfo_Text()
{
}
