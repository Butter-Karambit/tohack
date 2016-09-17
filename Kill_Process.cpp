// code inject.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h""
#include <stdio.h>
#include <Windows.h>
#include <TlHelp32.h>

void close_process(int *pid, char *path)
{
	HANDLE h1;
	h1 = OpenProcess(PROCESS_ALL_ACCESS, FALSE, *pid);
	TerminateProcess(h1, 0);
	CloseHandle(h1);
}

void  search_handle(char* path,int pid)
{
	if (strcmp(path, "1.exe") == 0)
		close_process(&pid, path);
	else if (strcmp(path, "2.exe") == 0)
		close_process(&pid, path);
	else if (strcmp(path, "3.exe") == 0)
		close_process(&pid, path);
	else if (strcmp(path, "4.exe") == 0)
		close_process(&pid, path);
}
int main()
{
	HANDLE h1 = INVALID_HANDLE_VALUE;
	PROCESSENTRY32 pe;

	pe.dwSize = sizeof(PROCESSENTRY32);
	h1 = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(h1, &pe);

	do
	{
		search_handle((char*)pe.szExeFile, pe.th32ProcessID);
	} while (Process32Next(h1, &pe));

	CloseHandle(h1);

	return 0;
}
