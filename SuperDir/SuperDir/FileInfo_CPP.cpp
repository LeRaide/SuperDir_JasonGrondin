#include "FileInfo_CPP.h"
#include <iostream>

FileInfo_CPP::~FileInfo_CPP()
{
	delete[] mFile;
}

void FileInfo_CPP::DisplayInformation()
{
	std::cout << lLineCount << " lignes\n";
}

FileInfo_CPP::FileInfo_CPP()
{
}
