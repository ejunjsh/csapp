# chapter05

## precondition
````shell
mkdir bin
````

## 5.13
A.

     +----+----+----+----+-----+-----+
     |%rbp|%rcx|%rax|%rbx|%xmm1|%xmm0|
     +----+----+----+----+-----+-----++----+
       +----|----|----|----------|--->|    |
       |    +----|----|----------|--->|load|      vmovad 0(%rbp,%rcx,8),%xmm1
       |    |    |    |    +-----|----|    |
       |    |    |    |    |     |    +----+
       |    +----|----|----------|--->|    |
       |    |    |    |    |     |    |load|---+
       |    |    +----|----------|--->|    |   |
       |    |    |    |    |     |    +----+   |  vmulsd (%rax,%rcx,8),%xmm1,%xmm0
       |    |    |    |    |     |    |    |<--+
       |    |    |    |    +-----|--->|mul |
       |    |    |    |    +-----|----|    |
       |    |    |    |    |     |    +----+
       |    |    |    |    +-----|--->|    |
       |    |    |    |    |     +--->|add |      vaddsd %xmm1,%xmm0,%xmm0
       |    |    |    |    |     +----|    |
       |    |    |    |    |     |    +----+
       |    +----|----|----------|--->|    |
       |         |    |    |     |    |add |      addq $1, %rcx
       |    +----|----|----------|----|    |
       |    |    |    |    |     |    +----+
       |    +----|----|----------|--->|    |
       |    |    |    |    |     |    |cmp |---+  cmpq %rbx, %rcx
       |    |    |    +----|-----|--->|    |   |
       |    |    |    |    |     |    +----+   |
       |    |    |    |    |     |    |    |   |
       |    |    |    |    |     |    |jne |<--+  jne .L15
       |    |    |    |    |     |    |    |
       |    |    |    |    |     |    +----+
       v    v    v    v    v     v
     +----+----+----+----+-----+-----+
     |%rbp|%rcx|%rax|%rbx|%xmm1|%xmm0|
     +----+----+----+----+-----+-----+



          +----+                      +-----+
          |%rcx|                      |%xmm0|
          +----+                      +-----+
            |                           |
            |     +----+                |  <--------- key path
            +---->|load|------+         |
            |     +----+      |         |
            |                 v         v
            |     +----+    +-+--+    +-+--+
            +---->|load|--->|mul |--->|add |
            |     +----+    +----+    +----+
            |                           |
            |                           |
            v                           |
          +----+                        |
          |add |                        |
          +----+                        |
            |                           |
            v                           v
          +-+--+                      +-----+
          |%rcx|                      |%xmm0|
          +----+                      +-----+

B.

    float add on key path, so CPE is 3.0

C.

    long add on key path, so CPE is 1.0

D.

    float multiply is not on the key path, only float add on key path

compile

    gcc src/5.13.c src/vec.c -o bin/5.13

run 

    bin/5.13

## 5.14


     +----+                          +----+
     |sum |                          | i  |
     +----+                          +----+
       |                               |
       v                               |
     +----+       +----+  +----+       |
     |add |<------|mul |<-|load|<------+
     +----+       +----+  +----+       |
       |                               |
       v                               |
     +----+       +----+  +----+       |
     |add |<------|mul |<-|load|<------+
     +----+       +----+  +----+       |
       |                               |
       v                               |
     +----+       +----+  +----+       |
     |add |<------|mul |<-|load|<------+
     +----+       +----+  +----+       |
       |                               |
       v                               |
     +----+       +----+  +----+       |
     |add |<------|mul |<-|load|<------+
     +----+       +----+  +----+       |
       |                               |
       v                               |
     +----+       +----+  +----+       |
     |add |<------|mul |<-|load|<------+
     +----+       +----+  +----+       |
       |                               |
       v                               |
     +----+       +----+  +----+       |
     |add |<------|mul |<-|load|<------+
     +----+       +----+  +----+       |
       |                               |
       |                               v
       |                             +----+
       |                             |add |
       |  <------- key path          +----+
       |                               |
       |                               |
       v                               v
     +----+                          +-+--+
     |sum |                          | i  |
     +----+                          +----+

A.

    every element has 6 long/float add

    element count is n/6

    so n/6 * 6 = n

    CPE bound == 1.0

B.

    same like A


compile

    gcc src/5.14.c src/vec.c -o bin/5.14

run 

    bin/5.14


# 5.15

maybe

1. float mul capatity limit(less than 6)
2. register renaming limit

compile

    gcc src/5.15.c src/vec.c -o bin/5.15

run 

    bin/5.15


# 5.16

compile

    gcc src/5.16.c src/vec.c -o bin/5.16

run 

    bin/5.16

# 5.17

compile

    gcc src/5.17.c  -o bin/5.17

run 

    bin/5.17

# 5.18

compile

    gcc src/5.18.c  -o bin/5.18

run 

    bin/5.18

# 5.19

compile

    gcc src/5.19.c  -o bin/5.19

run 

    bin/5.19