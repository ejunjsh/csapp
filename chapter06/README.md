# chapter06

## precondition
````shell
mkdir bin
````

## 6.22
assume

Bits Per Track

    bpt = x * r * K


Track Count

    tc = (1-x) * r * M


M, K are constant

so

Bit Count

    bc = K * M * r^2 * (1-x) * x

when x == 1/2, bc is maximum

## 6.23

    T_avg_seek = 4ms

    T_avg_rotation = 1/2 * 1/15000 * 60s/min * 1000ms/s = 2ms

    T_avg_transfer = 1/15000 * 1/800 * 60s/min * 1000ms/s = 0.005ms

    so

    T_access = 6.005ms

## 6.24

A.

best case: blocks are mapped sequential and on same cylinder. just seek data
once.

    T_avg_seek = 4ms
    T_avg_rotation = 2ms
    T_avg_transfer = 1/15000 * 1/1000 * 60s/min * 1000ms/s = 0.042ms

file size 2MB, block size 512B, block count 2MB/512B = 4000

Block Per Track = 1000, so we need rotate 4 loop to read all data

    T_max_rotation = 1/15000 * 60s/min * 1000ms/s = 4ms
    T_transfer = T_max_rotation * 4 = 16ms

so

    T_access = T_avg_seek + T_avg_rotation + T_transfer = 22ms


B.

worse case: blocks are random.

    T_access = 4000 * (T_avg_seek + T_avg_rotation + T_avg_transfer) = 24168ms


## 6.25

|m|c|B|E|S|t|s|b|
|-|-|-|-|-|-|-|-|
|32|1024|4|4|64|24|6|2|
|32|1024|4|256|1|30|0|2|
|32|1024|8|1|128|22|7|3|
|32|1024|8|128|1|29|0|3|
|32|1024|32|1|32|22|5|5|
|32|1024|32|4|8|24|3|5|

## 6.26

|m|c|B|E|S|t|s|b|
|-|-|-|-|-|-|-|-|
|32|2048|8 |1  |256|21|8|3|
|32|2048|4 |4  |128|23|7|2|
|32|1024|2 |8  |64 |25|6|1|
|32|1024|32|2  |16 |23|4|5|

## 6.27

A.

t = 0x45 = 0b01000101, s = 0b001, b = xx(xx may be 00/01/10/11)

address may be

    0100 0101 001 xx

    format
    0 1000 1010 01xx

address range: 0x08A4 - 0x08A7

t = 0x38

address may be

    0011 1000 001 xx

    format
    0 0111 0000 01xx

address range: 0x0704 - 0x0707

B.

t = 0x91 , s = 0b110

address may be

    1001 0001 110 xx

    format
    1 0010 0011 10xx

address range: 0x1238 - 0x123B

t = 0xF0

address may be

    1111 0000 110 xx

    format
    1 1110 0001 10xx

address range: 0x1E18 - 0x1E1B

## 6.28

A.

t = 0xEB , s = 0b010

address may be

    1110 1011 010 xx

    format
    1 1101 0110 10xx

address range: 0x1D68 - 0x1D6B

t = 0x0B

address may be

    0000 1011 010 xx

    format
    0 0001 0110 10xx

address range: 0x0168 - 0x016B

B.

t = 0xC7 , s = 0b100

address may be

    1100 0111 100 xx

    format
    1 1000 1111 00xx

address range: 0x18F0 - 0x18F3

t = 0x05 

address may be

    0000 0101 100 xx

    format
    0 0000 1011 00xx

address range: 0x00B0 - 0x00B3

C.

t = 0x71 , s = 0b101

address may be

    0111 0001 101 xx

    format
    0 1110 0011 01xx

address range: 0x0E34 - 0x0E37

t = 0x6E 

address may be

    0110 1110 101 xx

    format
    0 1101 1101 01xx

address range: 0x0DD4 - 0x0DD7

D.

t = 0x46 , s = 0b111

address may be

    0100 0110 111 xx

    format
    0 1000 1101 11xx

address range: 0x08DC - 0x08DF

t = 0xDE 

address may be

    1101 1110 111 xx

    format
    1 1011 1101 11xx

address range: 0x1BDC - 0x1BDF

## 6.29

A.

      11   10    9    8    7    6    5    4    3    2    1   0
    +----+----+----+----+----+----+----+----+----+----+----+----+
    | CT | CT | CT | CT | CT | CT | CT | CT | CI | CI | CO | CO |
    +----+----+----+----+----+----+----+----+----+----+----+----+

B.

|read/write|addr|hit?|value(or unknown)|
|-|-|-|-|
|read|0x834|No|-|
|write|0x836|Yes|unknown|
|read|0xFFD|Yes|0xC0|
