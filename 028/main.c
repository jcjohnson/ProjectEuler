#include <stdio.h>
#include <stdlib.h>

int getIndex(int i, int j, int size) {
  return i * size + j;
}

int drawBox(int *spiral, int size, int n, int val) {
  int y = size / 2 - n;
  int x = size / 2 + n;
  int i;
  
  // Move down
  for (i = 0; i < 2 * n; i++) {
    y++;
    spiral[getIndex(y, x, size)] = val;
    val++;
  }

  // Move left
  for (i = 0; i < 2 * n; i++) {
    x--;
    spiral[getIndex(y, x, size)] = val;
    val++;
  }

  // Move up
  for (i = 0; i < 2 * n; i++) {
    y--;
    spiral[getIndex(y, x, size)] = val;
    val++;
  }

  // Move right
  for (i = 0; i < 2 * n; i++) {
    x++;
    spiral[getIndex(y, x, size)] = val;
    val++;
  }

  return val;
}

int * makeSpiral(int size) {
  int i, j, val;

  int *spiral = malloc(size * size * sizeof(int));

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      spiral[getIndex(i, j, size)] = 0;
    }
  }

  spiral[getIndex(size / 2, size / 2, size)] = 1;

  val = 2;
  for (i = 1; 2 * i < size; i++) {
    val = drawBox(spiral, size, i, val);
  }

  return spiral;
}

int printSpiral(int *spiral, int size) {
  int i, j;

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%d\t", spiral[getIndex(i, j, size)]);
    }
    printf("\n");
  }
}

int diagonalSum(int *spiral, int size) {
  int i, sum = 0;

  for (i = 0; i < size; i++) {
    sum += spiral[getIndex(i, i, size)];
    if (size - i - 1 != i) {
      sum += spiral[getIndex(i, size - i - 1, size)];
    }
  }

  return sum;
}

int main() {
  int size = 1001;
  int *spiral = makeSpiral(size);

  // printSpiral(spiral, size);
  printf("%d\n", diagonalSum(spiral, size));

  free(spiral);
  return 0;
}
