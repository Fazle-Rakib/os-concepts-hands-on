#include <windows.h>
#include <iostream>

using namespace std;

void ConsoleMode(HANDLE hInput) {
    DWORD mode;
    if (GetConsoleMode(hInput, &mode)) {
        cout << "Current console mode: " << mode << endl;
    } else {
        cerr << "Failed to get console mode. Error: " << GetLastError() << endl;
    }

    if (SetConsoleMode(hInput, ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT)) {
        cout << "Console mode updated successfully." << endl;
    } else {
        cerr << "Failed to set console mode. Error: " << GetLastError() << endl;
    }
}

void WandRConsole(HANDLE x, HANDLE y) {
    char inputBuffer[125];
    DWORD bytesRead;
    cout << "Enter some text: ";
    ReadConsole(x, inputBuffer, sizeof(inputBuffer), &bytesRead, NULL);
    inputBuffer[bytesRead - 2] = '\0';
    cout << "You entered: " << inputBuffer << endl;

    const char* outputText = "Hello from Write Console!\n";
    DWORD bytesWritten;
    WriteConsole(y, outputText, strlen(outputText), &bytesWritten, NULL);
}

void handleConsoleInputBuffer(HANDLE x) {
    INPUT_RECORD inputRecord;
    DWORD eventsRead;
    ReadConsoleInput(x, &inputRecord, 1, &eventsRead);
    cout << "Read an input event from the console buffer." << endl;

    FlushConsoleInputBuffer(x);
    cout << "Console input buffer flushed." << endl;
}

void setCursorAndCheckEvents(HANDLE x, HANDLE y) {//check korte parbo j cursor er position change hoyeche or not!
    COORD newPos = {10, 5};
    SetConsoleCursorPosition(x, newPos);
    cout << "Cursor moved to position (10,5)." << endl;

    DWORD eventCount;
    if (GetNumberOfConsoleInputEvents(y, &eventCount)) {
        cout << "Number of unread console input events: " << eventCount << endl;
    } else {
        cerr << "Failed to get console input event count. Error: " << GetLastError() << endl;
    }
}

int main() {
    HANDLE input1 = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE output1 = GetStdHandle(STD_OUTPUT_HANDLE);
    
    ConsoleMode(input1);
    WandRConsole(input1, output1);
    handleConsoleInputBuffer(input1);
    setCursorAndCheckEvents(output1, input1);

    return 0;
}
