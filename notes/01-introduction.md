#  introduction to operating systems

**operating systems**

**tuesday august 21, 2024**

##  what is an operating system

-  definition -  an os is a program that acts as an intermediary between a user of a computer and the computer hardware
-  the goals of an operating systems are to execute user programs, make the computer system easy to use, and to utilize the hardware efficiently
-  the operating system is the intermediary between applications, a monitor, a keyboard, a printer, mouse, hard drive, etc.

##  evolution and history of operating systems

-  early days -  computers has no operating systems; each program required different code, making data processing complex and time-consuming
-  1956 -  general motors developed the first os for a single ibm computer
-  1960s -  ibm began installing os in their devices
-  unix -  first launched in the 1960s, written in c
-  microsoft -  developed os at ibm's request
-  today -  all major computer devices have os, performing similar functions with unique features

##  common operating systems

-  windows -  developed by microsoft, most popular os
-  mac os -  developed by apple, used in macbooks
-  linux -  open-source os, used in servers and personal computers
-  android -  developed by google, used in smartphones and tablets
-  ios -  developed by apple, used in iphones and ipads

##  fundamental goals of an operating system

1.  efficient use -  optimize computer recourse utilization
2.  user -  convenience -  provide eacy and convenient system usage
3.  non-interference -  prevent user activity interference

##  advantage and disadvantages of operating systems

**advantages**

-  memory management -  manages data in the device efficiently
-  hardware utilization -  optimize use of computer hardware
-  security -  maintain device security
-  application efficiency -  helps run different applications smoothly

**disadvantages**

-  useability -  this can be different for some users
-  cost and maintenance -  some are expensive and need heavy maintenance
-  security risks -  vulnerable to hacking threats

##  computer system structure

-  hardware -  physical components of a computer
-  os -  manages hardware, provides services for applications
-  applications -  software performing specific tasks
-  users -  people interacting with the computer

##  functions of an operating system

-  **resource allocators** -  decides between conflicting requests for efficient and fair resource use.
-  **control program** -  controls execution of programs to prevent error and improper use of the computer
-  registers <-> cache <-> main memory <-> electronic disk <-> magnetic disk <-> optical disk <-> magnetic tapes

##  the kernel

-  **definition** -  the one program running at all times on the computer
-  **role** -  manages system resources and communication between hardware and software

##  bootstrap program

-  **definition** -  loaded at power-up or reboot
-  **storage** -  stored in rom or eprom (firmware)
-  **function** -  initializes system aspects, loads os kernel, and starts execution

##  concurrency and interrupts

-  **concurrency** -  input/output and cpu can execute concurrently.  example -  a user can type on a keyboard while a file is being downloaded
-  **interrupts** -
    +  device controllers inform cpu of operation completion via an interrupt
    +  control is transferred to the interrupt service routine through the interrupt vector
    +  example -  a printer controller signals the cpi that printing is complete

##  types of interrupts

```
        interrupts
           /  \
    hardware  software
    interrupt interrupt
      /   \
maskable   non-maskable  
interrupt  interrupt
```
-  **interrupts** -  incoming interrupts are disabled while another is processed
-  **trap** -  a software generated interrupt caused by an error or user request
-  **os role** -  determines interrupt type via polling or vector interrupt system

##  system calls and device status table

-  **system call** -  request to the os for input/output completion
-  **device-status table** - entry for each i/o device indicating its type, address, and state


example of windows and unix system calls:

the following illustrates various equivalent system calls for windows and unix operating systems

| description                 | windows command                                                          | unix command                                   |
|:---------------------------:|:------------------------------------------------------------------------:|:----------------------------------------------:|
| process <br> control        | `CreateProcess()` <br> `ExitProcess()` <br> `WaitForSingleObject()`      | `fork()` <br> `exit()` <br> `wait()`           |
| file <br> manipulation      | `CreateFile()` <br> `ReadFile()` <br> `WriteFile()`<br> `CloseHandle()`  | `open()` <br> `read()` <br> `write()` `close()`|
| device <br> management      | `SetConsoleMode()` <br> `ReadConsole()` <br> `WriteConsole()`            | `ioctl()` <br> `read()` <br> `write()`         |
| information <br> management | `GetCurrentProcessID()` <br> `SetTimer()` <br> `Sleep()`                 | `getpid()` <br> `alarm()` <br> `sleep()`       |
| communications              | `CreatePipe()` <br> `CreateFileMapping()` <br> `MapViewOfFile()`         | `pipe()` <br> `shm_open` <br> `mmap()`         |
| protection                  | `SetFileSecurity()` <br> `InitializeSecurityDescriptor()` <br> `SetSecurityDescriptorGroup()` | `chmod()` <br> `umask()` <br> `chown()` |

##  storage structure

-  **main memory** -  random access, volatile.  example - ram, used for currently running programs
-  **secondary storage** - large, non-volatile extension of main memory.  example - hard drives, ssds, for long term data storage
-  **disk** -  divided into tracks and sectors, managed by disk controller. example - a hard disk is divided into tracks and sectors

##  caching

coping information into faster storage system to speed up access

no caching - each multi-step request is processed one by one

caching - subsequent requests receive a copy of the result

##  multiprocessor system

**benefits** -  increased throughput, economy of scale, increased reliability

**types** -  asymmetric, symmetric, clustered systems - linked multiprocessor system

##  multiprogramming and time sharing

**multiprogramming** -  provide efficiency via job scheduling

**timesharing** -  cpu switches jobs frequently for interacting computing

##  dual mode operation

**definition** -  allows os to protect itself and other system components

**modes** -  user mode, kernel mode

**privileged instructions** -  executable only in kernel mode

##  processes and threads

**single threaded processes** -  one program counter

**multi threaded processes** -  one program counter per thread

##  protection and security 

**protection** -  mechanism for controlling access to resources

**security** -  defense against attacks

##  user and group ids

**user ids (uid)** -  one per user

**group ids** - determine privileges for users and groups

|  person              | role           | file access              |
|:--------------------:|:--------------:|:------------------------:|
| super user (root)    | administrator  | `/share`                 |
| user1                | marketing      | `/share/marketing`       |
| user2                | sales          | `/share/sales`           |
| user3                | business       | `/share/business`        |

##  activity

**choose an operating system such as windows, macos, or linux** and answer these questions about the operating system you choose

#### 1.  what are the key features?

**user interface and design**
-  **dark mode** which allows the user to choose between light and dark color scheme for the system interface
-  **mission control** which provides an overview of all windows, desktops, and full screen apps
  
**integration with apple ecosystem**
-  **continuity** which allows a device to connect to other apple devices
-  **icloud** which allows for cloud storage for file and data to be access between different apple devices
-  **sidecar** which allows for a secondary display to be used.

**security and privacy**
-  **gatekeeper** ensures that software is downloaded from identified developers and protects against malware
-  **fileVault** ensures for full disk encryption to protect data
-  **privacy controls** where users can control which apps can access their data such as location, camera, and files

**built-in applications**
-  **safari** which is the default web browser
-  **mail** which is the default email client
-  **photos, music, and tv** which is the default photo management app, music player, and video player
-  **calendar** which is the default calendar app
-  **messages and facetime** which are apps for messaging and video calls

**navigation tools**
-  **finder** which is the default file management system
-  **spotlight** which is a search tool for finding files and applications
-  **automator** - a tool for creating custom workflows and automating tasks 

**software development**
-  **xcode** which is the default ide for developing macos and ios applications
-  **unix terminal** which allows for command line access to the system

**accessibility**
-  **voiceover** which is a screen reader for the visually impaired
-  **zoom** which allows for magnification of the screen
-  **siri** which is a voice assistant for controlling the system
-  **dictation** which allows for voice to text input

####  2.  how does the user interface look and feel?

polished, aesthetically pleasing, minimalistic layout, smooth animations, and vibrant colors

####  3.  what security features are included?

**gatekeeper** which is app verification which ensures that only trusted software or identified developers can be installed on the mac, it checks for a valid developer certificate before allowing installation, which reduces the risk of malware

**fileVault** which is full disk encryption, which protects data from unauthorized access

**password management** called keychain which is a secure way to store and manage passwords

**firewall** which is a network security feature which controls incoming and outgoing network traffic and prevents unauthorized connections to the mac

**t2 security chip** the security chip has security features including secure boot, hardware based encryption, and secure storage for touch id information and passwords

**two factor authentication** which is an account security feature that requires a password and a verification code sent to another device to log in

####  4.  what are the common use cases?

1.  creative work such as graphic design, video editing, and music production
2.  software development for applications, websites, games, and cross platform development
3.  business and office work for documents, spreadsheets, presentations, and communication
4.  education for research, writing, presentations, and collaboration
5.  entertainment for watching movies, listening to music, playing games, and browsing the web