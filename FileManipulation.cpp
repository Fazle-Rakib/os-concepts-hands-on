#include <windows.h>
#include <iostream>
using namespace std;
int main() {
    HANDLE hFile;
    string userData;
    DWORD bytesWritten;
    cout << "Enter text to write to file: ";
    getline(cin, userData);

    hFile = CreateFile("example2.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        cout << "Failed to create file\n";
        return 1;
    }
    WriteFile(hFile, userData.c_str(), userData.length(), &bytesWritten, NULL);

    CloseHandle(hFile);

    cout << "File written successfully\n";

    cout << "Check the folder now! Press any key to continue...\n";
    system("pause");
    if (DeleteFile("example2.txt")) {
        cout << "File deleted successfully\n";
    } else {
        cout<< "Failed to delete file\n";
    }

    return 0;
}
