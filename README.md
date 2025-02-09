# Windows.h Header File & System Calls  

## Introduction  
The `windows.h` header file is the primary Windows API header that provides access to core system functionalities in Windows operating systems. It includes declarations for various system services such as process management, file handling, memory management, threading, and synchronization.  

This file allows developers to interact directly with the Windows OS by making system calls to perform low-level operations.  

---

## Key System Calls in `windows.h`  

### 1. Process & Thread Management  
Windows provides APIs for creating and managing processes and threads.  
- `CreateProcess()` – Creates a new process and its primary thread.  
- `ExitProcess()` – Terminates the calling process and all its threads.  
- `TerminateProcess()` – Forces termination of a specified process.  
- `CreateThread()` – Creates a new thread within a process.  
- `ExitThread()` – Terminates the calling thread.  

---

### 2. File & Directory Operations  
Windows allows file handling operations through system calls:  
- `CreateFile()` – Opens or creates a file or device.  
- `ReadFile()` – Reads data from an open file.  
- `WriteFile()` – Writes data to a file.  
- `CloseHandle()` – Closes an open file or handle.  
- `DeleteFile()` – Deletes an existing file.  

---

### 3. Memory Management  
Memory allocation and deallocation functions help manage resources efficiently.  
- `VirtualAlloc()` – Reserves or commits memory pages.  
- `VirtualFree()` – Releases or decommits allocated memory.  
- `GlobalAlloc()` – Allocates memory from the global heap.  
- `HeapCreate()` – Creates a private heap object.  
- `HeapAlloc()` – Allocates memory from a heap.  

---

### 4. Synchronization & Interprocess Communication (IPC)  
To manage concurrency, Windows provides synchronization mechanisms.  
- `CreateMutex()` – Creates a mutex object for exclusive access control.  
- `WaitForSingleObject()` – Waits for an object to be signaled.  
- `ReleaseMutex()` – Releases ownership of a mutex.  
- `CreateEvent()` – Creates an event object for signaling.  

---

### 5. Console & Input/Output Handling  
For console applications, Windows provides system calls for input and output operations.  
- `GetStdHandle()` – Retrieves a handle to standard input, output, or error.  
- `ReadConsole()` – Reads input from the console.  
- `WriteConsole()` – Writes output to the console.  

---

### 6. System Information & Control  
These functions retrieve system details and control execution flow.  
- `GetSystemTime()` – Retrieves the current system time.  
- `GetTickCount()` – Returns the number of milliseconds since the system started.  
- `Sleep()` – Pauses execution for a specified time duration.  

---

This header file is essential for low-level Windows development and allows direct interaction with the OS for efficient resource management.  

## License  
This repository is open-source and available under the MIT License.  

---

Happy coding! 🚀
