/*
 * 8.12.c
 */
#include <stdio.h>
#include "csapp.h"

void doit() {
  Fork();
  Fork();
  printf("hello\n"); 
  return;
}

int main(int argc, char* argv[]) {
  doit();
  printf("hello\n");
  return 0;
}