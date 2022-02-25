#include "FileInfo_EXE.h"
#include <iostream>

FileInfo_EXE::~FileInfo_EXE()
{
	delete[] mFile;
}

void FileInfo_EXE::DisplayInformation()
{
	std::cout << size << " Size\n";
}

FileInfo_EXE::FileInfo_EXE()
{
}
