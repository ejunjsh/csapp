# chapter04

## precondition
````shell
mkdir bin
cd src/sim
sudo apt install flex bison tcl8.5-dev tk8.5-dev 
make clean
make
````

## 4.45

    subq $8, %rsp
    movq REG, (%rsp)

A

    No

    if REG is %rsp, we push %rsp-8 instead of %rsp into stack

B.

    movq REG, -8(%rsp)
    subq $8, %rsp


## 4.46

    movq (%rsp), REG
    addq $8, %rsp

A.

No

if REG is %rsp, `movq (%rsp), REG` pop the right value into %rsp,now the %rsp is not the pointer of stack, so `addq $8,%rsp` is useless.

B.

    addq $8, %rsp
    movq -8(%rsp), REG

## 4.47

A
see [bubble-sort-pointer.c](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/4.47/bubble-sort-pointer.c)

B
see [bubble-sort-pointer.ys](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/4.47/bubble-sort-pointer.ys)

    cd src/
    sim/misc/yas 4.47/bubble-sort-pointer.ys
    sim/misc/yis 4.47/bubble-sort-pointer.yo
    Stopped in 131 steps at PC = 0x13.  Status 'HLT', CC Z=1 S=0 O=0
    Changes to registers:
    %rax:   0x0000000000000000      0x0000000000000020
    %rsp:   0x0000000000000000      0x0000000000000200
    %rsi:   0x0000000000000000      0x0000000000000018
    %rdi:   0x0000000000000000      0x0000000000000018
    %r9:    0x0000000000000000      0x0000000000000001
    %r10:   0x0000000000000000      0x0000000000000002
    %r13:   0x0000000000000000      0x0000000000000001
    %r14:   0x0000000000000000      0x0000000000000008

    Changes to memory:
    0x0018: 0x0000000000000004      0x0000000000000001
    0x0020: 0x0000000000000003      0x0000000000000002
    0x0028: 0x0000000000000002      0x0000000000000003
    0x0030: 0x0000000000000001      0x0000000000000004
    0x01f0: 0x0000000000000000      0x0000000000000055
    0x01f8: 0x0000000000000000      0x0000000000000013

see above output, the order of array is ascend.