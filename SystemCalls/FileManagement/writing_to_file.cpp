#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    LPCSTR fileName = "test.txt";

    // Open the existing file with write access
    HANDLE hFile = CreateFile(
        fileName,            // File name
        GENERIC_WRITE,       // Open for writing
        0,                   // Do not share
        NULL,                // Default security
        OPEN_EXISTING,       // Open only if file exists
        FILE_ATTRIBUTE_NORMAL, // Normal file
        NULL                 // No template file
    );

    if(hFile == INVALID_HANDLE_VALUE) {
        cerr << "Failed to open file. Error: " << GetLastError() << endl;
        return 1;
    }

    // Writing to file
    const char* data = "Hello, Windows File System!";
    DWORD bytesWritten;
    if(!WriteFile(hFile, data, strlen(data), &bytesWritten, NULL)) {
        cerr << "Failed to write to file. Error: " << GetLastError() << endl;
    } else {
        cout << "Data written to file successfully." << endl;
    }

    // Close the file handle
    CloseHandle(hFile);

    return 0;
}
