#include "FileInfo_Binary.h"
#include <fstream>

FileInfo_Binary::~FileInfo_Binary()
{
}

void FileInfo_Binary::RetrieveInformation()
{

    std::ifstream::pos_type filesize(const char* filename)
    {
        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        return in.tellg();
    }
}

FileInfo_Binary::FileInfo_Binary()
{
}
