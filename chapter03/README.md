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

see [3.58](https://github.com/ejunjsh/csapp/blob/master/chapter03/src/3.58)

compile:

    gcc -c -m64 src/3.58/decode2.s -o bin/decode2.o
    gcc -m64 src/3.58/main.c src/3.58/decode.c bin/decode2.o -o bin/3.58    
run:

    bin/3.58 

## 3.59

ref 2.6

    ux = x + x_63*2^64
    uy = y + y_63*2^64  

    //x_63 and y_63 represent highest bit of x and y.

so 

    ux ∙ uy = (x + x_63*2^64) ∙ (y + y_63*2^64)
    ux ∙ uy = x ∙ y + (x_63*y + y_63*x)*2^64 + x_63*y_63*2^128

2^128 overflows, so

    x ∙ y = ux ∙ uy - (x_63*y + y_63*x)*2^64 

    //(x_63*y + y_63*x)*2^64 = (x_63*y + y_63*x) << 64

see [3.59.s](https://github.com/ejunjsh/csapp/blob/master/chapter03/src/3.59.s)

## 3.60

A.

|val|register|
|---|---|
|x|%rdi|
|n|%esi|
|result|%rax|
|mask|%rdx|

B.

    result = 0

    mask = 1

C.

    mask != 0

D.

    mask = mask << n

E.  see [3.60](https://github.com/ejunjsh/csapp/blob/master/chapter03/src/3.60)

compile:

    gcc -c -m64 src/3.60/loop.s -o bin/loop.o
    gcc -m64 src/3.60/main.c src/3.60/loop2.c bin/loop.o -o bin/3.60   

run:

    bin/3.60

## 3.61

compile:

    gcc -m64 src/cread-alt.c -o bin/cread-alt

run:

    bin/cread-alt

## 3.62
````c
/* Enumerated type creates set of contants numbered 0 and upward */
typedef enum { MODE_A, MODE_B, MODE_C, MODE_D, MODE_E } mode_t;

long switch3(long *p1, long *p2, mode_t action) {
  long result = 0;
  switch(action) {
    case MODE_A:
      *p2 = *p1;
      result = *p2;
      break;
    case MODE_B:
      *p1 = *p1 + *p2;
      result = *p1;
      break;
    case MODE_C:
      *p1 = 59;
      result = *p2;
      break;
    case MODE_D:
      *p1 = *p2;
      result = 27;
      break;
    case MODE_E:
      result = 27;
      break;
    default:
      result = 12;
      break;
  }
  return result;
}
````

## 3.63 
````c
long switch_prob(long x, long n) {
  long result = x;
  switch(n) {
    /* Fill in code here */
    case 60:
    case 62:
      result = x * 8;
      break;
    case 63:
      result = x >> 3;
      break;
    case 64:
      x = x << 4 - x;
    case 65:
      x = x * x;
    default:
      result = x + 0x4B;
  }
  return result;
}
````

## 3.64
A.

3.1 in book

    T D[R][C];

    &D[i][j] = Xd + L(C*i + j)

    T means type, D means data, R means row, C means column

    L means sizeof(T), Xd means address of D

similarly, in 3d array

    TYPE D[R][S][T]

    &D[i][j][k] = Xd + L(S*T*i + T*j + k)

B.

see [3.64/store-ele.s](https://github.com/ejunjsh/csapp/blob/master/chapter03/src/3.64)

base on comments,

    S * T = 65
    T = 13
    8*R*S*T = 3640

so

    R = 7
    S = 5
    T = 13

## 3.65

A.

    &A[i][j] in %rdx

B.

    &A[j][i] in %rax

C.

    addq $8, %rdx # means A[i][j] -> A[i][j+1]

    addq $120, %rax # means A[j][i] -> A[j+1][i], 120 == 8*M

    M = 15

## 3.66

base on comments in asm code

    cmpq %rdi, %rdx    # cmp t5 & t3
    jne .L3            # if t5 != n*3, loop

t5 is var i, so `NR(n) == n*3`

    leaq 1(,%rdi,4), %r8        # t1 = n*4 + 1
    .....
    salq $3, %r8                # t1 = t1*8 = 8*(n*4 + 1)
    .....
    addq %r8, %rcx              # t4 = t1+t4 = A + j*8 + 8*(n*4 + 1)

in every loop, pointer move `8*(n*4 + 1)` bytes, so `NC(n) == n*4 + 1`

compile:

    gcc src/3.66/*  -o bin/summ-col

run:

    bin/summ-col
