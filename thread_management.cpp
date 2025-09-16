#include <windows.h>
#include <iostream>

using namespace std;

// Thread function
DWORD WINAPI ThreadFunction(LPVOID lpParam) {
    int threadID = *static_cast<int*>(lpParam);
    cout << "Thread " << threadID << " is running." << endl;
    Sleep(2000);  // Simulate work by sleeping for 2 seconds
    cout << "Thread " << threadID << " has finished." << endl;
    return 0;
}

int main() {
    const int numThreads = 2;
    HANDLE threads[numThreads];
    int threadIDs[numThreads] = {1, 2};

    // Create multiple threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = CreateThread(
            NULL,                   // Default security attributes
            0,                      // Default stack size
            ThreadFunction,         // Thread function
            &threadIDs[i],          // Parameter to pass
            0,                      // Default creation flags
            NULL                    // Thread identifier (not used)
        );

        if (threads[i] == NULL) {
            cout << "Failed to create thread " << i + 1 << endl;
            return 1;
        }
        cout << "Thread " << threadIDs[i] << " created successfully." << endl;
    }

    // Synchronizing Threads (Wait for them to complete)
    WaitForMultipleObjects(numThreads, threads, TRUE, INFINITE);

    // Close thread handles
    for (int i = 0; i < numThreads; ++i) {
        CloseHandle(threads[i]);
    }

    cout << "All threads have finished execution." << endl;
    return 0;
}
