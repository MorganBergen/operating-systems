#  cpu scheduling

##  process execution cycle

process execution consists of a cycle of cpu execution and i/o wait

##  cpu scheduling decisions

scheduling decisions occur when process

switches from running to waiting (non preemptive)

switches from running to ready (preemptive)

switches from waiting to react (preemptive)

terminates (non preemptive)

##  dispatcher module

the dispatcher module gives control of the cpu to the process selected by the short term scheduler

dispatch latency  the time it takes for the dispatcher to stop one process and start another 

##  cpu scheduling algorithms

many cpu scheduling algorithms can be classified into two categories -  preemptive and non preemptive

**non preemptive scheduling**

one a process starts its execution, it runs to completion without being interrupted by another process

**examples**

**first come first serve (fcfs)** -  processes are executed in the order they arrive

**shortest job first (sjf)** -  the process with the smallest burst tie is executed next

**priority scheduling (non preemptive)** -  the highest priority process that is ready to run and will execute until completion

**preemptive scheduling**

a running process can be interrupted (preempted) if a new process arrives with a higher priority or shorter remaining time

**examples**

**round robin (rr)** -  each process is assigned a fixed time slice and can be preempted after its time slice expires

**shortest remaining time first (srtf)** -  a process is preempted if a new process arrives with a shorter remaining burst time

**priority scheduling (preemptive)** -  a higher priority process can interrupt a currently running lower priority process

##  choosing between preemptive and non preemptive scheduling

##  real world systems

most modern operating systems use preemptive scheduling to ensure responsiveness, particularly in multi tasking environments where multiple processes need to share cpu time efficiently

##  preemptive scheduling systems

**windows os** -  uses preemptive scheduling to allow high priority tasks to interrupt lower priority ones for a responsive user experience

**linux os** -  employs a completely fair scheduler (cfs)  that allows tasks to be

##  non preemptive scheduling systems

embedded systems -  simple micro controllers often 

##  scheduling algorithms continued

scheduling algorithms are chosen based on optimization criteria (e.g. throughput, turnaround time, etc.)

first come first serve (fcfs)

shortest job first (sjf)

round robin (rr)

priority

##  first come first serve

allocated cpu to the process that requests it first, using a fifo queue

**characteristics**

executes tasks on a first come first serve basis

easy to implement

high wait time; less efficient in performance

##  example first come first serve

let's consider an example where four processes with different burst times arrive at different times.  find the finish time, turnaround time, and waiting time for each process.

| process | burst time | arrival time |
| ------- | ---------- | ------------ |
| p1      | 6          | 2            |
| p2      | 8          | 1            |
| p3      | 3          | 0            |
| p4      | 4          | 4            |

waiting time =  turn around time - burst time

turn around time =  finish time - arrival time

gant chart

| c | b | a | d |
|:---:|:---:|:---:|:---:|
| 0 - 3 | 3 - 11 | 11 - 17 | 17 - 21 |

|  job   |  arrival time  |  burst time  |  finish time  |  turn around time  |  waiting time  |
|:------:|:--------------:|:------------:|:-------------:|:-------------------:|:-------------:|
|  p3    |      0         |      3       |      3        |       3 - 0 = 3     |   3 - 3 = 0   |
|  p2    |      1         |      8       |      11       |      11 - 1 = 10    |  10 - 8 = 2   |
|  p1    |      2         |      6       |      17       |      17 - 2 = 15    |  15 - 6 = 9   |
|  p4    |      4         |      4       |      21       |      21 - 4 = 17    |  17 - 4 = 13  |

##  shortest job first

selects the waiting process with the smallest execution time to execute next

**characteristics**

minimizes average waiting time among all scheduling algorithms

each task is associated with a unit of time to complete

may cause starvation if shorter processes keep arriving solvable with aging

##  example shortest job first

lets consider an example where four processes with different burst times arrive at different times.  find the finish time, turnaround time, and waiting time for each process.  also draw the gant chart.

|  process  |  arrival time  |  burst time  |
|:---------:|:--------------:|:------------:|
|  p1 = a   |      0         |      8       |
|  p2 = b   |      1         |      4       |
|  p3 = c   |      2         |      2       |
|  p4 = d   |      3         |      1       |

##  how do priorities work

**priority number**   each process is assigned

##  preemptive priority

let's consider an example where four processes with different burst times arrive at different times.  find the finish time, turnaround time, and waiting time for each process.  also draw the gant chart.

|  process  |  arrival time  |  burst time  |  priority  |
|:---------:|:--------------:|:------------:|:----------:|
|  p1 = a   |      0         |              |            |
|  p2 = b   |      1         |              |            |
|  p3 = c   |      2         |              |            |
|  p4 = d   |      3         |              |            |


##  multilevel queues

**structure**  fixed multiple queues based on criteria e.g. priority, process type

**assignment**  processes assigned to a queue remain there

**scheduling**

**fixed priority**  

##  multilevel feedback queues mlfq

**structure**  multiple dynamic queues with feedback

**assignment**  processes can move between queues based on behavior

**scheduling**  

**feedback**  processes using too much cpu time move to lower priority queues, long waiting processes move to higher priority queues

##  multiprocessor scheduling

**overview**  manages processes multiple cpus/cores for optimal performance

**asymmetric multiprocessing**  

**one paster process**  handles all system tasks

**pros**  simpler, reduced complexity

**cons**  bottleneck risk

##  little's formula

helps determine average wait time per process in any scheduling algorithm

$n = \lambda \times w$

##  example  



