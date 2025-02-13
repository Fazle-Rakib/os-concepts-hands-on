#include <stdio.h>
#include <windows.h>
void setConsoleMode(HANDLE hConsole) {
    DWORD dwMode;
    if (GetConsoleMode(hConsole, &dwMode)) {
        if (!SetConsoleMode(hConsole, dwMode)) {
            printf("Error setting console mode.\n");
        }
    } else {
        printf("Error getting console mode.\n");
    }
}

void readConsole() {
    char input[256];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    printf("You entered: %s", input);
}


void writeConsole(const char* message) {
    printf("%s\n", message);
}

int main() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    setConsoleMode(hConsole);


    writeConsole("Hello, Device Management World!");


    readConsole();

    return 0;
}

