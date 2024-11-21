#  operating systems assignment 3

**assuming a 1 kb page size, what are the page numbers and offsets for the following address references provided as decimal numbers?**

**`3085`**

page number = $\lfloor \frac{3085}{1024} \rfloor = 3$

offset = $3085 \mod 1024 = 13$

`42095`

page number = $\lfloor \frac{42095}{1024} \rfloor = 41$

offset = $42095 \mod 1024 = 31$

`215201`

page number = $\lfloor \frac{215201}{1024} \rfloor = 210$

offset = $215201 \mod 1024 = 257$

`650000`

page number = $\lfloor \frac{650000}{1024} \rfloor = 633$

offset = $650000 \mod 1024 = 136$

`2000001`

page number = $\lfloor \frac{2000001}{1024} \rfloor = 1955$

offset = $2000001 \mod 1024 = 1$

page size = 1 kb = 1024 bytes

**consider a logical address space of 246 pages with a 4 kb page size, mapped onto a physical memory of 64 frames**

**how many bits are required in the logical address?**

logical address space = 246 pages

page size = 4 kb = $2^{12}$ bytes

logical address = page number + offset

bits for page number = $\lceil \log_2 (246) \rceil = 8$

bits for offset = $\lceil \log_2 (2^{12}) \rceil = 12$

total logical address bits = 8 + 12 = 20

**how many bits are required in the physical address?**

physical memory = 64 frames

bits for frame number = $\log_2 (64) = 6$

bits for offset = 12

total physical address bits = 6 + 12 = 18

**on a system with paging, a process cannot access memory that it does not own.  why?  how could the operating system allow access to other memory?  why should it or should it not?**

paging uses a page table to map logical addresses to physical frames.  each process has its own page table, ensuring that there is some sort of protection and isolation between processes.  so attempting to access another processes's memory leads to a protection fault.

the operating system can allow access to other memory by modifying page table entires to share frames between processes.  shared memory regions can be set up for inter process communication.

the operating system should only share data that is intended to be shared, so it should be able to access processes explicitly needed to share data using, because arbitrary access violates the protections of paging.
   
**consider the following page reference string `7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0 , 1.` assuming demand paging with four frames, how many page faults and hits would occur for the following replacement algorithms?  include a visualization of the frames to complete full points**

**LRU replacement** -  maintain a list of recently used pages and replace the least recently used page when needed.  there are 17 page faults and 3 hits.

**optimal replacement** -  predict the next page reference and replace the page that will be used furthest in the future.  there are 11 page faults and 9 hits.

| Step | Page Reference | LRU Memory State | Optimal Memory State |
|:---|:---|:---|:---|
| 1 | 7 | [7] | [7] |
| 2 | 2 | [7, 2] | [7, 2] |
| 3 | 3 | [7, 2, 3] | [7, 2, 3] |
| 4 | 1 | [7, 2, 3, 1] | [7, 2, 3, 1] |
| 5 | 2 | [7, 3, 1, 2] | [7, 2, 3, 1] |
| 6 | 5 | [3, 1, 2, 5] | [7, 3, 1, 5] |
| 7 | 3 | [1, 2, 5, 3] | [7, 3, 1, 5] |
| 8 | 4 | [2, 5, 3, 4] | [7, 1, 5, 4] |
| 9 | 6 | [5, 3, 4, 6] | [7, 1, 5, 6] |
| 10 | 7 | [3, 4, 6, 7] | [7, 1, 5, 6] |
| 11 | 7 | [3, 4, 6, 7] | [7, 1, 5, 6] |
| 12 | 1 | [4, 6, 7, 1] | [7, 1, 5, 6] |
| 13 | 0 | [6, 7, 1, 0] | [1, 5, 6, 0] |
| 14 | 5 | [7, 1, 0, 5] | [1, 5, 6, 0] |
| 15 | 4 | [1, 0, 5, 4] | [1, 6, 0, 4] |
| 16 | 6 | [0, 5, 4, 6] | [1, 6, 0, 4] |
| 17 | 2 | [5, 4, 6, 2] | [1, 0, 4, 2] |
| 18 | 3 | [4, 6, 2, 3] | [1, 0, 2, 3] |
| 19 | 0 | [6, 2, 3, 0] | [1, 0, 2, 3] |
| 20 | 1 | [2, 3, 0, 1] | [1, 0, 2, 3] |

**a system provides support for user level and kernel level threads.  the mapping in this system is one to one (there is a corresponding kernel thread for each user thread).  does a multithreaded process consist of**
   
**a working set for the entire process**

in a multithreaded process, all of the threads share the same address space, therefore the working set may include pages used by any thread in the process.

**a working set for each thread?  explain.**

each thread might have its own active set of pages that it uses frequently, so the operating system can track this separately.

