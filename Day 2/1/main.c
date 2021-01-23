#include <stdio.h>

void pointer(int a) {
  char * p;
  p = (char*)&a;
  printf("%d => ", a);
  for (int i = 0; i < sizeof(a); i++) {
    printf("%d ", *p);
    p++;
  }
  printf("\n");
}

int main (void)
{
  pointer(270533154);
  return 0;
}