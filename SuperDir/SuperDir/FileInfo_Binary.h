#pragma once
#include "FileInfo_Base.h"
class FileInfo_Binary : public FileInfo_Base
{
public:

    virtual ~FileInfo_Binary();

    virtual void RetrieveInformation();

protected:
    FileInfo_Binary();

};



