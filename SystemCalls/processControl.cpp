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
            //here some attributes info of that process
            cout << "Process created successfully!" << endl;
            cout << "Process ID (PID): " << pi.dwProcessId << endl;
            cout << "Thread ID: " << pi.dwThreadId << endl;
            cout << "Process Handle: " << pi.hProcess << endl;
            cout << "Thread Handle: " << pi.hThread << endl;
            //if i want to terminate my code after 5 second that time use it
               Sleep(5000);
            // Terminate the process
            TerminateProcess(pi.hProcess, 0);
            cout << "Process terminated." << endl;
            //and if we want to terminate my notepad and proess in terminal type taskkill /IM notepad.exe /F

        // Close process and thread handles.
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        // Process creation failed
        cerr << "Process creation failed. Error: " << GetLastError() << endl;
    }

    return 0;
}
