#include "FileInfo_EXE.h"
#include <iostream>

FileInfo_EXE::~FileInfo_EXE()
{
}

void FileInfo_EXE::DisplayInformation()
{
	std::cout << size << " Size\n";
}

FileInfo_EXE::FileInfo_EXE()
{
}
