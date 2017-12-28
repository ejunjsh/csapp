# chapter02

## precondition
````shell
mkdir bin
````

## 2.55

```c
!INCLUDE "./code/show-bytes.c"
```

uname -mr:

    4.13.0-16-generic x86_64

compile:

    gcc -m64 src/show-bytes.c -o bin/show-bytes

run:

    bin/show-bytes

output:

    48 01 00 00
    00 00 a4 43
    78 7e 55 ce fe 7f 00 00

## 2.56

change:

    int test_num = 2047;

compile:

    gcc -m64 src/show-bytes.1.c -o bin/show-bytes.1

run:

    bin/show-bytes.1

output:

    ff 07 00 00
    00 e0 ff 44
    c8 c8 85 58 fe 7f 00 00

## 2.57


compile:

    gcc -m64 src/show-bytes-more.c -o bin/show-bytes-more

run:

    bin/show-bytes-more

output:

    48 01 00 00
    00 00 a4 43
    b4 33 4e cb fe 7f 00 00
    48 01
    48 01 00 00 00 00 00 00
    00 00 00 00 00 80 74 40
    48 01 00 00
    
## 2.58


compile:

    gcc -m64 src/is-little-endian.c -o bin/is-little-endian

run:

    bin/is-little-endian || echo $?

output:

    1

## 2.59

expression

    (x & 0xFF) | (y & ~0xFF)

compile:

    gcc -m64 src/generate-a-word.c -o bin/generate-a-word

run:

    bin/generate-a-word

## 2.60

compile:

    gcc -m64 src/replace-byte.c -o bin/replace-byte

run:

    bin/replace-byte# 2.61

A

    !~x

B

    !x

C

    !~(x | ~0xff)

D

    !((x >> ((sizeof(int)-1) << 3)) & 0xff)

compile:

    gcc -m64 src/2.61.c -o bin/2.61

run:

    bin/2.61
    
## 2.62

compile:

    gcc -m64 src/int-shifts-are-arithemetic.c -o bin/int-shifts-are-arithemetic

run:

    bin/int-shifts-are-arithemetic
    
## 2.63

compile:

    gcc -m64 src/srl-sra.c -o bin/srl-sra

run:

    bin/srl-sra
    
## 2.64

compile:

    gcc -m64 src/any_odd_one.c -o bin/any_odd_one

run:

    bin/any_odd_one
    
## 2.65

compile:

    gcc -m64 src/odd-ones.c -o bin/odd-ones

run:

    bin/odd-ones
    
## 2.66

compile:

    gcc -m64 src/leftmost-one.c -o bin/leftmost-one

run:

    bin/leftmost-one
    
## 2.67

A:

    If the value of the right operand is negative or is greater than or equal to the width of the promoted left operand, the behavior it undefined.

B & C:

    see code src/int-size-is-32.c

compile:

    gcc -m64 src/int-size-is-32.c -o bin/int-size-is-32

run:

    bin/int-size-is-32
    
## 2.68

compile:

    gcc -m64 src/lower-one-mask.c -o bin/lower-one-mask

run:

    bin/lower-one-mask
    
## 2.69

compile:

    gcc -m64 src/rotate-left.c -o bin/rotate-left

run:

    bin/rotate-left
    
## 2.70

compile:

    gcc -m64 src/fit-bits.c -o bin/fit-bits

run:

    bin/fit-bits
    
## 2.71

A:

    This function can't extract a negetive byte number from word

compile:

    gcc -m64 src/xbyte.c -o bin/xbyte

run:

    bin/xbyte
    
## 2.72

A:

    sizeof(val) return type size_t, it usually is a kind of unsigned type.
    calculate maxbytes-sizeof(val) get size_t type value, and it always >= 0

compile:

    gcc -m64 src/copy-int.c -o bin/copy-int

run:

    bin/copy-int
    
## 2.73

compile:

    gcc -m64 src/saturating-add.c -o bin/saturating-add

run:

    bin/saturating-add
    
## 2.74

compile:

    gcc -m64 src/tsub-ok.c -o bin/tsub-ok

run:

    bin/tsub-ok
    
## 2.75

compile:

    gcc -m64 src/unsigned-high-prod.c -o bin/unsigned-high-prod

run:

    bin/unsigned-high-prod

## 2.76

compile:

    gcc -m64 src/calloc.c -o bin/calloc

run:

    bin/calloc

## 2.77

compile:

    gcc -m64 src/2.77.c -o bin/2.77

run:

    bin/2.77

## 2.78

compile:

    gcc -m64 src/divide-power2.c -o bin/divide-power2

run:

    bin/divide-power2

## 2.79

compile:

    gcc -m64 src/mul3div4.c -o bin/mul3div4

run:

    bin/mul3div4

## 2.80

compile:

    gcc -m64 src/threeforths.c -o bin/threeforths

run:

    bin/threeforths

## 2.81

A:

    -1 << k

B:

    ~(-1 << k) << j

compile:

    gcc -m64 src/2.81.c -o bin/2.81

run:

    bin/2.81

## 2.82

A:

    Wrong,if x is INT_MIN

B,C,D,E:

    Right


compile:

    gcc -m64 src/2.82.c src/lib/random.c -o bin/2.82

run:

    bin/2.81

## 2.83

A.

    n = 0.yyyyy...

    n << k = y.yyyyy... = Y + n

    n << k - n = Y

    n = Y/(2^k - 1)

B.

(a).

    y = 101, Y = 5, k = 3

    n = 5/7

(b).

    y = 0110, Y = 6, k = 4

    n = 2/5

(c).

    y = 010011, Y = 19, k = 6

    n = 19/63

## 2.84

compile:

    gcc -m64 src/float-le.c -o bin/float-le

run:

    bin/float-le

## 2.85

bias = 2^(k-1)-1

V = 2^E * M


A:

    assume k=8 so bias=127
    7.0=111.000....
    M=1.11,f=0.11,E=2,e=bias+E=127+2=129
    0 10000001 11000000000000000000000

B:

    biggest odd number, M must be 1.11111...,f=0.111111....
    E = n, V = 0b11111111...(n+1 bits 1) = 2^(n+1) - 1
    0 bias+n 11111....

C:
    
    M must be 0b1.00...., f = 0b0.000...., E = 1 - bias
    V = 2^(1-bias)
    reciprocal
    V = 2^(bias-1)
    E = bias-1, e = bias + E=bias+bias-1
    assume k=8 so e=127+127-1=253
    0 11111101 00000000000000000000000

## 2.86

k=15
bias = 2^(15-1) - 1

|description| binary | decimal |
|-----------|--------|---------|
|least positive unstandard| 0 0000...(15) 0 000...(62)1 | 2^(1-bias-63) |
|least positive standard| 0 000...(14)1 1 000....(63) | 2^(1-bias) |
|bigest standard| 0 111...(14)0 1 111...(63) | 2^bias * (2-2^-63) |


## 2.87

| Desc | Hex | M | E | V | D |
|------|-----|---|---|---|---|
| -0 | 0x8000 | 0 | -14 | -0 | -0.0 |
| >2 least | 0x4001 | 1025/1024 | 1 | 1025/512 | 2.00195312 |
| 512 | 0x6000 | 1 | 9 | 512 | 512.0 |
| bigest denormalized | 0x03FF | 1023/1024 | -14 | 1023/(2^24) | 6.09755516e-5 |
| -oo | 0xFC00 | - | - | -oo | -oo |
| ox3BB0 | 0x3BB0 | 59/64 | -1 | 59/128 | 0.4609375 |