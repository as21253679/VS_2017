// encryption.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "stdafx.h"
#include <cstdio>
#include "Dll1.h"

#include <stdio.h>
#include <string.h>
#include <io.h> //c_file
#include <direct.h> 
#include <iostream> 
#include <Windows.h>
#include <fstream>

using namespace std;

long file_size(char *file)
{
	struct stat st;
	stat(file, &st);
	return st.st_size;
}

HANDLE Open_mass_storage(char *file)
{
	TCHAR filename_t[100] = { 0 };
	mbstowcs(filename_t, file, strlen(file));

	HANDLE hdisk = CreateFile(filename_t,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		nullptr,
		OPEN_EXISTING,
		0, NULL);
	if (hdisk == INVALID_HANDLE_VALUE)
	{
		int err = GetLastError();
		printf("Open_mass_storage error\n");
	}
	return hdisk;
}

void Read_Write_mass_storage(HANDLE pFile, long size, int parameter, bool flag)
{
	bool ok;
	char data[1];
	DWORD write;
	LARGE_INTEGER position = { 0 };

	for (long i = 0; i < size; i++)
	{
		position.QuadPart = i;  //set position address
		ok = SetFilePointerEx(pFile, position, nullptr, FILE_BEGIN);
		if (!ok)
		{
			printf("SetFilePointer error\n");
		}
		ok = ReadFile(pFile, data, 1, &write, nullptr);
		if (!ok)
		{
			printf("ReadFile error\n");
		}

		if (flag)	//true=加密,false=解密
			data[0] += parameter;
		else
			data[0] -= parameter;
		position.QuadPart = i;  //set position address
		ok = SetFilePointerEx(pFile, position, nullptr, FILE_BEGIN);
		if (!ok)
		{
			printf("SetFilePointer error\n");
		}
		ok = WriteFile(pFile, data, 1, &write, nullptr);
		if (!ok)
		{
			printf("WriteFile error\n");
		}
	}
}

__declspec(dllexport) void encode(char *filename, int parameter)
{
	long size = file_size(filename);
	HANDLE pFile = Open_mass_storage(filename);
	Read_Write_mass_storage(pFile, size, parameter, true);
	CloseHandle(pFile);
}

__declspec(dllexport) void decode(char *filename, int parameter)
{
	long size = file_size(filename);
	HANDLE pFile = Open_mass_storage(filename);
	Read_Write_mass_storage(pFile, size, parameter, false);
	CloseHandle(pFile);
}
