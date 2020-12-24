#include <stdio.h>
#include <stdlib.h>

#define s 5

int m[s];

void helix() {
  /*
    int s = 5;
    5 4 4 3 3 2 2 1 1
    → ↓ ← ↑ → ↓ ← ↑ →
  */
  int S = s * s;
  int x = 0;
  int n = 1;
  int d = 0;

  for (int i = s; i > 0; i--) {
    int J;
    if (i == s) {
      J = 1;
    } else {
      J = 2;
    }
    for (int j = 0; j < J; j++) {
      for (int t = 0; t < i; t++) {
        if (d == 0) {
          x = x + 1;
        } else if (d == 1) {
          x = x + s;
        } else if (d == 2) {
          x = x - 1;
        } else {
          x = x - s;
        }
        m[x - 1] = n;
        n++;
      }
      d++;
      if (d > 3) {
        d = 0;
      }
    }
  }

  printf("\n");
  for (int i = 0; i < S; i++) {
    printf("%2d ", m[i]);
    if (i % s == s - 1) {
      printf("\n");
    }
  }
}

int main (void)
{
  helix();
  return 0;
}
