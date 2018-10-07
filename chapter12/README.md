# chapter12

## precondition
````shell
mkdir bin
````

## 12.16

### build

    gcc -o bin/12.16 src/12.16.c src/csapp.c

### run

    bin/12.16

## 12.17

A. because the main thread doesn't wait other thread,so other thread exits after main thread exits.

B. use `pthread_exit`

### build

    gcc -o bin/12.17 src/12.17.c src/csapp.c

### run

    bin/12.17