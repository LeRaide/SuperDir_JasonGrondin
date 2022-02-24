#include "FileInfo_Other.h"
#include <iostream>

FileInfo_Other::~FileInfo_Other()
{
}

void FileInfo_Other::DisplayInformation()
{
	std::cout << size << " Size\n";
}

FileInfo_Other::FileInfo_Other()
{
}
