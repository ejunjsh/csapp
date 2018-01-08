# chapter03

## precondition
````shell
mkdir bin
````

## 3.45

compile:

    gcc -m64 src/struct_align.c -o bin/struct_align

run:

    bin/struct_align

## 3.58

compile:

    gcc -c -m64 src/3.58/decode2.s -o bin/decode2.o
    gcc -m64 src/3.58/main.c src/3.58/decode.c bin/decode2.o -o bin/3.58    
run:

    bin/3.58 