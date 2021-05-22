#include <stdio.h>
#include <dlfcn.h>
#ifdef __unix__
  #include <malloc.h>
#endif

//#include "calc.h"

void Pause() {
 printf("\nPress Enter for continue.");
 getchar();
}

int Getint() {
 char i_[11];
 int i = 0;
 fgets(i_, 11, stdin);
 sscanf(i_, "%d", &i);
 return i;
}

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    char *error;
    void * handle = dlopen(argv[i], RTLD_LAZY);
    if (!handle) {
      fputs(dlerror(), stderr);
      return 1;
    }
    char * funcName = dlsym(handle, "fn");
    if ((error = dlerror()) != NULL) {
      fprintf(stderr, "%s\n", error);
      return 1;
    }
    printf("%s\n", funcName);
    //int (* sum)(int, int) = dlsym(handle, funcName);
    //printf("%d\n", sum(2, 3));
    Pause();
    dlclose(handle);
  }


  /*
    int a, b, r, key;
    while (1) {
    system("clear");
    printf("|::| Calc\n");
    a = 0;
    b = a;
    printf("a = ");
    a = Getint();
    printf("b = ");
    b = Getint();
    printf("Function list:\n");
    printf("1 +\n");
    printf("2 -\n");
    printf("3 *\n");
    printf("4 /\n");
    printf("5 Quit\n");
    printf("Please, type key of function and press Enter: ");
    key = Getint();
    switch (key) {
     case 1:
      r = sum(a, b);
      break;
     case 2:
      r = sub(a, b);
      break;
     case 3:
      r = mul(a, b);
      break;
     case 4:
      r = div(a, b);
      break;
     case 5:
      return 0;
    }
    printf("result = %d\n", r);
    Pause();
    }
   */
   return 0;
}
