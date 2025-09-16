#include <iostream>
#include <unistd.h>  
#include <sys/types.h> 
#include <sys/wait.h> 
#include <signal.h>   

using namespace std;

int main() {
    pid_t pid = fork(); 

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0) {
        
        cout << "Child Process (PID: " << getpid() << ") running Google Chrome..." << endl;
        execlp("google-chrome", "google-chrome", NULL); 
        perror("Loading Chrome failed");
    } else {
        
        cout << "Parent Process (PID: " << getpid() << ") created Child PID: " << pid << endl;
        
        sleep(15); 

        cout << "Terminating Child Process..." << endl;
        kill(pid, SIGTERM); 

        wait(NULL);
        cout << "Child Process terminated!" << endl;
    }

    return 0;
}
