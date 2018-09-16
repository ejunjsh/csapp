# chapter10

## precondition
````shell
mkdir bin
````

## 10.6

build

    gcc -o bin/10.6 src/10.6.c src/csapp.c

run

    bin/10.6

output

    fd2 = 4

## 10.7

build

    gcc -o bin/10.7 src/10.7.c src/csapp.c

run

    bin/10.7

## 10.8

build

    gcc -o bin/fstatcheck src/10.8.c src/csapp.c

run

    bin/fstatcheck

## 10.9

    if (Fork() == 0) {
        Dup2(0, 3);
        Execve("fstatcheck", argv, envp);
    }