#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    STARTUPINFOW si = {sizeof(si)};
    PROCESS_INFORMATION pi;

    if (CreateProcessW(L"C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        cout << "Process created successfully. PID: " << pi.dwProcessId << endl;

        for (int i = 0; i < 50; i++) {
            if (_kbhit()) {
                _getch();
                break;
            }
            Sleep(100);
        }

        HWND hwnd = FindWindowW(L"Notepad", NULL);
        if (hwnd) {
            PostMessage(hwnd, WM_CLOSE, 0, 0);  // Request Notepad to close
            cout << "WM_CLOSE message sent to Notepad." << endl;
        } else {
            cerr << "Failed to find Notepad window." << endl;
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        cerr << "Process creation failed. Error: " << GetLastError() << endl;
    }

    return 0;
}
