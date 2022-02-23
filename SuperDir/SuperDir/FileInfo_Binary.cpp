#include "FileInfo_Binary.h"
#include <fstream>
#include <iostream>

FileInfo_Binary::~FileInfo_Binary()
{
}

void FileInfo_Binary::RetrieveInformation()
{
	FILE* lFile;
	char lFileName[1024];

	strcpy_s(lFileName, mFolder);
	strcpy_s(lFileName, "\\");
	strcpy_s(lFileName, mFile);

	int lRet = fopen_s(&lFile,lFileName, "r");
	fseek(lFile, 0, SEEK_END);
	int size = ftell(lFile);
	std::cout << size << " Size\n"; //A mettre dans le display
	fclose(lFile);
}

FileInfo_Binary::FileInfo_Binary()
{
}
