#include <stdio.h>

#define LEN 7
#define MAX 9999999

int pow4[] = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561};
int pow5[] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};

void getDigits(int num, int* digits) {
  int i;

  for (i = 0; i < LEN; i++) {
    digits[i] = num % 10;
    num = (num - digits[i]) / 10;
  }
}

int digitSum(int num) {
  int digits[LEN];
  int i, sum = 0;

  getDigits(num, digits);

  for (i = 0; i < LEN; i++) {
    sum += pow5[digits[i]];
  }

  return sum;
}

void printDigits(int *digits) {
  int i;

  for (i = 0; i < LEN; i++) {
    printf("%d\n", digits[i]);
  }
}

int main() {
  int i, sum = 0;
  
  for (i = 2; i <= MAX; i++) {
    if (i == digitSum(i)) {
      printf("%d\n", i);
      sum += i;
    }
  }

  printf("sum = %d\n", sum);

  return 0;
}
