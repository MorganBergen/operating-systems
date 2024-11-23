#include <iostream> // Include iostream for output
#include <cstdlib>  // Include the C Standard Library for system() function

int main() {
    std::cout << "Listing files in the current directory:" << std::endl;
    system("dir");  // Execute the command "dir" to list files in current directory
    return 0; // Return 0 to indicate successful execution
}
