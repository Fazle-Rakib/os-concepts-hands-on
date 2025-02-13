#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
void get_system_info() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    std::cout << "Processor Architecture: " << sysInfo.wProcessorArchitecture << std::endl;
    std::cout << "Page size: " << sysInfo.dwPageSize << " bytes" << std::endl;
    std::cout << "Number of processors: " << sysInfo.dwNumberOfProcessors << std::endl;
}
void get_current_time() {
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    std::cout << "Current date and time: " << asctime(tm_info);
}
int main() {
    std::cout << "System Information:\n";
    get_system_info();

    std::cout << "\nCurrent Time:\n";
    get_current_time();

    return 0;
}
