#include <iostream> // Include iostream for output
#include <cstdlib>  // Include the C Standard Library for system() function

int main() {
    // Print a message before executing the command
    std::cout << "Printing the current working directory:" << std::endl;

    // Execute the command "cd" to print the working directory
    int result = system("cd");

    // Check if the command was executed successfully
    if (result != 0) {
        std::cerr << "Failed to print the working directory." << std::endl;
        return 1; // Return 1 to indicate an error
    }

    // Print a success message
    std::cout << "Working directory printed successfully." << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}
