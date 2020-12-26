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

int main (void) {
  phonebook_data = (struct contact *)malloc(sizeof(struct contact));
  phonebook_data->name[0] = 'a';
  printf("%c\n", (phonebook_data + 0)->name[0]);

  phonebook_data = (struct contact *)realloc(phonebook_data, sizeof(struct contact) * 2);
  (phonebook_data + 1)->name[0] = 'b';
  printf("%c %c\n", (phonebook_data + 0)->name[0], (phonebook_data + 1)->name[0]);

  return 0;
}

/*
struct contact * p = (struct contact *)malloc(sizeof(struct contact) * 3);
p->name[0] = 'a';
p++;
p->name[0] = 'b';
p++;
p->name[0] = 'c';
p -= 2;
for (int i = 0; i < 3; i++) {
  printf("%c\n", (p + i)->name[0]);
}

(p + 1)->name[0] = (p + 2)->name[0];
p = realloc(p, sizeof(struct contact) * 2);
printf("%c\n", (p + 1)->name[0]);
*/
