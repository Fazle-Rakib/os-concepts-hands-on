#include <windows.h>
#include <iostream>

using namespace std;

int main() {

    LPCSTR fileName = "test.txt";

    // Get file attributes
    DWORD attributes = GetFileAttributes(fileName);

    if(attributes == INVALID_FILE_ATTRIBUTES) {
        cerr << "Failed to get file attributes. Error: " << GetLastError() << endl;
        return 1;
    }

    cout << "File Attributes for " << fileName << ":\n";

    if(attributes & FILE_ATTRIBUTE_READONLY) cout << "- Read-only\n";
    if(attributes & FILE_ATTRIBUTE_HIDDEN) cout << "- Hidden\n";
    if(attributes & FILE_ATTRIBUTE_SYSTEM) cout << "- System file\n";
    if(attributes & FILE_ATTRIBUTE_DIRECTORY) cout << "- Directory\n";
    if(attributes & FILE_ATTRIBUTE_ARCHIVE) cout << "- Archive\n";
    if(attributes & FILE_ATTRIBUTE_NORMAL) cout << "- Normal file\n";
    if(attributes & FILE_ATTRIBUTE_TEMPORARY) cout << "- Temporary file\n";

    return 0;
}
