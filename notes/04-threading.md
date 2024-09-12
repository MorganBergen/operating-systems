#  understanding threading

##  introduction to threading

**definition** -  a thread refers to a single sequential flow of activities being executed in a process

**shares** -  information like data segment, code segment files, etc. with its peer threads

**contains** its registers, program counter, stack

**significance**

##  types of threads

user level threads

kernel level threads

##  user level threads

user level threads are implemented by users

the kernel is unaware of the existence of user level threads

the kernel treats user level threads as single threaded processes

user level threads are small and much faster than kernel level threads

represented by program counter pc, stack, registers, and small process control block pcb

no kernel involvement in synchronization for user level threads

##  kernel level threads

kernel level threads are handled by the operating system directly

thread management is done by the kernel

the kernel manages context information for both the process and its threads

kernel level threads are larger and slower than user level threads

##  advantages and disadvantages of user level threads and kernel level threads

| aspect | user level threads | kernel level threads |
|:-------|:------------------|:--------------------|
| advantages | faster | only blocks the calling thread |
|advantage | more resource efficient | kernel manages scheduling and resources |
| advantages | quicker context switching | easier synchronization |
| advantages | simpler to implement | easier to debug |

##  multi threading

the ability of a program or an operating system to enable more than one user at a time without requiring multiple copies of the program running on the computer

##  examples of multithreading

in a browser, each tab can be a different thread

microsoft word employs multiple threads one for text formatting, another for processing inputs, etc.

##  multi threading models

**many to one** -  many user level threads mapped to a single kernel thread

**one to one** -  each user level thread maps to a kernel thread

**many to many** -  many user level threads mapped to many kernel threads

##  many to one model

**description** -  many user level threads mapped to a single kernel thread

**advantage** -  simple to implement

**disadvantage** - if the kernel thread blocks, all user level threads are blocked

[t] [t] [t] [t] user thread
  \ |    |  /
      [k] kernel threads

##  example 

image you are working on your computer,  you can have several programs open at the same time like a word process, a web browser, and a music player.  all of these programs are running under your user...

##  one to one model

**description** -  each user level thread maps to a kernel thread

**advantage** -  as more concurrency as other threads can run if one thread is blocked

**disadvantage** -  creates overhead due to large number of kernel threads

[t] --- [k]

[t] --- [k]

[t] --- [k]

[t] --- [k]

##  example

think of a process as a task or job your computer is doing, like running a game or a web browser.  each of these tasks has a unique id...

##  many to many model

<p align=center>
    <img src="./assets/thread-many.png">
</p>

##  example

think of files on your computer like documents or pictures.  different users can have different kinds of access to these files some might be able to read them, some might be able to write them, and some might not have access at all.

##  thread libraries

**purpose** -  provide programmers with an api for creating and managing threads

**examples** -  posix pthreads, java threads, windows threads

##  issues with multi threading

thread cancellation, signal cancellation

##  thread cancellation

##  signal handling

##  handling thread specific data

##  basic thread creation and execution

**define functions** -  two functions, `print_numbers`, `print_letters` are defined.  each function prints a sequence of items with a 1 second delay between prints

**create threads** -  two threads, `t1`, `t2` are created.  `t1` runs the `print_numbers` function, and `t2` runs the `print_letters` function

**start thread** -  both threads are started using the `start()` method which triggers the execution of the respective functions

```python
import threading
import time

def print_numbers():
    for i in range(1, 6):
    print(f"number: [i])
    time.sleep(1)

def print_letters():
    for letters in ["A", "B", "C", "D", "E"]:
        print(f"letter: [letters]")
        time.sleep(1)

#  creating threads
t1 = threading.Thread(target=print_numbers)
t2 = threading.Thread(target=print_letters)

#  starting threads
t1.start()
t2.start()

#  waiting for threads to finish
t1.join()
t2.join()
```
