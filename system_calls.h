#ifndef WINDOWS_SYSTEM_CALLS_H
#define WINDOWS_SYSTEM_CALLS_H

#include <windows.h>
#include <iostream>
#include <aclapi.h>

using namespace std;

/* ==========================
 * FILE MANAGEMENT FUNCTIONS
 * ========================== */

// Create a file
HANDLE CreateFileCustom(LPCSTR filename) {
    return CreateFileA(filename, GENERIC_WRITE | GENERIC_READ, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
}

// Write to a file
BOOL WriteFileCustom(HANDLE file, LPCSTR data) {
    DWORD bytesWritten;
    return WriteFile(file, data, strlen(data), &bytesWritten, NULL);
}

// Read from a file
BOOL ReadFileCustom(HANDLE file, LPSTR buffer, DWORD bufferSize) {
    DWORD bytesRead;
    return ReadFile(file, buffer, bufferSize - 1, &bytesRead, NULL);
}

// Delete a file
BOOL DeleteFileCustom(LPCSTR filename) {
    return DeleteFileA(filename);
}

/* ==========================
 * PROCESS MANAGEMENT FUNCTIONS
 * ========================== */

// Create a new process
BOOL CreateProcessCustom(LPCSTR appName) {
    STARTUPINFOA si = { sizeof(STARTUPINFOA) };
    PROCESS_INFORMATION pi;

    return CreateProcessA(appName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
}

// Terminate a process
BOOL TerminateProcessCustom(HANDLE processHandle) {
    return TerminateProcess(processHandle, 0);
}

/* ==========================
 * MEMORY MANAGEMENT FUNCTIONS
 * ========================== */

// Allocate memory using VirtualAlloc
LPVOID AllocateMemoryCustom(SIZE_T size) {
    return VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
}

// Free allocated memory
BOOL FreeMemoryCustom(LPVOID address) {
    return VirtualFree(address, 0, MEM_RELEASE);
}

/* ==========================
 * THREAD MANAGEMENT FUNCTIONS
 * ========================== */

// Thread function prototype
DWORD WINAPI ThreadFunction(LPVOID lpParam);

// Create a thread
HANDLE CreateThreadCustom(LPTHREAD_START_ROUTINE threadFunction, LPVOID param) {
    return CreateThread(NULL, 0, threadFunction, param, 0, NULL);
}

// Synchronize thread execution
DWORD WaitForThreadCustom(HANDLE thread) {
    return WaitForSingleObject(thread, INFINITE);
}

/* ==========================
 * PROTECTION & SECURITY FUNCTIONS
 * ========================== */

// Set file permissions (Restrict access to 'Everyone')
BOOL SetFilePermissions(LPCSTR filename) {
    PSECURITY_DESCRIPTOR pSD = (PSECURITY_DESCRIPTOR)LocalAlloc(LPTR, SECURITY_DESCRIPTOR_MIN_LENGTH);
    if (!InitializeSecurityDescriptor(pSD, SECURITY_DESCRIPTOR_REVISION))
        return FALSE;

    PSID pEveryoneSID = NULL;
    PACL pACL = NULL;
    EXPLICIT_ACCESS ea;
    SID_IDENTIFIER_AUTHORITY SIDAuthWorld = SECURITY_WORLD_SID_AUTHORITY;

    if (!AllocateAndInitializeSid(&SIDAuthWorld, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &pEveryoneSID))
        return FALSE;

    ZeroMemory(&ea, sizeof(EXPLICIT_ACCESS));
    ea.grfAccessPermissions = GENERIC_READ | GENERIC_WRITE;
    ea.grfAccessMode = DENY_ACCESS;
    ea.grfInheritance = NO_INHERITANCE;
    ea.Trustee.TrusteeForm = TRUSTEE_IS_SID;
    ea.Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
    ea.Trustee.ptstrName = (LPSTR)pEveryoneSID;

    if (SetEntriesInAcl(1, &ea, NULL, &pACL) != ERROR_SUCCESS)
        return FALSE;

    if (!SetSecurityDescriptorDacl(pSD, TRUE, pACL, FALSE))
        return FALSE;

    return SetFileSecurityA(filename, DACL_SECURITY_INFORMATION, pSD);
}

#endif // WINDOWS_SYSTEM_CALLS_H
