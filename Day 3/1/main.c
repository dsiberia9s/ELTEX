#include <stdio.h>

struct oct
{
  char a; // 1 byte + 3 bytes for padding = 4 bytes
  int b; // 4 bytes
};

void watch() {
  // char a[8] = {'A', 0, 0, 0, 0b1111000, 0b11, 0, 0};
  char a[8] = {'A', 0, 0, 0, 'B', 0, 0, 0};
  char * ap = a;
  for (int i = 0; i < 8; i++) {
    printf("%02x ", a[i]);
  }
  printf("\n");

  struct oct s;
  struct oct * sp = &s;

  sp = (struct oct *)ap;

  printf("a = %c; b = %d\n", sp->a, sp->b);
}

int main (void)
{
  watch();
  return 0;
}
