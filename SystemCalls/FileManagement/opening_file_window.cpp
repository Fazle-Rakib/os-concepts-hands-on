#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    // Start Notepad and open the file
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;

    if(CreateProcess(
        "C:\\Windows\\System32\\notepad.exe", // Program to run (Notepad)
        " test.txt",             
        NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi
    )) {
        cout << "File opened in Notepad." << endl;
        cout << "Process ID: " << pi.dwProcessId << endl;
        
        // Store process handle for closing later
        CloseHandle(pi.hThread);
    } else {
        cerr << "Failed to open file. Error: " << GetLastError() << endl;
        return 1;
    }

    return 0; // Not closing process here; will be closed separately
}
