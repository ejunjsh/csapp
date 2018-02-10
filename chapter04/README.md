# chapter04

## precondition
````shell
mkdir bin
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