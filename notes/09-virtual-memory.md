#  virtual memory

##  page faults

##  demand paging

pages are loaded into memory only when they are needed.  

reduces the amount of memory used by loading pages on demand

page faults occur when a page is not found

##  handling page faults

the operating system checks the page table to determine if the access is valid

if valid, the operating system locates a free frame in physical memory

the required page is loaded from disk into the free frame

the page table is updated with the new frame information

the process is resumed from where it was interrupted

##  page replacement strategies

copy on write cow

definition -  shared pages are copied only when modified, reducing unnecessary duplication until modification

key point -  optimize memory usage by delaying page duplication until necessary

modify (dirty) bit

definition -  a flag indicating

##  hit rate

hit rate measures the proportion of memory accesses that resulted in a hit (i.e. accessing a page that is already in memory)

formula -  hit rate = hits / reference string length

##  fault rate

fault rate measures the proportion of memory accesses that resulted in a page fault (i.e. accessing a page that needs to be loaded into memory)

formula - fault rate = faults / reference string length
