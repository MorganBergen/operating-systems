#  assignment 1

**cs 540 operating systems**

**morgan bergen**

**due  august 13 2024**

----

to succeed in this assignment, prioritize conciseness - convey your ideas in a few words as possible.  embrace open-ended questions, where there's no single correct answer.  instead make reasonable assumptions and respond as a wireless designer or researcher would.  each question has a value of 1 pt.

####  1.  how does the distinction between kernel mode and user mode function as a rudimentary form of protection (security) system?

kernel mode is a privileged mode of operating where the operating system has unrestricted access to all hardware and system resources, as opposed to user mode where more resources are restricted.  in kernel mode, the operating system can execute any cpu instruction and reference any memory address while user mode applications have limited access to system resources and cannot directly interact with hardware or reference arbitrary memory addresses.  

the distinction between kernel mode and user mode acts as a protection mechanism 
in terms of separation, controlled access, and fault isolation.  separation allows for protection by separating user applications from critical system operations, controlled access ensures that user applications must be required to make system calls to access hardware or perform privileged operations, and fault isolation ensures that if a user application crashes or behaves maliciously, the damage is contained within the user mode, preventing it from affecting the overall system stability.

####  2.  what is the purpose of system calls?

the purpose of a system call is to request the operating system for 

####  3.  describe the actions taken by a kernel to context-switch between processes

####  4.  what are common commands and their respective functionalities in the unix/linux command shell, and how can they be used effectively to manage files and directories?  please list at least five of them 

####  5.  consider the following c code snippet that demonstrates the use of the fork system call, and answer the following questions

```c
#include <stdio.h>
#include <unistd.h>

int main() {

    pid_t pid = fork();

    if (pid == -1) {
        //  error handling
        perror("fork");
        return 1;
        
    } else if {
        // child process
        printf("child process:  my pid is %d\n", getpid());

    } else {
        //  parent process
        printf("parent process:  my pid is %d\n", getpid());
        printf("parent process:  child pid is %d\n", pid);
    }

    return 0;
}
```

a -  explain the purpose of the fork system call in this code.  how does it facilitate the creation of a new process?

b -  describe the behavior of the child process and the parent process after the fork call.  what information does each process print?

c -  what are the potential return values of the fork system call?  how does the code handle each possible scenario?

d -  discuss the concept of copy on write memory as it related to the memory management of the child process.  how does it optimize memory usage in this context?

e -  how are file descriptors handled between the parent and child processes?  are they shared or copied?  explain your answer.

f -  what potential issues or considerations should be taken into account when managing shared resources between parent and child processes in a multi-process environment?