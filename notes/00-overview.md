#  overview

####  concepts

1.  [introduction](#introduction)  
2.  [os structures](#os-structures)  
3.  [processes](#processes)  
4.  [threads](#threads)  
5.  [process synchronization](#process-synchronization)  
6.  [cpu scheduling](#cpu-scheduling)  

##  introduction

###  operating system

an os is a program that acts as an intermediary between the user of a computer and the computer hardware

goals of the os are to execute programs, make the computer system easy to use, and utilize hardware efficiently

hardware $\leftrightarrow$ os $\leftrightarrow$ applications $\leftrightarrow$ users

an os is a resource allocator and a control program

a resource allocator decides between conflicting requests for efficient and fair resource use

a control program controls execution of programs to prevent errors and improper use of the computer

###  kernel

the kernel is the one program running at all times on the computer

###  bootstrap program

loaded at power up or reboot, stored in rom or eprom known as **firmware**, initializes all aspects of the system and loads os kernel and starts execution

i/o and cpu can execute concurrently

device controllers inform the cpu that it is finished with operating by causing an **interrupt**

interrupt transfers control the interrupt service routine generally, through the **interrupt vector**, which contains 

the addresses of all the service routines

incoming interrupts are disabled while another interrupt is being processes

**trap** is a software generated interrupt caused by error or user request

os determines which type of interrupt has occurred by **polling** or the **vector interrupt system**

###  system call

request to the operating system to allow user to wait for i/o completion

###  device status table

contains entry for each i/o device indicating its type, address, and state

os indexes into the i/o device table to determine device status and to modify the table entry to include interrupt

###  storage structure

main memory -  **random access**, **volatile**

secondary memory -  extension of main memory that provides large **non-volatile** storage

disk -  divided into **tracks** which are subdivided into **sectors**, the **disk controller** determines logical interaction between the device of the computer

###  caching

copying information into faster a storage system

###  multiprocessor systems

increased throughput, economy of scale, increased reliability
can be asymmetric or symmetric
**clustered systems** -  linked multiprocessor systems

###  multiprogramming

provides efficiency via **job scheduling**

when the os has to wait (ex. for i/o), switches to another job

###  timesharing

cpu switches jobs so frequently that each user can interact with each job while its running **interactive computing**

###  dual mode

dual mode operation allows os to protect itself and other system components -  **user mode** and **kernel mode**

some instructions are only executable in kernel mode, these are **privileged**

single threaded processes have one **program counter**, multi threaded processes have one pc per thread

###  protection

mechanism for controlling access of processes or users to resources defined by the operating system

###  security

defense of a system against attacks

###  user ids

one per user and **group id**, determine which users and groups of users have which privileges

##  os structures

###  user interface

a user interface can be command line or graphic user interface or batch

these allow for the user to interact with the system services via system calls typically written in c/c++

other system services that are helpful to the user include -  program execution, i/o operations, file system manipulation, communications, and error detection

services that exist to ensure efficient os operation are -  resource allocation, accounting, protection, and security

most system calls are accessed by **application program interface** api such as win32, poxix, java

usually there is a number associated with each system call

system call interface maintains a table indexed according to these numbers

parameters may need to be passed to the os during a system call, may be done by, passing in registers, address of parameter stored in a **block**, **pushed** onto the stack by the programming and **popped** off by the operating system or block and stack methods do not limit the number or length of parameters being passed.

###  process control system calls

`end`, `abort`, `load`, `execute`, `create process` / `terminate process`, `wait`, `allocate memory` / `free memory`

###  file management system calls

`create file`, `delete file`, `open file`, `close file`, `read`, `write`, `allocate memory`, `free memory`

###  device management system calls

`request device`, `release device`, `read`, `write`, `logically attach devices` / `logically detach devices`

###  information maintenance  system calls

`get time`, `set time`, `get system data`, `set system data`, `get process attributes`, `get file attributes`, `get device attributes`, `set process attributes`, `set file attributes`, `set device attributes`

###  communication system calls

`create communication connection`, `delete communication connection`, `send`, `transfer status information`

###  os layered approach

the operating system is divided into a number of layers or levels, each built on top of lower levels.  the bottom layer is layer 0 is the hardware and the highest layer n is the user interface

with modularity, layers are selected such that each uses functions or operations and services of only lower level layers

###  virtual machine

uses the layered approach, treats hardware and the os kernel as through they were all hardware

**host** creates the illusion that a process has its own processor and own virtual memory

each **guest** provided with a virtual copy of the underlying computer 

application failures can generate **core dump** file capturing memory of the process

operating system failure can generate **crash dump** file containing kernel memory

##  processes

###  process

a process contains a program counter, stack and data section

**text section** program code itself

**stack** is temporary data such as function parameters, return addresses, and local variables

**heap** contains memory dynamically allocated during run time

###  process control block 

a process control block contains information associated with each process, process state, pc, cpu registers, scheduling information, accounting information, and i/o status information

###  types of processes

**i/o bound processes** -  spends more time doing i/o than computations, many short cpu bursts

**cpu bound processes** -  spends more time doing computations, few very long cpu bursts

##  threads

##  process synchronization

##  cpu scheduling

