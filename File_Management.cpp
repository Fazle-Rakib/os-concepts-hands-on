#include <windows.h>
#include <iostream>

using namespace std;

void createFile(const char* filename) {
    HANDLE file = CreateFile(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        cout << "Failed to create file: " << filename << endl;
    } else {
        cout << "File created successfully: " << filename << endl;
        CloseHandle(file);
    }
}

void writeFile(const char* filename, const char* data) {
    HANDLE file = CreateFile(filename, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        cout << "Failed to open file for writing: " << filename << endl;
        return;
    }

    DWORD bytesWritten;
    BOOL success = WriteFile(file, data, strlen(data), &bytesWritten, NULL);
    if (success) {
        cout << "Data written to file: " << filename << endl;
    } else {
        cout << "Failed to write to file: " << filename << endl;
    }
    
    CloseHandle(file);
}

void readFile(const char* filename) {
    HANDLE file = CreateFile(filename, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        cout << "Failed to open file for reading: " << filename << endl;
        return;
    }

    char buffer[256] = {0};
    DWORD bytesRead;
    BOOL success = ReadFile(file, buffer, sizeof(buffer) - 1, &bytesRead, NULL);
    if (success) {
        cout << "File contents: " << buffer << endl;
    } else {
        cout << "Failed to read file: " << filename << endl;
    }

    CloseHandle(file);
}

void deleteFile(const char* filename) {
    if (DeleteFile(filename)) {
        cout << "File deleted successfully: " << filename << endl;
    } else {
        cout << "Failed to delete file: " << filename << endl;
    }
}

int main() {
    const char* filename = "testfile.txt";
    const char* data = "Hello, this is a test file.";

    createFile(filename);
    writeFile(filename, data);
    readFile(filename);
    deleteFile(filename);

    return 0;
}
