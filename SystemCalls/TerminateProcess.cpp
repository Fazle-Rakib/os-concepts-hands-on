#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    STARTUPINFOW si = {sizeof(si)};
    PROCESS_INFORMATION pi;

    // Create the Notepad process
    if (CreateProcessW(
            L"C:\\Windows\\System32\\notepad.exe", 
            NULL, 
            NULL, 
            NULL, 
            FALSE, 
            0, 
            NULL, 
            NULL, 
            &si, 
            &pi 
        )) {
        cout << "Process created successfully. PID: " << pi.dwProcessId << endl;

        Sleep(5000); // Sleep for 5 seconds

        // Terminate the process
        if (TerminateProcess(pi.hProcess, 0)) {
            cout << "Process terminated successfully." << endl;
        } else {
            cerr << "Failed to terminate the process. Error: " << GetLastError() << endl;
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        cerr << "Process creation failed. Error: " << GetLastError() << endl;
    }

    return 0;
}
