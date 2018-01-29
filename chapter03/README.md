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

## 3.67

A.

    104  +------------------+
         |                  |
         |                  |
         |                  |
         |                  |
         |                  |
         |                  |
         |                  |
         |                  |
     64  +------------------+ <-- %rdi
         |                  |
         |                  |
         |                  |
         |                  |
         |                  |
         |                  |
     32  +------------------+
         |         z        |
     24  +------------------+
         |        &z        |
     16  +------------------+
         |         y        |
      8  +------------------+
         |         x        |
      0  +------------------+ <-- %rsp


B.

eval pass a new address %rsp+64 to process

C.

process access s by %rsp+offset, not by %rdi

D.

eval pass address %rsp+64 to process, process store data from here as beginning,
finially return this address

E.

    104  +------------------+
         |                  |
         |                  |
         |                  |
         |                  |
         |                  |
         |                  |
     88  +------------------+
         |        z         |
     80  +------------------+
         |        x         |
     72  +------------------+
         |        y         |
     64  +------------------+ <-- %rdi(eval pass in)
         |                  |  \
         |                  |   -- %rax(process pass out)
         |                  |
         |                  |
         |                  |
         |                  |
     32  +------------------+
         |         z        |
     24  +------------------+
         |        &z        |
     16  +------------------+
         |         y        |
      8  +------------------+
         |         x        |
      0  +------------------+ <-- %rsp in eval
         |                  |
     -8  +------------------+ <-- %rsp in process

F.

caller find space and pass space address to callee, callee store data on this
space area and return this address

## 3.68

see comments in [3.68.s](https://github.com/ejunjsh/csapp/blob/master/chapter03/src/3.68.s)
then

    4 < B <= 8
    6 < A <= 10
    44 < A*B <= 46

so

    A = 9
    B = 5

## 3.69
see comment
````s
# void test(long i, b_struct *bp)
# i in %rdi, bp in %rsi
test:
  mov 0x120(%rsi), %ecx         # bp+0x120 fetch bp->last
  add (%rsi), %ecx              # bp->first + bp->last
  lea (%rdi,%rdi,4), %rax       # i*5
  lea (%rsi,%rax,8), %rax       # bp+i*40

  # ap = &bp->a[i] = bp+i*40+8, +8 means skip int first
  # so a_struct is aligned by 8, size is 40
  # check last instruction, %rdx here saves value ap->idx!!!
  # so in a_struct, idx is first element
  mov 0x8(%rax), %rdx

  movslq %ecx, %rcx             # n = bp->first + bp->last, convert to long

  # save n to address 8*(ap->idx) + bp+i*40+0x8 + 0x8  (0x10)
  # bp+i*40+0x8 means ap
  # ap + 0x8 means &(ap->x)
  # ap + 0x8 + 8*(ap->idx) means &(ap-x[ap->idx])
  # second element of a_struct is x, x is an array of long
  # 8*(ap->idx) means idx is also long type
  mov %rcx, 0x10(%rax,%rdx,8)

  # size of a_struct is 40 and aligned by 8
  # so array x has 4 long elements
  # finally, a_struct is
  #   typedef struct {
  #     long idx,
  #     long x[4]
  #   } a_struct
  retq
````
because bp->first takes 8 Bytes,(bp->first+b->a) takes 0x120=288
so b->a takes 280 , as i know, size of a_struct is 40

so CNT=280/40=7