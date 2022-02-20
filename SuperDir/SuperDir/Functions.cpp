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
				
				FileInfo_Base Init();
				i++;
			}
			else if (0 == _stricmp(".h", (const char*)ffd.cFileName + lLen - 2))
			{
				lFiles[i] = new FileInfo_H;
				i++;
			}
			else if (0 == _stricmp(".EXE", (const char*)ffd.cFileName + lLen - 4))
			{
				lFiles[i] = new FileInfo_EXE;
				i++;
			}
			else
			{
				lFiles[i] = new FileInfo_Other;
				i++;
			}
			
			
		}
		
	} while (FindNextFile(hFind, &ffd) != 0);
	
	return lFiles;
}



/*if (INVALID_HANDLE_VALUE == hFind)
	{
		DisplayErrorBox(TEXT("FindFirstFile"));
		return dwError;
	}*/



//void DisplayErrorBox(LPTSTR lpszFunction)
//{
//    // Retrieve the system error message for the last-error code
//
//    LPVOID lpMsgBuf;
//    LPVOID lpDisplayBuf;
//    DWORD dw = GetLastError();
//
//    FormatMessage(
//        FORMAT_MESSAGE_ALLOCATE_BUFFER |
//        FORMAT_MESSAGE_FROM_SYSTEM |
//        FORMAT_MESSAGE_IGNORE_INSERTS,
//        NULL,
//        dw,
//        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//        (LPTSTR)&lpMsgBuf,
//        0, NULL);
//
//    // Display the error message and clean up
//
//    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
//        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
//    StringCchPrintf((LPTSTR)lpDisplayBuf,
//        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
//        TEXT("%s failed with error %d: %s"),
//        lpszFunction, dw, lpMsgBuf);
//    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
//
//    LocalFree(lpMsgBuf);
//    LocalFree(lpDisplayBuf);
//}
