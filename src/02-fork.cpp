#include <iostream>
#include <process.h>
#include <windows.h>

void childProcess('void') {
    std::cout << "child process" << std::endl;
    _endthread(); // end the child thread to free up resources
}

int main() {
    // create a child process (thread)
    uintptr_t child = _beginthread
}