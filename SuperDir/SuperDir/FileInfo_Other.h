#pragma once
#include "FileInfo_Binary.h"
class FileInfo_Other : public FileInfo_Binary
{
public:

    virtual ~FileInfo_Other();
    FileInfo_Other();
    virtual void DisplayInformation();

protected:
   

};