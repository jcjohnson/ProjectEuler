#include "frac.h"

long gcd(long a, long b) {
  return b == 0 ? a : gcd(b, a % b);
}

void frac_reduce(frac *f) {
  long g = gcd(f->num, f->den);
  f->num /= g;
  f->den /= g;
}

void frac_add(frac *f1, frac *f2, frac *result) {
  long num = f1->num * f2->den + f1->den * f2->num;
  long den = f1->den * f2->den;
  result->num = num;
  result->den = den;
  frac_reduce(result);
}

void frac_add_long(frac *f, long n, frac *result) {
  result->num = f->num + n * f->den;
  result->den = f->den;
  frac_reduce(result);
}

void frac_multiply(frac *f1, frac *f2, frac *result) {
  long num = f1->num * f2->num;
  long den = f1->den * f2->den;
  result->num = num;
  result->den = den;
  frac_reduce(result);
}

void frac_multiply_long(frac *f, long n, frac *result) {
  result->num = f->num * n;
  result->den = f->den;
  frac_reduce(result);
}

void frac_inverse(frac *f, frac *result) {
  long num = f->den;
  long den = f->num;
  result->num = num;
  result->den = den;
}

void frac_print(frac *f) {
  printf("%ld / %ld\n", f->num, f->den);
}
