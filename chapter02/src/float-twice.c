/*
 * float-twice.c
 */
#include <stdio.h>
#include <assert.h>
#include "./lib/floats.h"
#include <math.h>
#include "./lib/random.h"

float_bits float_twice(float_bits f) {
  unsigned sig = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  int is_NAN_or_oo = (exp == 0xFF);
  if (is_NAN_or_oo) {
    return f;
  }

  if (exp == 0) {
    /* Denormalized */
    frac <<= 1;
  } else if (exp == 0xFF - 1) {
    /* twice to oo */
    exp = 0xFF;
    frac = 0;
  } else {
    /* Normalized */
    exp += 1;
  }

  return sig << 31 | exp << 23 | frac;
}

int main(int argc, char* argv[]) {
   init_seed();
   unsigned r = random_int();
   float f = u2f(r);
   float fmul2 = f * 2.0;
   printf("r:\t0x%.8X\t%d\n", r, r);
   if (isnan(f)) {
      assert(float_twice(r) == r);
    } else {
      assert(u2f(float_twice(r)) == fmul2);
    }
}
