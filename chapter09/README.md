# chapter09

## precondition
````shell
mkdir bin
cd chapter09
````

## 9.5

compile

    gcc -pthread src/mmapcopy.c src/csapp.c -o bin/mmapcopy

run

    bin/mmapcopy


## 9.11

VA: 0x027c

A.

      13 12 11 10  9  8  7  6  5  4  3  2  1  0
     +--|--|--|--|--|--|--|--|--|--|--|--|--|--+
     | 0| 0| 0| 0| 1| 0| 0| 1| 1| 1| 1| 1| 0| 0|
     +--|--|--|--|--|--|--|--|--|--|--|--|--|--+

B.

|param|value|
|-----|-----|
|VPN  |0x09 |
|TLBI |0x01 |
|TLBT |0x02 |
|hit? |No   |
|page falut?|No   |
|PPN  |0x17 |


C.


      11 10  9  8  7  6  5  4  3  2  1  0
     +--|--|--|--|--|--|--|--|--|--|--|--+
     | 0| 1| 0| 1| 1| 1| 1| 1| 1| 1| 0| 0|
     +--|--|--|--|--|--|--|--|--|--|--|--+


D.


|param|value|
|-----|-----|
|CO   |0x00 |
|CI   |0x0F |
|CT   |0x17 |
|hit? |No   |
|value|-----|


## 9.12

9.12

VA: 0x03a9

A.

      13 12 11 10  9  8  7  6  5  4  3  2  1  0
     +--|--|--|--|--|--|--|--|--|--|--|--|--|--+
     | 0| 0| 0| 0| 1| 1| 1| 0| 1| 0| 1| 0| 0| 1|
     +--|--|--|--|--|--|--|--|--|--|--|--|--|--+

B.

|param|value|
|-----|-----|
|VPN  |0x0E |
|TLBI |0x02 |
|TLBT |0x03 |
|hit? |No   |
|page falut?|No   |
|PPN  |0x11 |


C.


      11 10  9  8  7  6  5  4  3  2  1  0
     +--|--|--|--|--|--|--|--|--|--|--|--+
     | 0| 1| 0| 0| 0| 1| 1| 0| 1| 0| 0| 1|
     +--|--|--|--|--|--|--|--|--|--|--|--+


D.


|param|value|
|-----|-----|
|CO   |0x01 |
|CI   |0x0A |
|CT   |0x11 |
|hit? |No   |
|value|-----|



## 9.13

VA: 0x0040

A.

      13 12 11 10  9  8  7  6  5  4  3  2  1  0
     +--|--|--|--|--|--|--|--|--|--|--|--|--|--+
     | 0| 0| 0| 0| 0| 0| 0| 1| 0| 0| 0| 0| 0| 0|
     +--|--|--|--|--|--|--|--|--|--|--|--|--|--+

B.

|param|value|
|-----|-----|
|VPN  |0x01 |
|TLBI |0x01 |
|TLBT |0x00 |
|hit? |No   |
|page falut?|Yes  |

## 9.14

compile

    gcc -pthread  src/9.14.c src/csapp.c -o bin/9.14

run

    bin/9.14

## 9.15

|malloc|size|header|
|-|-|-|
|malloc(3) | 8| 0x9|
|malloc(11)|16|0x11|
|malloc(20)|24|0x19|
|malloc(21)|32|0x21|

## 9.16

**min block size= max (min allocated block or min spare block)**

|alignment| allocated block | spare block | min block size|
|---------|-----------------|-------------|---------------|
|word     |Header & Footer  |Header & Footer| 16 |
|word     |Header           |Header & Footer| 16 |
|double word|Header & Footer|Header & Footer| 16 |
|double word|Header         |Header & Footer| 16 | 


## 9.17

see [mm.v1/mm.c](https://github.com/ejunjsh/csapp/blob/master/chapter09/src/mm.v1/mm.c)

build

    gcc -c src/mm.v1/mm.c -I./src/mm/ -o mm.v1.o

## 9.18

see [mm.v2/mm.c](https://github.com/ejunjsh/csapp/blob/master/chapter09/src/mm.v2/mm.c)

build

    gcc -c src/mm.v2/mm.c -I./src/mm/ -o mm.v2.o

## 9.19

1 

    a: ☑️
    b: ✖️
    c: ✖️
    d: ✖️

2

    a: ✖️
    b: ✖️
    c: ✖️
    d: ☑️

3

    only b is ☑️

## 9.20

use 9.18 malloc to test with the std malloc

build

    gcc -DCUS_MALLOC src/9.20.c src/mm.v2/mm.c src/mm/memlib.c src/csapp.c -lpthread  -I./src/mm/ -I./src/ -o mymalloc
    gcc src/9.20.c -o stdmalloc

test

    time ./mymalloc && time ./stdmalloc
    malloc size: 25000000, heap_size: 28311552

    real    0m0.011s
    user    0m0.000s
    sys     0m0.008s
    malloc size: 25000000, heap_size: 28311552

    real    0m0.009s
    user    0m0.000s
    sys     0m0.004s
    malloc size: 25000000, heap_size: 28311552

    real    0m0.009s
    user    0m0.000s
    sys     0m0.004s

    