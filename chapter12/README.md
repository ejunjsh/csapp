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

    bin/12.16