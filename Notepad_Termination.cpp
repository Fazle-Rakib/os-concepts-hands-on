#include <windows.h>
#include <iostream>

using namespace std;

void CloseProcess() {
    Sleep(500);
    HWND hwnd = FindWindowW(NULL, L"Untitled - Notepad");

    if (hwnd) {
        cout << "Found Notepad!"<<endl;
        PostMessage(hwnd, WM_CLOSE, 0, 0);
    } else {
        cerr << "Error: Could not find Notepad window!"<<endl;
    }
}

int main() {
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;

    if (CreateProcess(TEXT("C:\\Windows\\System32\\notepad.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        Sleep(1000);
        cout << "Process started. Process closing in 4 seconds"<<endl;
        Sleep(4000);

        CloseProcess();

        Sleep(3000);

        DWORD exitCode;
        GetExitCodeProcess(pi.hProcess, &exitCode);
        if (exitCode == STILL_ACTIVE) {
            cout << "Forcefully terminating process"<<endl;
            TerminateProcess(pi.hProcess, 0);
        } else {
            cout << "Process closed gracefully."<<endl;
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        cerr << "Failed to create process. Error: " << GetLastError() << endl;
    }

    return 0;
}
