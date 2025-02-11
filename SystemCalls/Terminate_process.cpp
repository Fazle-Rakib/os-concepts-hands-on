#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    STARTUPINFOW si = {sizeof(si)};
    PROCESS_INFORMATION pi;

    // Creating a new process (notepad.exe)
    if (CreateProcessW(
            L"C:\\Windows\\System32\\notepad.exe",  // Path to the executable
            NULL,    // Command line arguments
            NULL,    // Process security attributes
            NULL,    // Thread security attributes
            FALSE,   // Handle inheritance
            0,       // Creation flags
            NULL,    // Environment variables
            NULL,    // Current directory
            &si,     // Startup Info
            &pi      // Process Information
        )) {
        cout << "Process created successfully. PID: " << pi.dwProcessId << endl;
        cout << "Press Enter to terminate the process..." << endl;
        cin.get(); // Wait for user input

        // Terminate the process
        if (TerminateProcess(pi.hProcess, 1)) {
            cout << "Process terminated." << endl;
        } else {
            cout << "TerminateProcess failed." << endl;
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        cout << "Process creation failed. "<< endl;
    }

    return 0;
}
