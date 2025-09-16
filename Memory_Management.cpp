#include <windows.h>
#include <iostream>
#include <cstring> // Required for memory functions

int main() {
    // Define the size of the memory block to allocate
    SIZE_T size = 1024; // 1 KB

    // Allocate memory
    LPVOID pMemory = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (pMemory == NULL) {
        std::cerr << "Memory allocation failed with error: " << GetLastError() << std::endl;
        return 1;
    }
    std::cout << "Memory allocated at: " << pMemory << std::endl;

    // Use the allocated memory
    char* pChar = static_cast<char*>(pMemory);
    memcpy(pChar, "Hello, VirtualAlloc!", strlen("Hello, VirtualAlloc!") + 1); // Safe alternative
    std::cout << "Stored message: " << pChar << std::endl;

    // Free allocated memory
    if (VirtualFree(pMemory, 0, MEM_RELEASE)) {
        std::cout << "Memory successfully freed." << std::endl;
    } else {
        std::cerr << "Memory release failed with error: " << GetLastError() << std::endl;
    }

    return 0;
}
