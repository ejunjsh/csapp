/*
 * transpose.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LOOP 1000
#define MAX  1024
#define LEN  MAX*MAX
#define BLOCK 8

void transpose(int* dst, int* src, int N) {
  int i, j;

  for (i = 0; i <= N-1; i++)
    for (j = 0; j <= N-1; j++)
      dst[j*N+i] = src[i*N+j];
}

void effective_transpose(int* dst, int* src, int N) {
  int i, j, a, b;

  for (i = 0; i <= N-BLOCK; i+=BLOCK)
    for (j = 0; j <= N-BLOCK; j+=BLOCK)
      for (a = i; a < i+BLOCK; a++)
        for (b = j; b < j+BLOCK; b++)
          dst[b*N+a] = src[a*N+b];

  for (; i <= N-1; i++)
    for (; j <= N-1; j++)
      dst[j*N+i] = src[i*N+j];
}


void prof(void) {
  int* d = (int*)malloc(sizeof(int)*LEN);
  int* s = (int*)malloc(sizeof(int)*LEN);

  for (int c = 0; c < LOOP; c++)
    transpose(d, s, MAX);

  free((void*)d);
  free((void*)s);
}

void prof_effect(void) {
  int* d = (int*)malloc(sizeof(int)*LEN);
  int* s = (int*)malloc(sizeof(int)*LEN);

  for (int c = 0; c < LOOP; c++)
    effective_transpose(d, s, MAX);

  free((void*)d);
  free((void*)s);
}

int main(int argc, char* argv[]) {
    
  /*prof();*/

  prof_effect();

  return 0;
}