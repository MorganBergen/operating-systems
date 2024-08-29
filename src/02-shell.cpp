#include <iostream> // Include iostream for output
#include <cstdlib>  // Include the C Standard Library for system() function

int main() {
    // Create a new directory named "new_folder"
    std::cout << "Creating a new directory named 'new_folder'..." << std::endl;
    int mkdirResult = system("mkdir new_folder");

    // Check if directory creation was successful
    if (mkdirResult != 0) {
        std::cerr << "Failed to create 'new_folder'. It may already exist or there was a permissions issue." << std::endl;
        return 1;
    } else {
        std::cout << "'new_folder' created successfully." << std::endl;
    }

    // Remove an existing directory named "old_folder" and its contents recursively
    std::cout << "Attempting to remove 'old_folder' and its contents..." << std::endl;
    int delResult = system("rmdir /s /q old_folder");

    // Check if directory deletion was successful
    if (delResult != 0) {
        std::cerr << "Failed to remove 'old_folder'. It may not exist or there was a permissions issue." << std::endl;
        return 1;
    } else {
        std::cout << "'old_folder' removed successfully." << std::endl;
    }

    // Return 0 to indicate successful execution
    std::cout << "Operation completed successfully." << std::endl;
    return 0;
}
