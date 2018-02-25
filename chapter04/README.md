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

## 4.53

### 1. data hazard

something handled by data-forward must be handled by stall if no data-forward
anymore. so when

    d_srcA in { e_dstE, M_dstM, M_dstE, W_dstM, W_dstE } ||
    d_srcB in { e_dstE, M_dstM, M_dstE, W_dstM, W_dstE }

data hazard happens, we have to insert bubble in phase E and stall phase F&D

**load/use hazard**

load/use hazard only happens when we use data-forward. no load/use hazard if no
data-forward.

pay attention

- previous load/use toggle condition `d_srcA == E_dstM || d_srcB ==
E_dstM` now toggles data hazard.
- in the beginning, `d_srcA == RNONE == e_dstE == E_dstM == ...etc`, that's not
data hazard

so we get:

    situation: data_hazard
    bool s_data_hazard =
      (
        (
          d_srcA != RNONE  &&
          d_srcA in { e_dstE, E_dstM, M_dstM, M_dstE, W_dstM, W_dstE }
        ) ||
        (
          d_srcB != RNONE  &&
          d_srcB in { e_dstE, E_dstM, M_dstM, M_dstE, W_dstM, W_dstE }
        )
      )

### 2. ret situation

keep same

    situation: ret
    bool s_ret = IRET in { D_icode, E_icode, M_icode };

### 3. jxx error

keep same

    situation: jxx error
    bool s_jxx_error = (E_icode == IJXX && !e_Cnd);

### 4. hazard composition

X means nothing to do; stall means stall; bubble means inserting bubble

|num|data|ret|jxx|F|D|E|M|W|
|-|-|-|-|-|-|-|-|-|
|1|0|0|0|X|X|X|X|X|
|2|0|0|1|X|bubble|bubble|X|X|
|3|0|1|0|stall|bubble|X|X|X|
|4|1|0|0|stall|stall|bubble|X|X|

situation 1: nothing happens, every thing is fine

situation 2: just jxx error, keep same with book

situation 3: just ret, keep same with book

situation 4: just data hazard,
stall phase F and D, insert bubble in phase E, M and W keep same

what if two/three of them happen same time?

ret:

      +-----------+    +-----------+    +-----------+
    M |           |  M |           |  M |    ret    |
      +-----------+    +-----------+    +-----------+
    E |           |  E |    ret    |  E |    nop    |
      +-----------+    +-----------+    +-----------+
    D |    ret    |  D |    nop    |  D |    nop    |
      +-----------+    +-----------+    +-----------+
            1                2                3

one of them

jxx error:

      +-----------+
    M |           |
      +-----------+
    E |    jxx    |
      +-----------+
    D |           |
      +-----------+

when jxx error happens, E_icode must be jxx

data hazard:

                   <--+
      +-----------+   |
    M |           |<--+
      +-----------+   |
    E |           |<--+
      +-----------+   |
    D |    xxx    +---+
      +-----------+

when data hazard happens, D_icode is not sure, xxx means any instruction


**composition 1**: ret and jxx

keep same on book

**composition 2**: ret and data hazard

they two happens same time, so xxx must be ret

                   <--+
      +-----------+   |
    M |           |<--+
      +-----------+   |
    E |           |<--+
      +-----------+   |
    D |    ret    +---+
      +-----------+

when they happen same time, data hazard is prior to ret because if ret doesn't
stall to avoid data hazard, we get wrong anwser with ISA

**composition 3**: jxx error and data hazard


                   <--+
      +-----------+   |
    M |           |<--+
      +-----------+   |
    E |    jxx    |<--+
      +-----------+   |
    D |    xxx    +---+
      +-----------+

when they two happens same time, jxx error is prior to data hazard because next
2 instructions is canceled when jxx error, xxx is canceled anymore.

**composition 4**: ret & jxx error & data hazard

                   <--+
      +-----------+   |
    M |           |<--+
      +-----------+   |
    E |    jxx    |<--+
      +-----------+   |
    D |    ret    +---+
      +-----------+

same like composition 3.


finally:

|num|data|ret|jxx|F|D|E|M|W|
|-|-|-|-|-|-|-|-|-|
|1|0|0|0|X|X|X|X|X|
|2|0|0|1|X|bubble|bubble|X|X|
|3|0|1|0|stall|bubble|X|X|X|
|4|1|0|0|stall|stall|bubble|X|X|
|5|0|1|1|X|bubble|bubble|X|X|
|6|1|0|1|X|bubble|bubble|X|X|
|7|1|1|0|stall|stall|bubble|X|X|
|8|1|1|1|X|bubble|bubble|X|X|

F:

- stall: (data || ret) && !jxx
- bubble: 0

D:

- stall: data && !jxx
- bubble: jxx || (!data && ret)

E:

- stall: 0
- bubble: jxx || data

M:

keep same

W:

keep same

finally:

see [pipe-stall.hcl](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/sim/pipe/pipe-stall.hcl)

you can `diff` to see differences with [pipe-std.hcl](https://github.com/ejunjsh/csapp/blob/master/chapter04/src/sim/pip/pipe-std.hcl)