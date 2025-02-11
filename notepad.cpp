#include <windows.h>
#include <iostream>

void CloseProcessGracefully() {
    Sleep(500);
    HWND hwnd = FindWindowW(NULL, L"*output.txt - Notepad");
    
    if (hwnd) {
        std::cout << "Found Notepad! Closing it gracefully...\n";
        PostMessage(hwnd, WM_CLOSE, 0, 0);
    } else {
        std::cerr << "Error: Could not find Notepad window! Using forceful termination...\n";
    }
}

int main() {
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;

    if (CreateProcess(TEXT("C:\\Windows\\System32\\notepad.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        Sleep(1000);
        std::cout << "Process started. Closing in 3 seconds...\n";
        // std::cin.get();
        Sleep(3000); 

        
         CloseProcessGracefully();


        Sleep(3000); 

        DWORD exitCode;
        GetExitCodeProcess(pi.hProcess, &exitCode);
        if (exitCode == STILL_ACTIVE) {
            std::cout << "Forcefully terminating process...\n";
            TerminateProcess(pi.hProcess, 0);
        } else {
            std::cout << "Process closed gracefully.\n";
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        std::cerr << "Failed to create process. Error: " << GetLastError() << std::endl;
    }

    return 0;
}
