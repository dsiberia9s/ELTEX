#include <stdio.h>
#include <stdlib.h>

#define s 3

int m[s];

void matrix() {
  int S = s * s;
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
  matrix();
  return 0;
}
