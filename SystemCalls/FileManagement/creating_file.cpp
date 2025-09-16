#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    HANDLE hFile = CreateFileW(
        L"test.txt",                // File name
        GENERIC_WRITE,              // Write access
        0,                          // No sharing
        NULL,                       // Default security
        CREATE_ALWAYS,              // Always create a new file
        FILE_ATTRIBUTE_NORMAL,       // Normal file
        NULL                        // No template
    );

    if(hFile == INVALID_HANDLE_VALUE) {
        cerr << "Failed to create file. Error: " << GetLastError() << endl;
        return 1;
    }

    cout << "File created successfully!" << endl;

    CloseHandle(hFile);
    return 0;
}
