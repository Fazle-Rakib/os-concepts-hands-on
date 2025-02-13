#include <windows.h>
#include <iostream>

void CreateAndTerminateProcess()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (CreateProcess(
        NULL,
        (LPSTR)"notepad.exe",
        NULL,
        NULL,
        FALSE,
        CREATE_NEW_CONSOLE,
        NULL,
        NULL,
        &si,
        &pi
    ))
    {
        std::cout << "Process created successfully!" << std::endl;

        std::cout << "Process ID: " << pi.dwProcessId << std::endl;
        std::cout << "Thread ID: " << pi.dwThreadId << std::endl;

        std::cout << "Sleeping for 5 seconds before terminating the process..." << std::endl;
        Sleep(5000);
        std::cout << "Terminating the process..." << std::endl;
        TerminateProcess(pi.hProcess, 0);


        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        std::cout << "Process terminated." << std::endl;
    }
    else
    {
        std::cerr << "Error creating process: " << GetLastError() << std::endl;
    }
}

int main()
{
    CreateAndTerminateProcess();
    return 0;
}
