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

    