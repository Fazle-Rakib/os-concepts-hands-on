#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFOW));
    si.cb = sizeof(STARTUPINFOW);
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

    wstring processName = L"C:\\Windows\\System32\\notepad.exe";

    if (!CreateProcessW(processName.c_str(), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        cerr << "Failed to create process. Error: " << GetLastError() << endl;
        return 1;
    }

    cout << "Process created successfully!" << endl;
    cout << "Process ID: " << pi.dwProcessId << endl;
    cout << "Thread ID: " << pi.dwThreadId << endl;

    Sleep(3000);

    if (!TerminateProcess(pi.hProcess, 0)) {
        cerr << "Failed to terminate process. Error: " << GetLastError() << endl;
    } else {
        cout << "Process terminated successfully." << endl;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
