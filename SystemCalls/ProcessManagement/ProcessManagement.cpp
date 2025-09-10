#include <windows.h>
#include <iostream>
using namespace std;

STARTUPINFO si={0};
PROCESS_INFORMATION pi={0};
LPCSTR applicationName="C:\\Windows\\System32\\notepad.exe";

void CreateProcess(){
     
    si.cb = sizeof(si);
    if(!CreateProcess(applicationName,NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)){
        cerr<<"Failed to create process. Error Code:"<<GetLastError()<<endl;
        return ;
    }
    cout<<"Notepad started successfully."<<endl;
    cout<<"Process ID: "<<pi.dwProcessId<<endl;
}
void TerminateProcess(){

    HWND hwnd=FindWindowW(L"Notepad",NULL);
    if(hwnd){
        cout<<"Notepad window found. Sending WM_CLOSE..."<<endl;
        if(PostMessageW(hwnd, WM_CLOSE, 0, 0)) {
            cout<<"WM_CLOSE message sent successfully."<<endl;
        }
        else{
            cerr<<"Failed to send WM_CLOSE message."<<endl;
        }
    } 
    else{
        cerr<<"Notepad window not found."<<endl;
    }
}
void CleanUp(){
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
int main() {

    CreateProcess();
    Sleep(3000);
    TerminateProcess();
    CleanUp();


    return 0;
}
     
