# CSC 415 - Project 2 - File copy

## Student Name : Tsun Ming Lee

## Student ID   : 918541473

## Build Instructions : I use "make" to compile the progam 

## Run Instructions : type "./fc" to run the code

## What my code does : The code is copy and creat a new file.

## strace/dtruss output : 

Welcome to the File Copy Program by Tsun Ming Lee!

Enter the name of the file to copy from:LICENSE

Enter the name of the file to copy to:LICENSECOPY

File Copy Successful, 1074 bytes copied.

| % time   | seconds  | usecs/call |    calls   | errors |     syscall  |
| :--------:  | :--------:  |    :------:   |  :------:  | :-----:  |   :------:      |
|48.63       |0.000996  |       18      |    56      |            |    write        |
|32.52       |0.000666  |       12      |    56      |            |    read         |
|5.76         |0.000118  |       30      |    4        |            |    openat     |
|3.37         |0.000069  |       17      |    4        |            |  mprotect    |
|2.98         |0.000061  |       12      |    5        |            |   mmap       |
|1.81         |0.000037  |       37      |    1        |            |   munmap   |
|1.61         |0.000033  |       8        |    4        |            |   fstat          |
|1.46         |0.000030  |       8        |    4        |            |   close         |
|1.07         |0.000022  |       7        |    3        |            |   brk            |
|0.49         |0.000010  |       10      |    1        |            |   arch_prctl |
|0.29         |0.000006  |       6        |    1        |     1     |   lseek        |
|0.00         |0.000000  |       0        |    3        |     3     |   access     |
|0.00         |0.000000  |       0        |    1        |            |   execve      |
|100.00     |0.002048  |                 |  143      |     4     |     total     |


We can see the table is showing the time on the left hand side, middle is how many times of the system call, also the right hand side is the name of the system call. We can see system call write and read both are  56 on the calls, because the problem need to read what the file have and copy. But why the uses/call are differene. I think because read the file only need one time, so after the program finish to read the file, it doesn't need to read again. The write is more than read because of the "error", that mean my problem have some loop is about if any error then the problem need to stop. The problem need to check if any error for everytime it run, so that will make "write" will call more then "read".
