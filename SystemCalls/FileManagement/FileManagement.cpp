#include <windows.h>
#include <iostream>
using namespace std;

HANDLE hFile;
DWORD bytesWritten,bytesRead;

void CreateFile(){
    hFile= CreateFile("testfile.txt",GENERIC_WRITE|GENERIC_READ,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
    cout<<"hFile: "<<hFile<<endl;
    if(hFile==INVALID_HANDLE_VALUE){
        cerr<<"Failed to create file. Error: "<<GetLastError()<<endl;
    }
    else{
    cout<<"File created successfully!"<<endl;
    }
}
void WriteToFile(){
    char writeBuffer[] = "Hello";
    if(!WriteFile(hFile, writeBuffer,sizeof(writeBuffer),&bytesWritten,NULL)){
        cerr<<"Failed to write to file. Error: "<<GetLastError()<<endl;
        CloseHandle(hFile);
    }
    else{
    cout<<"Data written to file successfully!"<<endl;
    }
}
void ReadFromFile(){
 SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
    char readBuffer[100]={0};
    if(!ReadFile(hFile, readBuffer, sizeof(readBuffer),&bytesRead,NULL)){
        cerr<<"Failed to read from file. Error: "<<GetLastError()<<endl;
        CloseHandle(hFile);
    }
    else{
        readBuffer[bytesRead]='\0';
        cout<<"Data read from file:"<<readBuffer<<endl;
    }
}
void DeleteFile(){

    CloseHandle(hFile);
    if(DeleteFile("testfile.txt")){
        cout<<"File deleted successfully!"<<endl;
    }
    else{
        cerr<<"Failed to delete file.Error:"<<GetLastError()<<endl;
    }
}
int main() {

    CreateFile();
    Sleep(1000);
    WriteToFile();
    Sleep(1000);
    ReadFromFile();
    Sleep(3000);
    DeleteFile();




    return 0;
}  