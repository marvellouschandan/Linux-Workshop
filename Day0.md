# Day 0 : An Awesome Day With Linux!

## Step-by-Step compilation of C Program:

As per I believe compilation of C Program is not a very tedious task. But the step-by-step compilation I believe could be done and viewed on Linux very easily.

So, I took this example to demonstrate how much the analysis is easy on Linux where as a bit difficult on other OS or better say is hidden behind the GUIs which is not a good news for a Computer Science scholar.

So, let's begin with the compilation process-

In this example we are going to use an open-source compiler named GCC to compile our C program.

There are four steps to compile a C program:

1. Pre-processing

2. Compilation

3. Assembly

4. Linking

Let's see each step one-by-one:
### 1. Preprocessing-

This is the first phase through which source code is passed. This phase include:

* Removal of Comments
* Expansion of Macros
* Expansion of the included files.

Let's see the preprocessed file:
```bash
	$ gcc -E sample_code.c
```
Above command just shows the output preprocessed file on terminal. Let's see that inside a file.
```bash
	$ gcc -E sample_code.c | tee sample_code.i
```

The preprocessed output is stored in the sample_code.i. 
Let’s see what’s inside sample_code.i: using 
```bash
	$vi sample_code.i 
```

In the above output, source file is filled with lots and lots of info, but at the end our code is preserved.
Analysis:

* printf contains now a + b rather than add(a, b) that’s because macros have expanded.
* Comments are stripped off.
* #include<stdio.h> is missing instead we see lots of code. So header files has been expanded and included in our source file.

### 2. Compilation-
The next step is to compile sample_code.i and produce an; intermediate compiled output file sample_code.s. This file is in assembly level instructions. 
```bash
	$ gcc -S sample_code.c
```

Let’s see through this file using 
```bash
	$vi sample_code.
```

### 3. Assembly-
In this phase the sample_code.s is taken as input and turned into sample_code.o by assembler. This file contain machine level instructions. At this phase, only existing code is converted into machine language, the function calls like printf() are not resolved.
```bash
	$ gcc -c sample_code.c
```

Let’s view this file using vim-
```bash
$vi sample_code.o
```

### 4. Linking-
This is the final phase in which all the linking of function calls with their definitions are done. Linker knows where all these functions are implemented. Linker does some extra work also, it adds some extra code to our program which is required when the program starts and ends. For example, there is a code which is required for setting up the environment like passing command line arguments. This task can be easily verified by using $size sample_code.o and $size sample_code. Through these commands, we know that how output file increases from an object file to an executable file. This is because of the extra code that linker adds with our program.

```bash
	$ gcc sample_code.c -o sample_code
```

Now let's run this code-
```bash
	$ ./sample_code
```

---

## Basic Linux Commands-

#### ls:
ls (1)               - list directory contents
ls (1p)              - list directory contents

e.g-
```bash
	$ ls -l  # - is a file, d is a directory, l is a symbolic file, x is executable
	$ ls -a  # Concept of hidden files
	$ ls -al
	$ ls -r  # List in reverse name
	$ ls -t  # List new files
	$ ls -rt  # old first
```

#### cd:
cd (n)               - Change working directory
cd (1p)              - change the working directory

e.g-
```bash
	$ cd ~
	$ cd /
	$ cd -
	$ cd .
	$ cd ..
```

#### touch:
touch (1)            - change file timestamps
touch (1p)           - change file access and modification times
```bash
	$ touch test{1, 2, 3}.txt
```

#### cat:
cat (1)              - concatenate files and print on the standard output
cat (1p)             - concatenate and print files

#### less:
less (1)             - opposite of more
less (3perl)         - perl pragma to request less of something

#### more:
more (1)             - file perusal filter for crt viewing
more (1p)            - display files on a page-by-page basis

e.g-more can move forwards and backwards in text files but cannot move backwards in pipes.
```bash
	$ more test.txt
```

#### head:
head (1)             - output the first part of files
head (1p)            - copy the first part of files

#### tail:
tail (1)             - output the last part of files
tail (1p)            - copy the last part of a file

#### pwd:
pwd (n)              - Return the absolute path of the current working directory
pwd (1)              - print name of current/working directory
pwd (1p)             - return working directory name

#### mkdir:
mkdir (2)            - create a directory
mkdir (1)            - make directories
mkdir (1p)           - make directories
mkdir (3p)           - make a directory relative to directory file descriptor
e.g-
```bash
	$ mkdir folder
	$ mkdir -p ~/Desktop/a/b/c
```

#### cp:
cp (1)               - copy files and directories
cp (1p)              - copy files
e.g-
```bash
	$ cp test.txt ~/Documents/newname.txt
	$ cp -i  # Override or not
	$ cp -r folder-inside-folder/
```

#### mv:
mv (1)               - move (rename) files
mv (1p)              - move files
e.g-
```bash
	$ mv -i file.txt ~/Desktop/
	$ mv -v file.txt newname.txt  # Rename a file
```

#### rm:
rm (1)               - remove files or directories
rm (1p)              - remove directory entries
e.g-
```bash
	$ rm -r folder-inside-folder
	$ rm -i file  # Remove interactively
	$ rm -rf folder  # Remove folder recursively and files forcefully
```

#### wget:
wget (1)             - The non-interactive network downloader.

#### date:
date (1)             - print or set the system date and time
date (1p)            - write the date and time

e.g-
```bash
	$ date +'%d/%m/%y %H:%M:%S'
```

#### cal:
cal (1)              - display a calendar
cal (1p)             - print a calendar

#### top:
top (1)              - display Linux processes

#### man:
man (7)              - macros to format man pages
man (1p)             - display system documentation
man (1)              - an interface to the on-line reference manuals

#### grep:
grep (1)             - print lines that match patterns
grep (1p)            - search a file for a pattern

#### find:
find (n)             - search for classes and objects
find (1)             - search for files in a directory hierarchy
find (1p)            - find files

#### ps:
ps (1p)              - report process status
ps (1)               - report a snapshot of the current processes.

#### ssh:
ssh (1)              - OpenSSH SSH client (remote login program)

#### uname:
uname (2)            - get name and information about current kernel
uname (1)            - print system information
uname (1p)           - return system name
uname (3p)           - get the name of the current system

#### hostname:
hostname (7)         - hostname resolution description
hostname (1)         - show or set system host name
hostname (5)         - Local hostname configuration file

#### free:
free (1)             - Display amount of free and used memory in the system
free (3)             - allocate and free dynamic memory
free (3p)            - free allocated memory

#### whoami:
whoami (1)           - print effective userid

#### useradd:
useradd (8)          - create a new user or update default new user information
userdel (8)          - delete a user account and related files

#### kill:
kill (2)             - send signal to a process
kill (1)             - terminate a process
kill (1p)            - terminate or signal processes
kill (3p)            - send a signal to a process or a group of processes

#### ip:
ip (8)               - show / manipulate routing, network devices, interfaces and tunnels
ip (7)               - Linux IPv4 protocol implementation

#### ifconfig:
ifconfig: nothing appropriate.

#### ping:
ping (8)             - send ICMP ECHO_REQUEST to network hosts

#### whois:
whois: nothing appropriate.

#### tar:
tar (1)              - an archiving utility
tar (5)              - format of tape archive files

#### rmdir:
rmdir (2)            - delete a directory
rmdir (1)            - remove empty directories
rmdir (1p)           - remove directories
rmdir (3p)           - remove a directory

### Package management:
```bash
	$ sudo apt-get install filezilla
	$ sudo apt-get remove filezilla
	$ sudo apt-get purge filezilla
	$ sudo apt-cache search filezilla
	$ sudo apt-cache show filezilla
	$ sudo apt-get update  # Resynchronize sources
	$ sudo apt-get upgrade  # Upgrade all packages to newest version
	$ sudo apt-get dist-upgrade  # Also upgrade dependencies
```
