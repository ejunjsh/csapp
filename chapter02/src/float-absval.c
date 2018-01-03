/*
 * float-absval.c
 */
#include <stdio.h>
#include <assert.h>
#include "./lib/floats.h"
#include <math.h>
#include "./lib/random.h"

float_bits float_absval(float_bits f) {
  unsigned sig = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  int is_NAN = (exp == 0xFF) && (frac != 0);
  if (is_NAN) {
    return f;
  }

  return 0 << 31 | exp << 23 | frac;
}

int main(int argc, char* argv[]) {
   init_seed();
   unsigned r = random_int();
   float f = u2f(r);
   printf("r:\t0x%.8X\t%d\n", r, r);
   if (isnan(f)) {
      assert(float_absval(r) == r);
    } else {
      assert(u2f(float_absval(r)) == fabsf(f));
    }
}