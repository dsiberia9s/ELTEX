#include <stdio.h>
#include <string.h>

#ifdef __APPLE__
#include <stdlib.h>
#else
#include <malloc.h>
#endif

#define FILED_SIZE 64
#define PB_SIZE 256

struct contact
{
  char name[FILED_SIZE];
  char surname[FILED_SIZE];
  char phone[FILED_SIZE];
  unsigned char property; // & 0b00010000 init, & 0b00010001 used, & 0b00010000 empty
};

struct contact * phonebook_data = NULL;

char pause() {
  printf("Press Enter for continue.");
  return getchar();
}

int main (void) {
  char name[32];
  fgets(name, 32, stdin);
  //pause();
  //sscanf((const char *)stdin, "%s", name);
  printf("%s\n", name);
  return 0;
}

/*
phonebook_data = (struct contact *)malloc(sizeof(struct contact));
phonebook_data->name[0] = 'a';
printf("%c\n", (phonebook_data + 0)->name[0]);

phonebook_data = (struct contact *)realloc(phonebook_data, sizeof(struct contact) * 2);
(phonebook_data + 1)->name[0] = 'b';
printf("%c %c\n", (phonebook_data + 0)->name[0], (phonebook_data + 1)->name[0]);
*/
