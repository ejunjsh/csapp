# chapter12

## precondition
````shell
mkdir bin
````

## code 12.26 from book

### build

    gcc -o bin/reader-writer src/reader-writer.c src/csapp.c -lpthread

### run

    bin/reader-writer

## 12.16

### build

    gcc -o bin/12.16 src/12.16.c src/csapp.c -lpthread

### run

    bin/12.16

## 12.17

A. because the main thread doesn't wait other thread,so other thread exits after main thread exits.

B. use `pthread_exit`

### build

    gcc -o bin/12.17 src/12.17.c src/csapp.c -lpthread

### run

    bin/12.17

## 12.18

A unsafe

B safe

C unsafe

## 12.19

### build

    gcc -o bin/12.19 src/12.19.c src/csapp.c -lpthread

### run

    bin/12.19

## 12.20

### build

    gcc -o bin/12.20 src/12.20.c src/csapp.c -lpthread

### run

    bin/12.20

## 12.21

### build

    gcc -o bin/12.21 src/12.21.c src/csapp.c -lpthread

### run

    bin/12.21

## 12.22

### build

    gcc -o bin/12.22 src/12.22.c src/csapp.c -lpthread

### run

    bin/12.22

### test

    telnet localhost 5000

## 12.23

### build

    gcc -o bin/12.23.client src/12.23.client.c src/csapp.c -lpthread
    gcc -o bin/12.23.bug src/12.23.bug.c src/csapp.c -lpthread
    gcc -o bin/12.23 src/12.23.c src/csapp.c -lpthread

### run

    bin/12.23.bug
    bin/12.23
    bin/12.23.client

### test

    bin/12.23.bug
    bin/12.23.client

you will see `Connection reset by peer`,and server clash.

    bin/12.23

it will deal with the error without clash.

## 12.24

if don't pass pointer param which points to same data block, functions

    rio_readn
    rio_writen
    rio_readinitb
    rio_readlineb
    rio_readnb

are all implicitly reentrant functions

## 12.25

see [echo_cnt.c](https://github.com/ejunjsh/csapp/blob/master/chapter12/src/echo_cnt.c)

thread safe?

Yes, mutex make it safe

reentrant?

No, share the same mutex,will cause the dead lock

## 12.26

### build

    gcc -o bin/12.26 src/12.26.c src/csapp.c -lpthread

### run

    bin/12.26


## 12.27

```c
FILE *fpin, *fpout;
fpin = fdopen(sockfd, "r");
fpout = fdopen(sockfd, "w");

// read and write

fclose(fpin);
fclose(fpout);
```
ref: 10.11

`fdopen` open 2 stream on same sockfd, `fdclose` will close sockfd under stream.
if you call `fclose` 2 stream on the same sockfd, the second `fclose` will fail.

image one thread execute code and open 2 stream on fd N. after execution of line
`fclose(fpin);`, program create another thread and execute the same code.

but

after `fclose(fpin);` in thread 1, fd N is reusable again. assume thread 2 use
the fd N again: thread 1 execute line `fclose(fpout);` close the fd that thread
2 is using. it'll cause something unpredicted.

## 12.28

No effect on deadlock

1

|thread 1|thread 2|
|-|-|
|P(s)|P(s)|
|P(t)|P(t)|
|V(s)|V(s)|
|V(t)|V(t)|


        +
        |
        |
        +                   +--------------------+
    V(t)|                   |                    |
        |                   |                    |
        +                   |  unsafe region t   |
        |                   |                    |
        |                   |                    |
        +         +---------+---------+          |
    V(s)|         |         |         |          |
        |         |         |         |          |
        +         |         |         |          |
        |         |         |         |          |
        |         |         |         |          |
        +         |         +---------+----------+
    P(t)|         |                   |
        |         |  unsafe region s  |
        +         |                   |
        |         |                   |
        |         |                   |
        +         +-------------------+
    P(s)|
        |
        +
        |
        |
        +----+----+----+----+----+----+----+----+----+  thread 1
              P(s)      P(t)      V(s)      V(t)



2

|thread 1|thread 2|
|-|-|
|P(s)|P(s)|
|P(t)|P(t)|
|V(s)|V(t)|
|V(t)|V(s)|


        +
        |
        |
        +         +-------------------+
    V(s)|         |                   |
        |         |                   |
        +         |                   |
        |         |                   |
        |         |                   |
        +         |         +---------+----------+
    V(t)|         |         |         |          |
        |         |         |         | unsafe   |
        +         |         |         | region   |
        |         |         |         |    t     |
        |         |         |         |          |
        +         |         +---------+----------+
    P(t)|         |                   |
        |         |                   |
        +         | unsafe region s   |
        |         |                   |
        |         |                   |
        +         +-------------------+
    P(s)|
        |
        +
        |
        |
        +----+----+----+----+----+----+----+----+----+  thread 1
              P(s)      P(t)      V(s)      V(t)




3

|thread 1|thread 2|
|-|-|
|P(s)|P(s)|
|P(t)|P(t)|
|V(t)|V(s)|
|V(s)|V(t)|


        +
        |
        |
        +                   +---------+
    V(t)|                   | unsafe  |
        |                   | region  |
        +                   |   t     |
        |                   |         |
        |                   |         |
        +         +---------+---------+----------+
    V(s)|         |         |         |          |
        |         |         |         |          |
        +         |         |         |          |
        |         |         |         |          |
        |         |         |         |          |
        +         |         +---------+          |
    P(t)|         |                              |
        |         |                              |
        +         |    unsafe region s           |
        |         |                              |
        |         |                              |
        +         +------------------------------+
    P(s)|
        |
        +
        |
        |
        +----+----+----+----+----+----+----+----+----+  thread 1
              P(s)      P(t)      V(t)      V(s)




4

|thread 1|thread 2|
|-|-|
|P(s)|P(s)|
|P(t)|P(t)|
|V(t)|V(t)|
|V(s)|V(s)|


        +
        |
        |
        +         +------------------------------+
    V(s)|         |                              |
        |         |                              |
        +         |                              |
        |         |                              |
        |         |                              |
        +         |         +----------+         |
    V(t)|         |         | unsafe   |         |
        |         |         | region   |         |
        +         |         |    t     |         |
        |         |         |          |         |
        |         |         |          |         |
        +         |         +----------+         |
    P(t)|         |                              |
        |         |                              |
        +         |    unsafe region s           |
        |         |                              |
        |         |                              |
        +         +------------------------------+
    P(s)|
        |
        +
        |
        |
        +----+----+----+----+----+----+----+----+----+  thread 1
              P(s)      P(t)      V(t)      V(s)


## 12.29

no deadlock


initial: a = 1, b = 1, c = 1

|thread 1|thread 2|
|-|-|
|P(a)|P(c)|
|P(b)|P(b)|
|V(b)|V(b)|
|P(c)|V(c)|
|V(c)|----|
|V(a)|----|

thread 2 doesn't manipulate mutex a and initial a is 1, so P(a), V(a) don't affect deadlock status.

|thread 1|thread 2|
|-|-|
|P(b)|P(c)|
|V(b)|P(b)|
|P(c)|V(b)|
|V(c)|V(c)|

        +
        |
        |
        +                             +----------+
    V(c)|                             |          |
        |                             |          |
        +                             |          |
        |                             |          |
        |                             |          |
        +         +----------+        |          |
    V(b)|         |          |        |          |
        |         |          |        |          |
        +         |          |        |          |
        |         |          |        |          |
        |         |          |        |          |
        +         +----------+        |          |
    P(b)|                             |          |
        |                             |          |
        +                             |          |
        |                             |          |
        |                             |          |
        +                             +----------+
    P(c)|
        |
        +
        |
        |
        +----+----+----+----+----+----+----+----+----+  thread 1
              P(b)      V(b)      P(c)      V(c)


## 12.30


initial: a = 1, b = 1, c = 1

|thread 1|thread 2|thread 3|
|-|-|-|
|P(a)|P(c)|P(c)|
|P(b)|P(b)|V(c)|
|V(b)|V(b)|P(b)|
|P(c)|V(c)|P(a)|
|V(c)|P(a)|V(a)|
|V(a)|V(a)|V(b)|

A.

thread 1: a&b, a&c

thread 2: b&c

thread 3: a&b

B.

thread 2 and thread 3

C.

keep same order P(a), P(b), P(c) in every thread

## 12.31

### build

    gcc -o bin/12.31 src/12.31.c src/csapp.c -lpthread

### run

    bin/12.31

## 12.32

### build

    gcc -o bin/12.32 src/12.32.c src/csapp.c -lpthread

### run

    bin/12.32

## 12.33

### build

    gcc -o bin/12.33 src/12.33.c src/csapp.c -lpthread

### run

    bin/12.33


## 12.34

### build

    gcc -o bin/12.34.concurrent src/12.34.concurrent.c src/csapp.c -lpthread
    gcc -o bin/12.34.non.concurrent src/12.34.non.concurrent.c src/csapp.c -lpthread

### test

    time bin/12.34.concurrent && time bin/12.34.non.concurrent

### example

    $ time bin/12.34.concurrent&& time bin/12.34.non.concurrent

    real    0m0.296s
    user    0m1.008s
    sys     0m0.004s

    real    0m0.771s
    user    0m0.768s
    sys     0m0.000s

    obviously the concurrent version is faster than the serial version.

## 12.35

### build

    gcc -o bin/12.35 src/12.35.c src/csapp.c -lpthread

### run

    bin/12.35

### test

click the link [http://localhost:5000](http://localhost:5000)