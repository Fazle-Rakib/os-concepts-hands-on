//this will set the attribute to read-only. No other operations(deleting,writing,opening etc) will not be applicable after doing this!

#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    LPCSTR fileName = "test.txt";  // File path

    // Set the file attribute to read-only
    if (SetFileAttributes(fileName, FILE_ATTRIBUTE_READONLY)) {
        cout << "File is now set to read-only." << endl;
    } else {
        cerr << "Failed to set file as read-only. Error: " << GetLastError() << endl;
    }

    return 0;
}
