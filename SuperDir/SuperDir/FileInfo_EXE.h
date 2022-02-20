#pragma once
#include "FileInfo_Binary.h"
class FileInfo_EXE : public FileInfo_Binary
{
public:

    virtual ~FileInfo_EXE();
    FileInfo_EXE();
    virtual void DisplayInformation();

protected:
    

};