# chapter07

## precondition
````shell
mkdir bin
````

## 7.6

|    |in .symtab?| type | module | section |
|----|-----------|------|--------|---------|
|buf |     Yes   |external|m       | .data   |
|bufp0|    Yes   |global|swap    | .data   |
|bufp1|    Yes   |local |swap    | .bss    |
|swap|     Yes   |global|swap    | .text   |
|temp|     No    |------|-----   | ------  |
|incr|     Yes   |local |swap    | .text   |
|count|    Yes   |local |swap    | .bss    |

validate

    gcc -c src/swap.c -o bin/swap.o
    objdump -t bin/swap.o

    bin/swap.o:     file format elf64-x86-64

    SYMBOL TABLE:
    0000000000000000 l    df *ABS*  0000000000000000 swap.c
    0000000000000000 l    d  .text  0000000000000000 .text
    0000000000000000 l    d  .data  0000000000000000 .data
    0000000000000000 l    d  .bss   0000000000000000 .bss
    0000000000000000 l    d  .data.rel      0000000000000000 .data.rel
    0000000000000000 l     O .bss   0000000000000008 bufp1
    0000000000000000 l     F .text  0000000000000016 incr
    0000000000000008 l     O .bss   0000000000000004 count.1797
    0000000000000000 l    d  .note.GNU-stack        0000000000000000 .note.GNU-stack
    0000000000000000 l    d  .eh_frame      0000000000000000 .eh_frame
    0000000000000000 l    d  .comment       0000000000000000 .comment
    0000000000000000 g     O .data.rel      0000000000000008 bufp0
    0000000000000000         *UND*  0000000000000000 buf
    0000000000000016 g     F .text  000000000000004d swap


## 7.7

comment the `x=-0.0`

test

    gcc src/bar5.c src/foo5.c -o bin/7.7
    bin/7.7

## 7.8

A.

    main.1

    main.2

B.

    unknown

    unknown

C.

    error

    error


## 7.9

the `0x48` is low byte of assemble code of `main` method, why it is a byte,because `bar6.c` declare it as a char.

when linking,the first byte of assemble code of the `main` method  is set to `main` variable in `bar6.c`

test

    gcc src/bar6.c src/foo6.c -o bin/7.9
    bin/7.9
    0x55

my output is `0x55`

    objdump -d bin/7.9

ignore all but main function below

    000000000000066e <main>:
    66e:   55                      push   %rbp
    66f:   48 89 e5                mov    %rsp,%rbp
    672:   48 83 ec 10             sub    $0x10,%rsp
    676:   89 7d fc                mov    %edi,-0x4(%rbp)
    679:   48 89 75 f0             mov    %rsi,-0x10(%rbp)
    67d:   e8 c8 ff ff ff          callq  64a <p2>
    682:   b8 00 00 00 00          mov    $0x0,%eax
    687:   c9                      leaveq
    688:   c3                      retq
    689:   0f 1f 80 00 00 00 00    nopl   0x0(%rax)

you will see `0x55` in `66e:   55                      push   %rbp`