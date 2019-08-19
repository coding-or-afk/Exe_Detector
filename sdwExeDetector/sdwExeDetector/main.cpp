#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <tchar.h>
#include <cstdio>

#define DIR_LEN BUFSIZ

int main() {
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 100;
	si.dwXSize = 100;
	si.dwYSize = 100;
	TCHAR command[] = _T("notepad");

	BOOL state;
	while (1) {
		
		HWND hNote;
		hNote = FindWindow(L"Notepad",NULL);
		if (hNote == NULL) {
			state = CreateProcess(NULL, command, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
		}
		else {
			_fputts(_T("Notepad is already ON! \n"),stdout);
		}

		Sleep(3000);
	}

	return 0;
}
