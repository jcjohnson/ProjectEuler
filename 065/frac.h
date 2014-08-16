#ifndef FRAC_H
#define FRAC_H

#include <stdio.h>

typedef struct _frac {
  long num;
  long den;
} frac;

long gcd(long a, long b);

void frac_reduce(frac *f);

void frac_add(frac *f1, frac *f2, frac *result);

void frac_add_long(frac *f, long n, frac *result);

void frac_multiply(frac *f1, frac *f2, frac *result);

void frac_multiply_long(frac *f, long n, frac *result);

void frac_inverse(frac *f, frac *result);

void frac_print(frac *f);

#endif
