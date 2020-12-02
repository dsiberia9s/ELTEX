#include <stdio.h>
#include <stdlib.h>

void matrix(int s) {
  int S = s * s;
  int * m = (int*)malloc(sizeof(int) * S);
  for (int i = 0; i < S; i++) {
    m[i] = i + 1;
  }

  for (int i = 0; i < S; i++) {
    printf("%d ", m[i]);
    if (i % s == s - 1) {
      printf("\n");
    }
  }
}

int main (void)
{
  matrix(3);
  return 0;
}