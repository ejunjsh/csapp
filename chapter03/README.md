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

  # save n to address 8*(ap->idx) + bp+i*40 + (0x8 + 0x8)  (0x10)
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
conclusion from above comments:
bp->first takes 8 Bytes,(bp->first+b->a) takes 0x120=288
so b->a takes 280 ,
and size of a_struct is 40
so CNT=280/40=7

## 3.70

A

|val|offset|
|---|------|
|e1.p|0|
|e1.y|8|
|e2.x|0|
|e2.next|8|

B

    16

C

see comment
````s
# void proc(union ele *up)
# up in %rdi
proc:
  # %rax = *(up+8), don't know it's next or y
  movq 8(%rdi), %rax

  # %rdx = *( *(up+8) ), %rax stands for a pointer
  # so *( *(up+8) ) means *(up->e2.next)
  movq (%rax), %rdx

  # %rdx = *( *(up->e2.next) )
  # %rdx is treated as a pointer
  # so %rdx stores *( *(up->e2.next).e1.p )
  movq (%rdx), %rdx

  # %rax stores *(up+8)
  # %rax is treated as a pointer
  # so %rax = *( up->e2.next ), stands for another union ele's address
  #
  # in subq, %rdx is a long number
  # *( *(up->e2.next)+8 ) must be a long number
  # so 8(%rax) means *(up->e2.next).e1.y
  subq 8(%rax), %rdx

  # %rdi never changes in previous instructions
  # instruction below is the final assignment
  # so (%rdi) means up->e2.x
  movq %rdx, (%rdi)
  ret
````

````C
void proc(union ele *up) {
  up->e2.x = *( *(up->e2.next).e1.p ) - *(up->e2.next).e1.y
}
````

## 3.71
see [good-echo.c](https://github.com/ejunjsh/csapp/blob/master/chapter03/src/3.71/good-echo.c)

compile

    gcc src/3.71/good-echo.c -o bin/good-echo

run

    bin/good-echo

## 3.72

A

    s2 = s1 - [ (n * 8 + 30) & 0XFFFFFFF0 ]

    when n is odd

    s2 = s1 - (n * 8 + 24)

    when n is even

    s2 = s1 - (n * 8 + 16)

B

    p = (s2 + 15) & 0XFFFFFFF0
    the least multiple of 16 that greater than s2

C

|which|e1|n|s1|
|-|-|-|-|
|least|1|even|n%16==1|
|greatest|24|odd|n%16==0|

least:

e1 can't be 0, if e1 == 0, p should equal to s2

when n is even, e1 + e2 == 16, if e2 is 15, e1 will be least that can reach,
so s1 == n that n%16==1

greatest:

when n is odd, e1 + e2 == 24. if p == s2, e2 == 0, so e1 will be the greatest
value 24 that can reach. s1 == n that n%16 == 0

D

    p is aligned by 16

    s2 is the least multiple of 16 that preserve 8*n size space