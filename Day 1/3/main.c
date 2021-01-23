#include <stdio.h>
#include <math.h>

void invert() {
  int m[] = {0, 0, 1, 0, 1, 1, 1, 1, 1};
  int S = sizeof(m) / sizeof(m[0]);
  int s = sqrt(S);
  for (int i = 0; i < S; i++) {
    m[i] = (m[i]) ? 0 : 1;
  }

  for (int i = 0; i < S; i++) {
    printf("%d", m[i]);
    if (i % s == s - 1) {
      printf("\n");
    }
  }
}

int main (void)
{
  invert();
  return 0;
}
