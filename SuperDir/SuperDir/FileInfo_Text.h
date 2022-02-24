#pragma once
#include "FileInfo_Base.h"
class FileInfo_Text : public FileInfo_Base
{
public:

    virtual ~FileInfo_Text();

    virtual void RetrieveInformation();

protected:
    FileInfo_Text();
    unsigned int lLineCount = 0;
};