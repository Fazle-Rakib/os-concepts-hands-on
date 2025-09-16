#include <windows.h>
#include <iostream>
using namespace std;

void CALLBACK TimerCallback(HWND hwnd, UINT message, UINT_PTR idEvent, DWORD time) {
    static int count = 0;
    cout << "Timer Event Triggered after: " << (++count) * 3 << " seconds\n";
}

int main() {
    DWORD processId = GetCurrentProcessId();
    cout<< "Current Process ID: " << processId << "\n";

    UINT_PTR timerId = SetTimer(NULL, 0, 3000, TimerCallback);
    if (timerId == 0) {
        cout << "Failed to set timer!\n";
        return 1;
    }

    cout << "Timer set for every 3 seconds. Press Ctrl+C to exit.\n";
    MSG msg;
    for (int i = 1; i <= 5; i++) {
        cout << "Sleeping for 3 seconds...\n";
        Sleep(3000);
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    KillTimer(NULL, timerId);
    cout << "Timer stopped. Exiting program.\n";

    return 0;
}
