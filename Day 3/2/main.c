#include <stdio.h>

struct contact
{
  char name[32];
  char surname[32];
  char phone[16];
  char empty;
  char init;
};

struct contact phonebook_data[127];

void phonebook(int action) {
  int size = sizeof(phonebook_data) / sizeof(phonebook_data[0]);
  printf("\n");
  if (action == 0) { // menu
      while (1) {
      printf("Hello! I'am phonebook.\n1 - create new contact;\n2 - edit;\n3 - search;\n4 - remove;\n0 - exit.\n> ");
      char k[3];
      fgets(k, 3, stdin);
      switch (k[0]) {
        case '1':
          phonebook(1);
          break;
        case '2':
          phonebook(2);
          break;
        case '3':
          phonebook(3);
          break;
        case '4':
          phonebook(4);
          break;
        case '0':
          return;
      }
    }
  } else if (action == 1) { // add
    int init = 0;
    for (int i = 0; i < size; i++) {
      if (phonebook_data[i].init == 1) {
        init++;
      }
    }
    if (init != size) {
      printf("!!!");
      for (int i = 0; i < size; i++) {
        phonebook_data[i].init = 1;
      }
    } else {
      printf("*");
    }
  } else if (action == 2) { // edit
    
  } else if (action == 3) { //search

  } else if (action == 4) { // remove

  }
}

int main (void) {
  phonebook(0);
  return 0;
}