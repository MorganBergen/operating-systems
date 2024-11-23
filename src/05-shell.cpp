#include <cstdlib> // Include the C Standard Library for system() function
#include <iostream> // Include the C++ Standard Library for cout and endl
using namespace std;

int main()
{
    // Executing the system command "echo Hello, World!" and storing the return value
    int returnCode = system("echo Hello, World!");

    // Checking if the command was executed successfully
    if (returnCode == 0) {
        // Output message indicating successful command execution
        cout << "Command executed successfully." << endl;
    }
    else {
        // Output message indicating command execution failure or non-zero return value
        cout << "Command execution failed or returned non-zero: " << returnCode << endl;
    }

    return 0; // Return 0 to indicate successful execution
}
