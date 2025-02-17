#include <windows.h>
#include <iostream>
#include <aclapi.h>  // Required for security functions

using namespace std;

void SetFilePermissions(const char* filename) {
    // Convert filename to wide string for Windows API compatibility
    wstring wFilename = wstring(filename, filename + strlen(filename));

    // Define the security descriptor
    PSECURITY_DESCRIPTOR pSD = (PSECURITY_DESCRIPTOR)LocalAlloc(LPTR, SECURITY_DESCRIPTOR_MIN_LENGTH);
    if (!InitializeSecurityDescriptor(pSD, SECURITY_DESCRIPTOR_REVISION)) {
        cout << "Failed to initialize security descriptor. Error: " << GetLastError() << endl;
        return;
    }

    // Set the security descriptor to allow only the current user full control
    PSID pEveryoneSID = NULL;
    PACL pACL = NULL;
    EXPLICIT_ACCESS ea;
    SID_IDENTIFIER_AUTHORITY SIDAuthWorld = SECURITY_WORLD_SID_AUTHORITY;

    // Create a well-known SID for the Everyone group
    if (!AllocateAndInitializeSid(&SIDAuthWorld, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &pEveryoneSID)) {
        cout << "Failed to initialize SID. Error: " << GetLastError() << endl;
        return;
    }

    // Set up an access control entry (ACE) that denies access to Everyone
    ZeroMemory(&ea, sizeof(EXPLICIT_ACCESS));
    ea.grfAccessPermissions = GENERIC_READ | GENERIC_WRITE;
    ea.grfAccessMode = DENY_ACCESS;
    ea.grfInheritance = NO_INHERITANCE;
    ea.Trustee.TrusteeForm = TRUSTEE_IS_SID;
    ea.Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
    ea.Trustee.ptstrName = (LPSTR)pEveryoneSID;

    // Create a new ACL that contains the new ACE
    if (SetEntriesInAcl(1, &ea, NULL, &pACL) != ERROR_SUCCESS) {
        cout << "Failed to set entries in ACL. Error: " << GetLastError() << endl;
        return;
    }

    // Set the security descriptor DACL
    if (!SetSecurityDescriptorDacl(pSD, TRUE, pACL, FALSE)) {
        cout << "Failed to set security descriptor DACL. Error: " << GetLastError() << endl;
        return;
    }

    // Apply the security descriptor to the file (Use Unicode version)
    if (SetFileSecurityW(wFilename.c_str(), DACL_SECURITY_INFORMATION, pSD) == 0) {
        cout << "Failed to set file security. Error: " << GetLastError() << endl;
    } else {
        cout << "File security updated successfully for: " << filename << endl;
    }

    // Cleanup
    if (pEveryoneSID) FreeSid(pEveryoneSID);
    if (pACL) LocalFree(pACL);
    if (pSD) LocalFree(pSD);
}

int main() {
    const char* filename = "securefile.txt";

    // Create a file
    HANDLE file = CreateFileA(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        cout << "Failed to create file. Error: " << GetLastError() << endl;
        return 1;
    }
    CloseHandle(file);

    // Set file permissions
    SetFilePermissions(filename);

    return 0;
}
