#include <windows.h>
#include <stdio.h>
#include <string.h>
int main() {
    HANDLE hFile;
    DWORD dwBytesWritten, dwBytesRead;
    char writeData[] = "Hello, this is a test file!";
    char readData[50] = {0};
    const char *filePath = "C:\\Users\\Asus\\testfile.txt";

    hFile = CreateFile(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Failed to create file. Error: %lu\n", GetLastError());
        return 1;
    }
    printf("File created successfully at %s.\n", filePath);
    if (!WriteFile(hFile, writeData, strlen(writeData), &dwBytesWritten, NULL)) {
        printf("Failed to write to file. Error: %lu\n", GetLastError());
        CloseHandle(hFile);
        return 1;
    }
    printf("Data written to file successfully.\n");


    CloseHandle(hFile);


    hFile = CreateFile(filePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Failed to open file. Error: %lu\n", GetLastError());
        return 1;
    }
    printf("File opened successfully for reading.\n");


    if (!ReadFile(hFile, readData, sizeof(readData) - 1, &dwBytesRead, NULL)) {
        printf("Failed to read file. Error: %lu\n", GetLastError());
        CloseHandle(hFile);
        return 1;
    }
    readData[dwBytesRead] = '\0';
    printf("Data read from file: %s\n", readData);

    CloseHandle(hFile);

    // Deleting the file
    /*if (!DeleteFile(filePath)) {
        printf("Failed to delete file. Error: %lu\n", GetLastError());
        return 1;
    }
    printf("File deleted successfully.\n");*/

    return 0;
}
