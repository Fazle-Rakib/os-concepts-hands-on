#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    DWORD processID; // Store Notepad's process ID

    cout << "Enter Notepad's Process ID: ";
    cin >> processID;

    // Open Notepad process
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);

    if(hProcess) {
        TerminateProcess(hProcess, 0); 
        CloseHandle(hProcess);
        cout << "Notepad closed." << endl;
    } else {
        cerr << "Failed to find Notepad process. Error: " << GetLastError() << endl;
    }

    return 0;
}
