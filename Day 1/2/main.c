#include <stdio.h>
#include <stdlib.h>

#define s 6

int m[s];

void back() {
  for (int i = 0; i < s; i++) {
    m[i] = i + 1;
  }

  printf("Input-> ");
  for (int i = 0; i < s; i++) {
    printf("%d ", m[i]);
  }

  printf("\n");

  printf("Output-> ");
  for (int i = s - 1; i > -1; i--) {
    printf("%d ", m[i]);
  }
}

int main (void)
{
  back();
  return 0;
}
