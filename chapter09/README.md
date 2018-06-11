# chapter09

## precondition
````shell
mkdir bin
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
