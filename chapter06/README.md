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

