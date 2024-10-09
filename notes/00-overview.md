#  overview

###  table of contents

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

when cpu switches to another process, the system must save the state of the old process to pcb and load the saved state from pcb for the new process via a **context switch**

time of a context switch is dependent on hardware

parent processes create child processes and form a tree

**pid** allows for process management

parents and children can share all / some/ none resources

parents can execute concurrently with children or wait until children terminate 

**`fork()`** system call create a new process

**`exec()`**  system call used after a fork to replace the processes' memory space with a new program

###  interprocess communication ipc

cooperating processes need interprocess communication -  shared memory or message passing

**message passing** may be blocking or non-blocking

**blocking** is considered **synchronous**

**blocking send** has the sender block until the message is received

**blocking receive** has the receiver block until the message is available

**non-blocking** is considered **asynchronous**

**non-blocking send** has the sender send the message and continue

**non-blocking receive** has the receiver receive a valid message or null

##  threads

###  threads

threads are a fundamental unit of cpu utilization that forms the basis of multi threaded computer systems

process creation is heavy weight while thread creation is light weight

can simplify code and increase efficiency

kernels are generally multi-threaded

###  multi-threading

multi-threading models include many to one, one to one, many to many

**many to one** -  many user level threads mapped to single kernel thread

**one to one** -  each user level thread maps to kernel thread

**many to many** -  many user level threads mapped to many kernel threads

###  thread library

a thread library provides the programmer with apis for creating and managing threads

issues include -  thread cancellation, signal handling (synchronous / asynchronous), handling thread specific data, and scheduler activations

**cancellation**

asynchronous cancellation terminates the target thread immediately

deferred cancellation allow the target thread to periodically check if it should be canceled

**signal handler**

a signal handler processes signals generated by a particular event, delivered to a process, handled

**scheduler**

scheduler activation provides **upcalls** -  a communication mechanism from the kernel to the thread library

allows application to maintain the correct number of kernel threads

##  process synchronization

###  race condition

a race conditional has several processes access and manipulate the same data concurrently, outcome depends on which order each access takes place

###  critical section

each process has a critical section of code, where it is manipulating data

to solve critical section **problem** each process must ask permission to enter critical sections in **entry section**, follow critical section with **exit section** and then execute the **remainder section**

especially difficult to solve this problem in preemptive kernels

###  peterson's solution

a solution for two processes

two processes share two variables, `int turn`, and `Boolean flag[2]`

**`turn`** -  whose turn it is to enter the critical section

**`flag`** -  indication of whether or not a process is ready to enter critical section

**`flag[i] = true`** -  indicates that process $P_{i}$ is ready

###  algorithm for process $P_{i}$

```cpp
do {

    flag[i] = true;
    turn = j;

    while (flag[j] && turn === j) {
        critical section
    }

    flag[i] = false;
    remainder section

} while (true);
```

modern machine provide atomic hardware instructions -  **atomic** = non-interruptable

solutions using **locks**

```cpp
do {

    acquire lock
        critical section

    release lock
        remainder section

} while (true);
```

###  test and set

solution using the test and set instruction -  shared boolean variable lock, initialized to false

```cpp
boolean TestAndSet(boolean *target) {
    
    boolean rv = *target;

    *target = true;

    return rv;
}

int main() {
    do {
        while ( TestAndSet(&lock) ) {
            //  do nothing
        }
        //  critical section
        lock = false;
        //  remainder section
    } while (true);
}
```

###  swap

```cpp
void Swap(boolean *a, boolean *b) {
    boolean temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    do {
        key = true;
        while (key = true) {
            Swap(&lock, &key);
        }
        //  critical section
        lock = false;
        //  remainder section
    } while(true);

    return(0);
}
```

###  semaphore

synchronization tool that does not require busy waiting

standard operations are `wait()` and `signal()` these are the only operations that can access semaphore $S$

can have **counting** unrestricted range and **binary** semaphores

###  deadlock

two or more processes are waiting indefinitely for an event that can be caused by only one of the waiting processes

most operating systems do not prevent or deal with deadlocks

can cause **starvation** and **priority inversion** lower priority process holds lock needed by higher priority process 

other synchronization problems include **bounded buffer problem** and **readers writers problem**

###  monitor

monitor is a high level abstraction that provides a convenient and effective mechanism for process synchronization

only one process may be active within the monitor at a time

can utilize **condition** variables to suspend a resume process (ex. condition `x`, `y;`)

`x.wait()` -  a process that invokes the operation is suspended until `x.signal()`

`x.signal()` -  resumes one of processes if any that invoked `x.wait()`

can be implemented with semaphores

##  cpu scheduling

###  cpu scheduling

process execution consists of a cycle of cpu execution and i/o wait

cpu scheduling decisions take place when a process...

switches from running to waiting (nonpreemptive)

switches from running to ready (preemptive)

switches from waiting to ready (preemptive)

terminates (nonpreemptive)

###  dispatcher

the dispatcher module gives control of the cpu to the process selected by the short term scheduler

**dispatch latency** is the time it takes for the dispatcher to stop one process and start another

###  scheduling algorithms

scheduling algorithms are chosen based on optimization criteria (ex. throughput, turnaround time, etc)

fcfs -  first come first served

sjf -  shortest job first

preemptive sjf -  shortest remaining time first 

round robin 

priority scheduling

###  exponential averaging

determining length of the next cpu burst is known as exponential averaging

1.  $t_{n} =$ actual length of nth cpu burst
2.  $\tau_{n + 1} =$ predicted value for the next cpu burst
3.  $\alpha, 0 \leq \alpha \leq 1$ commonly $\alpha$ set to $1/2$
4.  define $\tau_{n + 1} = \alpha * t_{n} + (1 - \alpha) * \tau_{n}$

###  priority scheduling

priority scheduling can result in **starvation**, which can be solved by **aging** a process (as time progresses, increase the priority)

###  round robin

in round robin small time quantums can result in large amounts of context switches

time quantum should be chosen so that 80% of processes have short burst times than the time quantum

###  multilevel queues / multilevel feedback queues

multilevel queues and multilevel feedback queues have multiple process queues that have different priority levels 

in the feedback queue, priority is not fixed $\rightarrow$ processes can be promoted and demoted to different queues

feedback queues can have different scheduling algorithms at different levels

###  multiprocessor scheduling

multiprocessor scheduling is done in several different ways

**asymmetric multiprocessing** -  only one processor accesses system data structures $\rightarrow$ no need to data share

**symmetric multiprocessing** -  each processor is self scheduling (currently the most common method)

**processor affinity** -  a process running on one processor is more likely to continue to run on the same processor, so that the processor's memory still contains data specific to that specific process

###  little's formula

little's formula can help determine average wait time per process in any scheduling algorithm

$n = \lambda \times W$

$n =$  average queue length

$W =$ average waiting time in queue

$\lambda =$ average arrival rate into queue

###  simulations 

simulations are programmed models of a computer system with variable clocks

used to gather statistics indicating algorithm performance

running simulations is more accurate than queuing models like little's law

although more accurate, high cost and high risk