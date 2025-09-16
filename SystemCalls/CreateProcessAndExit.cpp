#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    //STARTUPINFO  holds information about how a process's main window should be displayed 
    STARTUPINFO si = {0};

    //PROCESS_INFORMATION  stores information about new created process
    PROCESS_INFORMATION pi = {0};

    si.cb = sizeof(si);
    
    // create an process for this  passing the file full location 
    CreateProcess(
        "C:\\Windows\\System32\\notepad.exe", 
        NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    
    cout<<"Create a new process , Process ID :"<<pi.dwProcessId<<"\n";

    // this is the windows API  that pauses the execution of the current thread
    Sleep(2000);
    
    //finds a window by its class name or window title
    HWND hWnd = FindWindow("Notepad", NULL);

    //sends a message to  window for closing this process
    PostMessage(hWnd, WM_CLOSE, 0, 0);  
    WaitForSingleObject(pi.hProcess, 500);
    
    cout<<"Exit  The  process , Process ID :"<<pi.dwProcessId<<"\n";

    return 0;
}
