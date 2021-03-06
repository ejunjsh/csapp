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


## 6.30

A.

    C = E * B * S = 128B

B.

      12   11   10    9    8    7    6    5    4    3    2    1   0
    +----+----+----+----+----+----+----+----+----+----+----+----+----+
    | CT | CT | CT | CT | CT | CT | CT | CT | CI | CI | CI | CO | CO |
    +----+----+----+----+----+----+----+----+----+----+----+----+----+

## 6.31

A.

      12   11   10    9    8    7    6    5    4    3    2    1   0
    +----+----+----+----+----+----+----+----+----+----+----+----+----+
    |  0 |  0 |  1 |  1 |  1 |  0 |  0 |  0 |  1 |  1 |  0 |  1 |  0 |
    +----+----+----+----+----+----+----+----+----+----+----+----+----+

B.

|param|value|
|-|-|
|CO|0x02|
|CI|0x06|
|CT|0x38|
|hit?|Yes|
|return|0xEB|

## 6.32

A.

      12   11   10    9    8    7    6    5    4    3    2    1   0
    +----+----+----+----+----+----+----+----+----+----+----+----+----+
    |  1 |  0 |  1 |  1 |  0 |  1 |  1 |  1 |  0 |  1 |  0 |  0 |  0 |
    +----+----+----+----+----+----+----+----+----+----+----+----+----+

B.

|param|value|
|-|-|
|CO|0x00|
|CI|0x02|
|CT|0xB7|
|hit?|No|
|return|--|

## 6.33

    the first line memory address is below:

      12   11   10    9    8    7    6    5    4    3    2    1   0
    +----+----+----+----+----+----+----+----+----+----+----+----+----+
    |  1 |  0 |  1 |  1 |  1 |  1 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |
    +----+----+----+----+----+----+----+----+----+----+----+----+----+

    so the range is 0x1788-0x178B

    the second line memory address is below:

      12   11   10    9    8    7    6    5    4    3    2    1   0
    +----+----+----+----+----+----+----+----+----+----+----+----+----+
    |  1 |  0 |  1 |  1 |  0 |  1 |  1 |  0 |  0 |  1 |  0 |  0 |  0 |
    +----+----+----+----+----+----+----+----+----+----+----+----+----+

    so the range is 0x16C8-0x16CB

## 6.34

src:

|  |c0|c1|c2|c3|
|--|--|--|--|--|
|r0|m |m |h |m |
|r1|m |h |m |h |
|r2|m |m |h |m |
|r3|m |h |m |h |

dst:

|  |c0|c1|c2|c3|
|--|--|--|--|--|
|r0|m |m |m |m |
|r1|m |m |m |m |
|r2|m |m |m |m |
|r3|m |m |m |m |


## 6.35

The cache can store all data in array, so the cache hit except address of every row.

src:

|  |c0|c1|c2|c3|
|--|--|--|--|--|
|r0|m |h |h |h |
|r1|m |h |h |h |
|r2|m |h |h |h |
|r3|m |h |h |h |

dst:

|  |c0|c1|c2|c3|
|--|--|--|--|--|
|r0|m |h |h |h |
|r1|m |h |h |h |
|r2|m |h |h |h |
|r3|m |h |h |h |


## 6.36

```c
int x[2][128];
int i;
int sum = 0;

for (i = 0; i < 128; i++) {
  sum += x[0][i] * x[1][i];
}
```

A.

    C = 512, E = 1, B = 16, S = 32

    total read count: 2 * 128

    x[0][i] address: i*4

    x[1][i] address: (128+i)*4 = 512 + i*4

    so x[0][i] and x[1][i] are cached into same block.

    miss rate 100%

B.

    C = 1024, E = 1, B = 16, S = 64

    sizeof(x) == 2 * 128 * 4 == C

    whole array can be cached.

    miss rate is depended on block size B.

    B = 16, sizeof(int) = 4, so

    miss rate is 25%

C.

    C = 512, E = 2, B = 16, S = 16

    total read count: 2 * 128

    x[0][i] address: i*4

    x[1][i] address: (128+i)*4 = 512 + i*4

    so x[0][i] and x[1][i] are cached into different block in same set.

    in first half, all elements can be cached. miss rate is 25%.

```c
for (i = 0; i < 64; i++)
  sum += x[0][i] * x[1][i];
```

    in second half 

```c
for (i = 64; i < 128; i++)
  sum += x[0][i] * x[1][i];
```

    x[0][i] is not in cache. according to LRU strategy, cache x[0][i] into the
    same block with x[0][i-64], cache x[1][i] into the
    same block with x[1][i-64]. miss rate is 25%.

    finally, miss rate is still 25%.

D.

    No

    if B is still 16, sizeof(int) = 4, block can only cache 4 int one time.

    read int first time toggle memory cache, miss; next 3 time read hit.

    25% miss rate is lowest.

E.

    Yes

    assume B = 32, block cache 8 int at one time.

    only 1 miss in 8 time int read.

    miss rate can be 12.5%.

## 6.37

```c
!INCLUDE "./code/6.37.c"
```

C = 4096, B = 16, E = 1, S = 256


### N = 64

````c
typedef int array_t[N][N];

int sumA(array_t a) {
  int i, j;
  int sum = 0;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      sum += a[i][j];

  return sum;
}

int sumB(array_t a) {
  int i, j;
  int sum = 0;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      sum += a[j][i];

  return sum;
}

int sumC(array_t a) {
  int i, j;
  int sum = 0;
  for (i = 0; i < N; i+=2)
    for (j = 0; j < N; j+=2)
      sum += (a[j][i] + a[j][i+1] + a[j+1][i] + a[j+1][i+1])
}
````

sizeof(array_t) == 64 * 64 == 4096 == 4*C


    memory-cache graph

    memory address start from 0 and end to 4096*4.

    cell size is 16B. number(0-255) in cell means cache block number that the cell
    will be cached.

        0    +---------+
             |    0    |
        16   +---------+
             |    1    |
        32   +---------+
             |    2    |
        48   +---------+
             |    .    |
             |    .    |
             |    .    |
             |    .    |
             |    .    |
    4096-16  +---------+
             |   255   |
       4096  +---------+
             |    0    |
    4096+16  +---------+
             |    1    |
    4096+32  +---------+
             |    .    |
             |    .    |
             |    .    |
             |    .    |
             |    .    |
             |    .    |
    4096*4-16+---------+
             |   255   |
    4096*4   +---------+

A. sumA

    sum += a[i][j];

read memory address order:

0, 4, 8, 12, ....., 4096*4-4

read cache order:

0, 0, 0, 0, 1, 1, 1, 1,.....255, 255, 255, 255, 0, 0, 0, 0,.....255, 255, 255,
255

first cache read miss, next 3 time read hit.

miss rate: 25%

B. sumB

    sum += a[j][i];


read memory address order:
````

0, 64*4, 64*4*2, .... 64*4*63, 4, 64*4+4, 64*4*2+4, .... 4096*4-4
````

read cache order:
````
0, 16, 32, 48, ... 240,(4 times) 1, 17, 33, ... 241,(4 times)
15, 31, 47, ... 255(4 times)
````

let's see first read loop:

read cache order loop 4 times

0, 16, 32, 48, ... 240,(4 times)

first loop all miss, next 3 loop all hit

so miss rate is 25%.

C. sumC

    for (i = 0; i < N; i+=2)
      for (j = 0; j < N; j+=2)
        sum += (a[j][i] + a[j][i+1] + a[j+1][i] + a[j+1][i+1]);

easy to see that read a[j][i+1] and a[j+1][i+1] always hit

same like

    for (i = 0; i < N; i+=2)
      for (j = 0; j < N; j+=2)
        sum += (a[j][i] + a[j+1][i]);

same like

    for (i = 0; i < N; i+=2)
      for (j = 0; j < N; j++)
        sum += a[j][i];

total read count = 64*64

because of i+=2,

read cache order only loop 2 times

0, 16, 32, 48, ... 240,(2 times)

so miss rate is 50%

total read miss count = 64/2 * 64 * 50% = 64*64/4

so miss rate is still 25%.

### N = 60

A. sumA

    sum += a[i][j];

read memory by step 1

miss rate 25%

B. sumB

    for (i = 0; i < N; i++)
      for (j = 0; j < N; j++)
        sum += a[j][i];

it's interesting.

let's see first inner loop a[0][0] -> a[59][0]

read memory address order:
````
0, 60*4, 60*4*2, .... 60*4*59
````
read cache order:

0, 15, 30, ...., 225, (17 numbers)
255, 14, 29, ....., 224, (17 numbers)
254, 13, 28, ....., 223, (17 numbers)
253, 12, 27, 42, 57, 72, 87, 102, 117 (9 numbers)

all read miss and store into different blocks

next 3 loops: a[0][1] -> a[59][1], a[0][2] -> a[59][2], a[0][3] -> a[59][3]

all hit

althrough N is smaller and not power of 2, miss rate is still 25%

C. sumC

same as miss rate when N = 64

25%

## 6.38

A.

    4 * 16 * 16

B.

    sizeof(point_color) == 16, B = 32

    the first access always miss

    square[i][j].c = 0

    then cache 2 point_color

    square[i][j].m = 0
    square[i][j].y = 0
    square[i][j].k = 0
    square[i][j+1].c = 0
    square[i][j+1].m = 0
    square[i][j+1].y = 0
    square[i][j+1].k = 0

    above are all hit in cache

    so miss count is 4 * 16 * 16 * 1/8

C.

    1/8

## 6.39

A.

    4 * 16 * 16

B.

    sizeof(point_color) == 16, B = 32

    square[j][i].c = 0

    the first always miss,the cache can store 2 point_color, then

    square[j][i].m = 0
    square[j][i].y = 0
    square[j][i].k = 0

    all hit.

    next loop

    square[j+1][i] - square[j][i] == 16*16 == 256

    square[j+1][i] miss, cache block not conflict with square[j][i]

    square[j+8][i] - square[j][i] == 16*16*8 == 2048

    square[j+8][i] miss, cache block overwrite square[j][i] block. 

    so when we reach square[j][i+1], still miss.

    so miss count is 4 * 16 * 16 * 1/4

C.

    1/4

## 6.40

A.

    4 * 16 * 16

B.

    first loop, same like 6.38, but

    write count is 16*16, miss rate is 1/2.

    second loop, same like 6.38, but

    write count is 16*16*3, miss rate is 1/6.

    miss count is

    16*16*1/2 + 16*16*3*1/6

C.

    1/4


## 6.41

    every loop

    buffer[i][j].r = 0;

    always miss, then cache one piexl, so

    buffer[i][j].g = 0;
    buffer[i][j].b = 0;
    buffer[i][j].a = 0;

    all hit

    so miss rate is 1/4

## 6.42

same like

```c
for (i = 0; i < 640; i++)
  for (j = 0; j < 480; j++)
    buffer[i][j].r = 0;
    buffer[i][j].g = 0;
    buffer[i][j].b = 0;
    buffer[i][j].a = 0;
```

C = 64KB, B = 4B, sizeof(piexl) = 4

    buffer[i][j].r = 0;

miss, cache one piexl, so

    buffer[i][j].g = 0;
    buffer[i][j].b = 0;
    buffer[i][j].a = 0;

all hit

miss rate is 1/4

## 6.43

same like
````c
for (i = 0; i < 640; i++)
  for (j = 0; j < 480; j++)
    (int*)&buffer[i][j] = 0;
````
every loop,
````c
(int*)&buffer[i][j] = 0;
````
always miss

miss rate 100%

## 6.44

compile

    cd src/mountain/
    make

run

    ./mountain

below result is my ubuntu vm

    Clock frequency is approx. 2195.1 MHz
    Memory mountain (MB/sec)
            s1      s2      s3      s4      s5      s6      s7      s8      s9      s10     s11     s12     s13     s14     s15
    128m    12705   6982    4866    3695    3159    2663    2298    2112    1934    1609    1792    1692    1658    1642    1630
    64m     17221   9313    5838    4856    3654    3056    2716    2569    2305    2242    2068    2022    1985    1918    1894
    32m     17329   9171    6219    4796    3915    3307    2746    2487    2386    2248    2137    2039    2044    2040    2018
    16m     15995   9043    6137    5378    4417    2935    2905    2563    2391    2257    2146    2358    2457    2353    2540
    8m      19409   11099   7505    5772    5923    5061    4455    3932    3730    3554    3423    3441    3211    3381    3724
    4m      23115   18919   13244   10285   8383    7086    6127    5385    5326    5176    5053    4973    4607    4565    4541
    2m      27020   19975   13553   10641   8641    7314    6351    5600    5338    5155    5007    4890    4816    4747    4731
    1024k   26986   19695   13522   10570   8623    7279    6343    5585    5342    5150    5000    4867    4801    4755    4725
    512k    26233   20178   13582   10590   8598    7315    6333    5595    5338    5149    4834    4703    4667    4642    4667
    256k    26047   21561   17393   14697   12038   10248   8668    7783    7788    8005    8120    8665    9015    8827    9239
    128k    26474   23849   23715   21293   17837   14901   12925   11512   11288   11345   10404   11069   10934   10827   10527
    64k     26454   24121   24048   22366   18928   15898   13520   12085   11909   12027   11759   11940   12405   11392   19897
    32k     28031   27246   27121   26213   25871   25724   25560   24040   22829   24797   25142   22529   22486   24229   23733
    16k     27966   27000   26404   25543   25321   24763   24695   20813   21712   22757   20687   19456   20337   18884   20664


## 6.45

see [transpose.c](https://github.com/ejunjsh/csapp/blob/master/chapter06/src/transpose.c)

compile

    gcc src/transpose.c -o bin/transpose

run

    date +%s;bin/transpose;date +%s

you can adjust the `BLOCK` in the code to find which value make the code faster. 

In my machine, the `BLOCK` 8 is the best value.

## 6.46

see [convert.c](https://github.com/ejunjsh/csapp/blob/master/chapter06/src/convert.c)

compile

    gcc src/convert.c -o bin/convert

run

    date +%s;bin/convert;date +%s

you can adjust the `BLOCK` in the code to find which value make the code faster. 

In my machine, the `BLOCK` 16 is the best value.

the original code in book run during 13 seconds.
after i optimize the code, the result of running is during 4 seconds