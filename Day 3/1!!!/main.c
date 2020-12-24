#include <stdio.h>

void watch() {
  struct main
  {
    char a; // 1 byte
    int b; // 4 bytes
  };
  
  struct main strct;
  struct main * ptr_strct;
  ptr_strct = &strct;
  ptr_strct->a = 'C';
  ptr_strct->b = 3;

  char str[50] = {'A', 0, 0, 0, 0, 'B', 0, 0, 0, 0};
  printf("%d", );
  /*
  for (int i = 0; i < 50; i++) {
    printf("%d ", str[i]);
  }
  */
}

int main (void)
{
  watch();
  return 0;
}