#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    if(DeleteFileW(L"test.txt")) {
        cout << "File deleted successfully!" << endl;
    } else {
        cerr << "Failed to delete file. Error: " << GetLastError() << endl;
    }
    return 0;
}
