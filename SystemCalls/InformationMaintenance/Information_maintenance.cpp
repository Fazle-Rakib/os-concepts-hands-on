#include <windows.h>
#include <iostream>
using namespace std;

void TimeAndDate(){
    SYSTEMTIME st;
    GetSystemTime(&st);
    cout<<"Today's date: "<<st.wDay<<"-"<<st.wMonth<<"-"<<st.wYear<<endl;
    cout<<"Current time: "<<st.wHour<<":"<<st.wMinute<<":"<<st.wSecond<<endl;
}
void OsVersion(){
    OSVERSIONINFO osversion;
    ZeroMemory(&osversion, sizeof(OSVERSIONINFO));
    osversion.dwOSVersionInfoSize= sizeof(OSVERSIONINFO);
    auto i=GetVersionEx(&osversion);
    if(i){
        cout<<"OS version: "<<osversion.dwMajorVersion<<"."<<osversion.dwMinorVersion<<endl;
        cout<<"Build number: "<<osversion.dwBuildNumber<<endl;
    }
    else{
        cerr<<"Failed to get OS version.Error: "<<GetLastError()<<endl;
    }
}

int main() {
    
    cout<<"----- System Information -----"<<endl;

    TimeAndDate();
    Sleep(1000);
    OsVersion();

    
    return 0;
}
