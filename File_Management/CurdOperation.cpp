#include<windows.h>
#include<iostream>
using namespace std;
 
#include <fstream>
#include <string>

void createFile(const string& fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        cout << "File created successfully: " << fileName << endl;
    } else {
        cout << "Unable to create file: " << fileName << endl;
    }
    file.close();
}

void updateFile(const string& fileName, const string& content) {
    ofstream file(fileName);
    if (file.is_open()) {
        file << content;
        cout << "File updated successfully: " << fileName << endl;
    } else {
        cout << "Unable to update file: " << fileName << endl;
    }
    file.close();
}

void deleteFile(const string& fileName) {
    if (remove(fileName.c_str()) == 0) {
        cout << "File deleted successfully: " << fileName << endl;
    } else {
        cout << "Unable to delete file: " << fileName << endl;
    }
}

void copyFile(const string& sourceFileName, const string& destinationFileName) {
    ifstream sourceFile(sourceFileName, ios::binary);
    ofstream destinationFile(destinationFileName, ios::binary);

    if (sourceFile.is_open() && destinationFile.is_open()) {
        destinationFile << sourceFile.rdbuf();
        cout << "File copied successfully: " << sourceFileName << " to " << destinationFileName << endl;
    } else {
        cout << "Unable to copy file: " << sourceFileName << endl;
    }

    sourceFile.close();
    destinationFile.close();
}

int main() {
    string command, fileName, content;

    while (true) {
        cout << "Enter command (create, update, delete, copy, exit): ";
        cin >> command;

        if (command == "exit") {
            break;
        }

        cout << "Enter file name: ";
        cin >> fileName;

        if (command == "create") {
            createFile(fileName);
        } else if (command == "update") {
            cout << "Enter content: ";
            cin.ignore();
            getline(cin, content);
            updateFile(fileName, content);
        } else if (command == "delete") {
            deleteFile(fileName);
        } else if (command == "copy") {
            string destinationFileName;
            cout << "Enter destination file name: ";
            cin >> destinationFileName;
            copyFile(fileName, destinationFileName);
        } else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}