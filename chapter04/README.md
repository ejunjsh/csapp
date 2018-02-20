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

## 4.48
see [bubble-sort-pointer-3-cmovl.ys](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/4.48/bubble-sort-pointer-3-cmovl.ys)

    cd src/
    sim/misc/yas 4.48/bubble-sort-pointer-3-cmovl.ys
    sim/misc/yis 4.48/bubble-sort-pointer-3-cmovl.yo
    Stopped in 143 steps at PC = 0x13.  Status 'HLT', CC Z=1 S=0 O=0
    Changes to registers:
    %rax:   0x0000000000000000      0x0000000000000020
    %rsp:   0x0000000000000000      0x0000000000000200
    %rsi:   0x0000000000000000      0x0000000000000018
    %rdi:   0x0000000000000000      0x0000000000000018
    %r9:    0x0000000000000000      0x0000000000000002
    %r10:   0x0000000000000000      0x0000000000000001
    %r11:   0x0000000000000000      0x0000000000000001
    %r13:   0x0000000000000000      0x0000000000000001
    %r14:   0x0000000000000000      0x0000000000000008

    Changes to memory:
    0x0018: 0x0000000000000004      0x0000000000000001
    0x0020: 0x0000000000000003      0x0000000000000002
    0x0028: 0x0000000000000002      0x0000000000000003
    0x0030: 0x0000000000000001      0x0000000000000004
    0x01f0: 0x0000000000000000      0x0000000000000055
    0x01f8: 0x0000000000000000      0x0000000000000013

## 4.49
see [bubble-sort-pointer-1-cmovge.ys](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/4.49/bubble-sort-pointer-1-cmovge.ys)

    cd src/
    sim/misc/yas 4.49/bubble-sort-pointer-1-cmovge.ys
    sim/misc/yis 4.49/bubble-sort-pointer-1-cmovge.yo
    Stopped in 155 steps at PC = 0x13.  Status 'HLT', CC Z=1 S=0 O=0
    Changes to registers:
    %rax:   0x0000000000000000      0x0000000000000020
    %rsp:   0x0000000000000000      0x0000000000000200
    %rsi:   0x0000000000000000      0x0000000000000018
    %rdi:   0x0000000000000000      0x0000000000000018
    %r9:    0x0000000000000000      0x0000000000000002
    %r10:   0x0000000000000000      0x0000000000000001
    %r11:   0x0000000000000000      0x0000000000000002
    %r13:   0x0000000000000000      0x0000000000000001
    %r14:   0x0000000000000000      0x0000000000000008

    Changes to memory:
    0x0018: 0x0000000000000004      0x0000000000000001
    0x0020: 0x0000000000000003      0x0000000000000002
    0x0028: 0x0000000000000002      0x0000000000000003
    0x0030: 0x0000000000000001      0x0000000000000004
    0x01f0: 0x0000000000000000      0x0000000000000055
    0x01f8: 0x0000000000000000      0x0000000000000013

## 4.50
see [switch.ys](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/4.50/switch.ys)

    cd src/
    sim/misc/yas 4.50/switch.ys
    sim/misc/yis 4.50/switch.yo
    Stopped in 133 steps at PC = 0x13.  Status 'HLT', CC Z=0 S=0 O=0
    Changes to registers:
    %rax:   0x0000000000000000      0x0000000000000bbb
    %rcx:   0x0000000000000000      0x00000000000000e7
    %rdx:   0x0000000000000000      0xfffffffffffffffd
    %rsp:   0x0000000000000000      0x0000000000000200
    %rdi:   0x0000000000000000      0x00000000000001a8
    %r8:    0x0000000000000000      0x0000000000000008
    %r11:   0x0000000000000000      0x0000000000000001

    Changes to memory:
    0x0000: 0x000000000200f430      0x0000000000000ddd
    0x0008: 0x0000000038800000      0x0000000000000ddd
    0x0010: 0x0000000000000000      0x0000000000000ccc
    0x0018: 0x0000000000000000      0x0000000000000bbb
    0x01e8: 0x0000000000000000      0x00000000000001a8
    0x01f0: 0x0000000000000000      0x00000000000000ac
    0x01f8: 0x0000000000000000      0x0000000000000013


## 4.51

|phase|iaddq V,rB|
|--|--|
|F|icode:ifun = M1[PC]; rA:rB = M1[PC+1]; valC = M8[PC+2]; valP = PC + 10;|
|D|valB = R[rB]|
|E|valE = valB + valC; set CC|
|M||
|W|R[rB] = valE|
|PC|PC = valP|

## 4.52

see [seq-full.hcl](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/sim/seq/seq-full.hcl)

you can search the keyword with "IIADDQ" in this file to see differences with [seq-std.hcl](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/sim/seq/seq-std.hcl)