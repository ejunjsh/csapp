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

## 3.59

ref 2.6

    ux = x + x_63\*2^64
    uy = y + y_63\*2^64  

so 

    ux ∙ uy = (x + x\_63\*2^64) ∙ (y + y_63\*2^64)
    ux ∙ uy = x ∙ y + (x\_63\*y + y_63\*x)\*2^64 + x\_63\*y\_63\*2^128

2^128 overflows, so

    x ∙ y = ux ∙ uy - (x\_63\*y + y\_63\*x)2^64 

see [3.59.s](https://github.com/ejunjsh/csapp/blob/master/chapter03/src/3.59.s)