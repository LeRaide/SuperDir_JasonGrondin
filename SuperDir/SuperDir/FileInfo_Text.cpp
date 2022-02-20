#include "FileInfo_Text.h"
#include <cstddef>
#include <xpolymorphic_allocator.h>

FileInfo_Text::~FileInfo_Text()
{
}

void FileInfo_Text::RetrieveInformation()
{
	FileInfo_Base* lFile;
	char lLine[1024];
	unsigned int lLineCount = 0;
	while (NULL != fgets(lLine, sizeof(lLine), lFile))
	{
		lLineCount++;
	}
}

FileInfo_Text::FileInfo_Text()
{
}
