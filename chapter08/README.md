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