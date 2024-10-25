#  operating systems

assignment 2

###  question 1

can a multithreaded solution using multiple user level threads achieve better performance on a multiprocessor system than on a single processor system?  explain

a multithreaded solution using multiple user level threads can achieve better performance on a multiprocessor system than on a single processor system because it can take advantage of the multiple processors to execute multiple threads concurrently. This allows for more efficient use of the CPU and can lead to faster execution times.

###  question 2

a multithreaded web server wishes to keep track of the number of requests it services (known as bits).  consider the two following strategies to prevent a race condition on the variable hits.

the first strategy is to use the basic mutex lock when updating hits

```cpp
int hints;
mutex lock hit lock;
hit lock.acquire();
hits++;
hit lock.release();
```

a second strategy is to use an atomic integer

```cpp
atomic t hits;
atomic inc($hits);
```

explain which of these two strategies is more efficient

a race condition occurs when multiple processes or threads read and write shared data concurrently, and the final outcome depends on the sequence of their execution.  this can lead to unpredictable behavior and bugs that are hard to reproduce and debug.  both of the strategies above prevent race conditions by ensuring that only one thread can update the `hits` variable at a time.  

the `mutex` is short for mutual exclusion and it ensure that only one thread at a time can acquire the lock and update the `hits` variable.  when a thread wants to update `hits`, it must acquire the lock, modify the value, and release the lock so other threads can proceed.  

the overhead occurs when acquiring and releasing a `mutex` lock.  `mutex` involve system calls that may cause context switching if other threads are waiting for the lock, which introduces overhead.  

###  question 3

for each scheduling algorithm calculate the following for each process

a.  finish time
b.  turnaround time
c.  waiting time
d.  draw a gantt chart

then identify which process has the minimum waiting time.  time quantum = 2

processes: `p1`, `p2`, `p3`, `p4`

|  process  |  arrival time  |  burst time  |  priority  | 
|:---------:|:--------------:|:------------:|:----------:|
|    p1     |        0       |      5       |     3      |
|    p2     |        2       |      3       |     1      |
|    p3     |        4       |      1       |     4      |
|    p4     |        6       |      7       |     2      |


###  question 4

write a program that simulates a soda dispenser using a stack data structure.  create a class named `SodaDispenser` with methods to manage the dispenser.  implement the following methods `add_soda(self, soda)`, `dispense_soda(self)`, `is_empty(self)`, `peek_soda(self)`.  ensure your program includes test cases demonstrating the functionality of these methods.  submit your implementation in blackboard as a file named `SodaDispenser` followed by your name and id, using the appropriate file extension for the language you choose.  your submission will be evaluated on the correctness of the methods, handling of edge cases, code readability, and proper commenting. 

`add_soda(self, soda)` to add a soda represented as a string to the top of the dispenser

`dispense_soda(self)` to remove and return the soda from the top of the dispenser, handling the case where the dispenser is empty by raising an exception or returning a special value

`is_empty(self)` to return `True` is the dispenser is empty and `False` otherwise

`peek_soda(self)` to return the soda at the top of the dispenser without removing it, also handling the empty dispenser scenario appropriately