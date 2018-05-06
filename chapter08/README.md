# chapter08

## precondition
````shell
mkdir bin
````

## 8.9
|process pair|cocurrent?|
|------------|-|
|AB|No|
|AC|Yes|
|AD|Yes|
|BC|Yes|
|BD|Yes|
|CD|Yes|

## 8.10
A.  call once, return twice

    fork

B. call once, never return

    longjmp, execve

C. call once, return 1 or more times

    setjmp

## 8.11

4 lines

                            c
                        +-------+
                        |    "hello"
                        |    
                    c   |   p
                +-------+-------+
                |     fork   "hello"
                |
                |           c
                |       +-------+
                |       |    "hello"
                |       |    
                |   p   |   p    
         +------+-------+-------+
        main  fork    fork   "hello"

compile

    gcc -m64 -pthread src/8.11.c src/csapp.c  -o bin/8.11

run 

    bin/8.11

## 8.12

8 lines


                            c
                        +-------+---------+
                        |    "hello"   "hello"
                        |    
                    c   |   p
                +-------+-------+---------+
                |     fork   "hello"   "hello"
                |
                |           c
                |       +-------+---------+
                |       |    "hello"   "hello"
                |       |    
                |   p   |   p    
         +------+-------+-------+---------+
        main  fork    fork   "hello"   "hello"

compile

    gcc -m64 -pthread src/8.12.c src/csapp.c  -o bin/8.12

run 

    bin/8.12

## 8.13

the parent process don't share x with the child process, they have own x.
    
    x=4
    x=3
    x=2


compile

    gcc -m64 -pthread src/8.13.c src/csapp.c  -o bin/8.13

run 

    bin/8.13

## 8.14

3 lines


                            c
                        +-------+
                        |    "hello"
                        |    
                    c   |   p
                +-------+-------+
                |     fork   "hello"
                |
                |   p   
         +------+-------+-------+
        main  fork   return  "hello"


compile

    gcc -m64 -pthread src/8.14.c src/csapp.c  -o bin/8.14

run 

    bin/8.14

## 8.15

5 lines


                            c
                        +-------+-------+---------+
                        |    "hello"  return    "hello"
                        |    
                    c   |   p
                +-------+-------+-------+---------+
                |     fork   "hello"  return    "hello"
                |
                |
                |   p   
         +------+-------+-------+
        main  fork   return  "hello"


compile

    gcc -m64 -pthread src/8.15.c src/csapp.c  -o bin/8.15

run 

    bin/8.15

## 8.16

child process has its own counter.

    counter = 2


compile

    gcc -m64 -pthread src/8.16.c src/csapp.c  -o bin/8.16

run 

    bin/8.16

## 8.17

                            1        Bye
                    +-------+---------+-------------+ exit(2)
                    |    printf     printf          |
                    |                               |
        hello       |        0                      |             2       Bye
    +------+--------+--------+----------------------+--------+--------+---------+
    main  printf    fork    printf              waitpid     printf   printf   exit(2)

 all possible output are 

    hello  1  Bye 0     2  Bye
    hello  1  0   Bye   2  Bye
    hello  0  1   Bye   2  Bye


## 8.18


                            c
                        +-------+---------+
                        |      "0"     exit "2"
                        |    
                    c   |   p
                +-------+-------+---------+
                |     fork     "1"     exit "2"
                |   (atexit)
                |           c
                |       +-------+---------+
                |       |      "0"      exit
                |       |    
                |   p   |   p    
         +------+-------+-------+---------+
        main  fork    fork     "1"      exit

2 must be behind 0/1

B & D is impossible.


compile

    gcc -m64 -pthread src/8.18.c src/csapp.c  -o bin/8.18

run 

    bin/8.18

## 8.19

compile

    gcc -m64 -pthread src/8.19.c src/csapp.c  -o bin/8.19

run 

    bin/8.19

you will see rule is 2^n

## 8.20

compile

    gcc -m64 -pthread src/8.20.c src/csapp.c  -o bin/8.20

run 

    bin/8.20

## 8.21

compile

    gcc -m64 -pthread src/8.21.c src/csapp.c  -o bin/8.21

run 

    bin/8.21

in my computer,always

    bac

but should be

    bac

or 

    abc

## 8.22

compile
    
    gcc -m64 -pthread src/exit-code.c src/csapp.c  -o bin/exit-code
    gcc -m64 -pthread src/wait-sig.c src/csapp.c  -o bin/wait-sig
    gcc -m64 -pthread src/mysystem.c src/csapp.c  -o bin/mysystem

run 

    bin/mysystem

output 

    child pid: 4695
    normally exit, code: 10
    child pid: 4697
    exit caused by signal, code: 15

there are some problem:

while you run mysystem, and open another terminal to kill the child process "4697":

    kill 4697

you will get the message from the orignal terminal

    exit caused by signal, code: 15

but there are a child process that is still running in background and using 100% cpu.
you can top to see:

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
    4791 sky       20   0    6508    776    696 R 100.0  0.0   5:28.98 wait-sig

why? becasue the kill only kill its parent process "sh -c".

    mysystem ----> sh -c -------> wait-sig
    pid=xxxx      pid=4697        pid=4791