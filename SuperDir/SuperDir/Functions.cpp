#include <iostream>
#include "IFileInfo.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
#include "FileInfo_CPP.h"
#include "FileInfo_H.h"
#include "FileInfo_EXE.h"
#include "FileInfo_Other.h"
#include "FileInfo_Base.h"


IFileInfo** FindFiles(const char* aFolder) 
{
	WIN32_FIND_DATAW ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	TCHAR szDir[MAX_PATH];
    DWORD dwError = 0;
	LARGE_INTEGER filesize;
	IFileInfo** lFiles = new IFileInfo * [100];
	for (unsigned int i = 0; i < 100; i++)
	{
		lFiles[i] = NULL;
	}
	swprintf_s(szDir, L"%S\\*", aFolder);
	hFind = FindFirstFile(szDir, &ffd);
	unsigned int i = 0;
	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			int lLen = strlen((const char*)ffd.cFileName);
			if (0 == _stricmp(".cpp",(const char*)ffd.cFileName + lLen - 4))
			{
				lFiles[i] = new FileInfo_CPP;
				
				lFiles[i]->Init(aFolder,(const char*)ffd.cFileName);
				i++;
			}
			else if (0 == _stricmp(".h", (const char*)ffd.cFileName + lLen - 2))
			{
				lFiles[i] = new FileInfo_H;
				lFiles[i]->Init(aFolder, (const char*)ffd.cFileName);
				i++;
			}
			else if (0 == _stricmp(".EXE", (const char*)ffd.cFileName + lLen - 4))
			{
				lFiles[i] = new FileInfo_EXE;
				lFiles[i]->Init(aFolder, (const char*)ffd.cFileName);
				i++;
			}
			else
			{
				lFiles[i] = new FileInfo_Other;
				lFiles[i]->Init(aFolder, (const char*)ffd.cFileName);
				i++;
			}
			
			
		}
		
	} while (FindNextFile(hFind, &ffd) != 0);
	
	return lFiles;
}
void RetrieveInformation(IFileInfo** aFiles)
{
	for (unsigned int i = 0; i < 100; i++)
	{
		if (NULL != aFiles[i])
		{
			aFiles[i]->RetrieveInformation();
		}
		
	}
}
void DisplayInformation(IFileInfo** aFiles)
{
	for (unsigned int i = 0; i < 100; i++)
	{
		if (NULL != aFiles[i])
		{
			aFiles[i]->DisplayInformation();
		}
	}
}

void ReleaseMemory(IFileInfo** aFiles)
{
	for (unsigned int i = 0; i < 100; i++)
	{
		if (NULL != aFiles[i])
		{
			aFiles[i]->~IFileInfo();
		}
	}
}