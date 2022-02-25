#include "FileInfo_H.h"
#include <iostream>

FileInfo_H::~FileInfo_H()
{
	delete[] mFile;
}

void FileInfo_H::DisplayInformation()
{
	std::cout << lLineCount << " lignes\n";
}

FileInfo_H::FileInfo_H()
{
}
