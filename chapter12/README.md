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

