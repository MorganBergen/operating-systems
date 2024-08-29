//  Note: Code in C++

#include <windows.h>  // Include Windows API header
#include <iostream>   // Include iostream for C++ output

using namespace std;

int main() {
    // Declare variables for the process information and startup info
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Initialize the STARTUPINFO structure
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Attempt to create a child process
    if (!CreateProcess(
            NULL,           // No module name (use command line)
            (LPSTR)"cmd.exe /c echo Hello from child process", // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            FALSE,          // Set handle inheritance to FALSE
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi))           // Pointer to PROCESS_INFORMATION structure
    {
        cerr << "CreateProcess failed (" << GetLastError() << ")." << endl;
        return 1;
    }

    // Parent process continues here
    cout << "Parent process executing..." << endl;
    cout << "Parent PID: " << GetCurrentProcessId() << endl;
    cout << "Child PID: " << pi.dwProcessId << endl;

    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
