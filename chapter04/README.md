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