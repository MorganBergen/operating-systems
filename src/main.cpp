/**
 * @file        main.cpp
 * @author      morgan bergen
 * @date        august 29 2024
 * @brief       operating systems assignment activity   
 * 
 * @details     write a program that executes five different shell commands
 *              `ls`                    list contents of current directory
 *              `echo `hello world`     print hello world
 *              `mkdir` test_directory  create a new directory named "test_directory"
 *              `cat` example.txt       display contents of a text file named "example.txt"
 *              `pwd`                   print the current working directory
 * 
 * @note        to compile program use  `$ g++ -Wall -o exec main.cpp`
 *              to run program use      `$ ./exec`
 */

#include <iostream>
#include <cstdlib>

/**
 * @brief       main function
 * @details     executes five different shell commands
 * @param       none
 * @return      0
 * @note        `system()` function is used to execute shell commands
 */
int main() {

    std::cout << "\nlist contents of current directory" << std::endl;
    system("ls");

    std::cout << "\nprint hello world" << std::endl;
    system("echo 'hello world'");

    std::cout << "\ncreate a new directory named 'test_directory'" << std::endl;
    system("mkdir test_directory");

    std::cout << "\ndisplay contents of a text file named 'example.txt'" << std::endl;
    
    /** 
    * @note     check if file exists, if not create it
    */
    if (system("cat example.txt") != 0) {
        std::cout << "File not found: Creating 'example.txt' now..." << std::endl;
        system("touch example.txt");
        system("printf \"Contents of file\" > example.txt");
        system("cat example.txt");
    } else {
    }

    std::cout << "\n\nprint the current working directory" << std::endl;
    system("pwd");
    
    return(0);
}

/**
 * @note        discuss the importance of using shell commands in programming and real life applications
 *              shell commands are a way to interact with the operating system, they are a fast and easy
 *              way to perform tasks instead of using a mouse and gui.
 *              shell commands are important for programming because they are essential to the development
 *              of software.  in order to utilize a library or framework, you must be able to execute
 *              the shell commands that are required to install and run the software.
 *             
 * @note        discuss the security risks of using shell commands in programming
 *              shell commands are a security risk because they are irrevocable, meaning that once a command
 *              is executed, it cannot be undone.
 *              additionally shell commands can be used to execute malicious code, so it is important to
 *              be cautious when using shell commands in programming.
 * 
 *              the `sudo` command is a good example of a shell command that can be used to execute    
 *              malicious code, because you are giving the command root access to your system and removing
 *              any security restrictions.
 *              `sudo` stands for superuser do and provided elevated privileges to the user.
 *              and you can access or modify system level files
 * 
 *              Unintended Changes: Running commands as root bypasses many of the built-in protections that
 *              prevent unintended or unauthorized changes to the system. For example, editing system 
 *              files or changing permissions can lead to unpredictable behavior or system vulnerabilities.
 */