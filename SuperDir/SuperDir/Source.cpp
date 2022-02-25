#include "IFileInfo.h"
#include <xlocinfo>

IFileInfo** FindFiles(const char* aFolder);
void RetrieveInformation(IFileInfo** aFiles);
void DisplayInformation(IFileInfo** aFiles);
void ReleaseMemory(IFileInfo** aFiles);
int main(int aCount, const char** aVector)
{
	IFileInfo** foundFile = FindFiles(aVector[1]);
	RetrieveInformation(foundFile);
	DisplayInformation(foundFile);
	ReleaseMemory(foundFile);
}