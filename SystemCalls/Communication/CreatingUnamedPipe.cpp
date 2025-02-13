/*
IPC -> Communicating between different process
Pipe ->  for communicating local process 
1.Unnmaed Pipe 
2.Named Pipe 

*Unnamed Pipe is used for Uniderectional Communication 
*Unnamed pipe is used for local machine or Computer  not for communication with another machine or computer 
*It can not used over the network 
*
*/

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int main(){
    BOOL bCreatePipe;
    HANDLE hRead;
    HANDLE hWrite;

    char szBuffer[512]="Hello OS";
    DWORD dwBufferSize= sizeof( szBuffer );
    BOOL bWritefile;
    BOOL bReadfile;
    DWORD dwNoByteWrite;
    DWORD dwNoByteRead;


    //create file 
    bCreatePipe= CreatePipe(
        &hRead, &hWrite,NULL,dwBufferSize
    );
    
    //error Handeling       bCreatepipe file return boolian
    if(bCreatePipe== FALSE){
        cout<<"Create pipe failed  & Error NO "<<GetLastError()<<endl;
    }else{
        cout<<"Create Pipe Succesfully"<<endl;
    }
    
    //Write file 
    bWritefile = WriteFile(
        hWrite,szBuffer ,dwBufferSize, &dwNoByteWrite,NULL
    );

    //error Handeling       bWrite file return boolian
    if(bWritefile== FALSE){
        cout<<"Write Failed failed  & Error NO "<<GetLastError()<<endl;
    }else{
        cout<<"Write  Successfully"<<endl;
    }


    //close Handle 
    CloseHandle(hWrite);


    //Read file
    bReadfile = ReadFile(
        hRead, szBuffer ,dwBufferSize , &dwNoByteWrite,NULL
    );

    //error Handeling       bRead file return boolian
    if(bReadfile== FALSE){
        cout<<"Rerad Failed failed  & Error NO "<<GetLastError()<<endl;
    }else{
        cout<<"Read  Succesfully"<<endl;
    }
    CloseHandle(hWrite);
}