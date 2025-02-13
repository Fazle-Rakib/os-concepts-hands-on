
#include<windows.h>
#include<stdio.h>
int main() {

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (CreateProcess(
        "C:\\Windows\\System32\\notepad.exe", // Path to executable
        NULL,                               // Command line (NULL means default)
        NULL,                               // Process security attributes
        NULL,                               // Thread security attributes
        FALSE,                              // Inherit handles
        0,                                  // Creation flags
        NULL,                               // Environment
        NULL,                               // Current directory
        &si,                                // Startup info
        &pi                                 // Process information
    )) {
        printf("Process created successfully!\n");
        Sleep(5000);
        // Terminate the process after 5 seconds
        TerminateProcess(pi.hProcess, 0);
        printf("Process terminated after 5 seconds.\n");
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        printf("Failed to create process. Error: %lu\n", GetLastError());
    }

    return 0;
}
