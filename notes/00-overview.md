#  overview

####  concepts

1.  [introduction](#introduction)  
2.  [os structures](#os-structures)  
3.  [processes](#processes)  
4.  [threads](#threads)  
5.  [process synchronization](#process-synchronization)  
6.  [cpu scheduling](#cpu-scheduling)  

##  introduction

####  operating system

an os is a program that acts as an intermediary between the user of a computer and the computer hardware

goals of the os are to execute programs, make the computer system easy to use, and utilize hardware efficiently

hardware $\leftrightarrow$ os $\leftrightarrow$ applications $\leftrightarrow$ users

an os is a resource allocator and a control program

a resource allocator decides between conflicting requests for efficient and fair resource use

a control program controls execution of programs to prevent errors and improper use of the computer

####  kernel

the kernel is the one program running at all times on the computer

####  bootstrap program

loaded at power up or reboot

stored in rom or eprom known as **firmware**, initializes all aspects of the system and loads os kernel and starts execution

device controllers inform the cpu that it is finished with operating by causing an **interrupt**

interrupt transfers control the interrupt service routine generally, through the **interrupt vector**, which contains the addresses of all the service routines

incoming interrupts are disabled while another interrupt is being processes

**trap** is a software generated interrupt caused by error or user request

os determines which type of interrupt has occurred by **polling** or the **vector interrupt system**

####  system call

request to the operating system to allow user to wait for i/o completion

##  os structures

##  processes

##  threads

##  process synchronization

##  cpu scheduling

