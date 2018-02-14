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