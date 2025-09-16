#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    HANDLE hFile = CreateFileW(
        L"test.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if(hFile == INVALID_HANDLE_VALUE) {
        cerr << "Failed to open file. Error: " << GetLastError() << endl;
        return 1;
    }

    char buffer[100] = {0};
    DWORD bytesRead;
    if(ReadFile(hFile, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
        cout << "File content: " << buffer << endl;
    } else {
        cerr << "Failed to read file. Error: " << GetLastError() << endl;
    }

    CloseHandle(hFile);
    return 0;
}
