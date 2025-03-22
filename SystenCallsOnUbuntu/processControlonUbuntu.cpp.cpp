#include <iostream>
#include <spawn.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

extern char **environ; 

int main() {
    pid_t pid;
    const char *program = "/usr/bin/google-chrome"; // Chrome 

    char *const args[] = {const_cast<char *>(program), NULL};

    // Process (Windows- CreateProcessW)
    if (posix_spawn(&pid, program, NULL, NULL, args, environ) == 0) {
        cout << "Chrome opened successfully. PID: " << pid << endl;
    } else {
        cerr << "Process creation failed!" << endl;
        return 1;
    }

    waitpid(pid, NULL, 0);
    cout << "Chrome terminated!" << endl;

    return 0;
}
