#pragma once
#include "IFileInfo.h"
class FileInfo_Base : public IFileInfo
{
    
public:
    
    virtual ~FileInfo_Base();
    char mFolder[512];
    char mFile[256];
    virtual void Init(const char * aFolder, const char* aFile);

protected:
    FileInfo_Base();
    
};
