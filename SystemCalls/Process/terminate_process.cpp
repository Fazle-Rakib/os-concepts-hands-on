#include<windows.h>
#include<iostream>
using namespace std;

int main(){
    HANDLE hProcess;
    HANDLE hThread;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD dwProcessId = 0;
    DWORD dwThreadId = 0;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    BOOL bCreateProcess = NULL;

    bCreateProcess = CreateProcess(
        "C:\\Windows\\System32\\notepad.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

    if(bCreateProcess == 0){
        cout<<"Process Creation Failed & Error No: "<<GetLastError()<<endl;
    }
    else{
        cout<<"Process Creation Success"<<endl;
        cout<<"Process ID: "<<pi.dwProcessId<<endl;
        cout<<"Thread ID: "<<pi.dwThreadId<<endl;
    }
    

    cout << "Press any key to close the process" << endl;
    cin.get();
    TerminateProcess(pi.hProcess, 0);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}