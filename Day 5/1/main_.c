#include <stdio.h>
#include <string.h>

#ifdef __APPLE__
#include <stdlib.h>
#else
#include <malloc.h>
#endif

#define FILED_SIZE 64

struct contact
{
  char name[FILED_SIZE];
  char surname[FILED_SIZE];
  char phone[FILED_SIZE];
};

struct contact * phonebook_data = NULL;
size_t phonebook_data_size = 0;

void Add() {
  if (phonebook_data_size == 0) {
    phonebook_data = (struct contact *)malloc(sizeof(struct contact));
  } else {
    phonebook_data = (struct contact *)realloc(phonebook_data, sizeof(struct contact) * (phonebook_data_size + 1));
  }
  if (phonebook_data == NULL) {
    perror("Allocate error.");
    exit(EXIT_FAILURE);
  }
  phonebook_data_size++;
}

int Remove(size_t id) {
  if ((!phonebook_data_size) || (id < 0) || (id >= phonebook_data_size)) {
    return 0;
  }
  if (id == 0) {
    if (phonebook_data_size > 1) {
      for (size_t i = 0; i < phonebook_data_size; i++) {
        strcpy((phonebook_data + id + i)->name, (phonebook_data + id + 1 + i)->name);
        strcpy((phonebook_data + id + i)->surname, (phonebook_data + id + 1 + i)->surname);
        strcpy((phonebook_data + id + i)->phone, (phonebook_data + id + 1 + i)->phone);
      }
    } else {
      free(phonebook_data);
      phonebook_data_size = 0;
      return 1;
    }
  } else if (id < (phonebook_data_size - 1)) {
    for (size_t i = 0; i < phonebook_data_size; i++) {
      strcpy((phonebook_data + id - 1)->name, (phonebook_data + id + 1)->name);
      strcpy((phonebook_data + id - 1)->surname, (phonebook_data + id + 1)->surname);
      strcpy((phonebook_data + id - 1)->phone, (phonebook_data + id + 1)->phone);
    }
  }
  struct contact * phonebook_data_tmp = NULL;
  phonebook_data = realloc(phonebook_data, sizeof(struct contact) * (phonebook_data_size - 1));
  if (phonebook_data == NULL) {
    perror("Allocate error.");
    exit(EXIT_FAILURE);
  }
  phonebook_data_size--;
  return 1;
}

void Watch() {
  printf("#\tName\tSurname\tPhone\n");
  for (size_t i = 0; i < phonebook_data_size; i++) {
    printf("%zu\t%s\t%s\t%s\n", i, (phonebook_data + i)->name, (phonebook_data + i)->surname, (phonebook_data + i)->phone);
  }
}

void phonebook(unsigned char action) {
  int field = FILED_SIZE;
  char trash;
  int key;

  while (1) {
    if (action == 1) {
      system("clear");
      printf("📕 PHONE BOOK. Add new contact.\n");
      printf("Help: type * and press Enter for exit.\n");
      printf("Assidned ID #%zu.\n", phonebook_data_size);
      Add();
      printf("Type NAME and press Enter: ");
      scanf("%s", (phonebook_data + phonebook_data_size - 1)->name);
      fseek(stdin, 0, SEEK_END);
      if ((phonebook_data + phonebook_data_size - 1)->name[0] == '*') {
        return;
      }
      printf("Type SURNAME and press Enter: ");
      scanf("%s", (phonebook_data + phonebook_data_size - 1)->surname);
      fseek(stdin, 0, SEEK_END);
      if ((phonebook_data + phonebook_data_size - 1)->surname[0] == '*') {
        return;
      }
      printf("Type PHONE and press Enter: ");
      scanf("%s", (phonebook_data + phonebook_data_size - 1)->phone);
      fseek(stdin, 0, SEEK_END);
      if ((phonebook_data + phonebook_data_size - 1)->phone[0] == '*') {
        return;
      }
      printf("Contact succefull added: %s. %s. %s.\n", (phonebook_data + phonebook_data_size - 1)->name, (phonebook_data + phonebook_data_size - 1)->surname, (phonebook_data + phonebook_data_size - 1)->phone);
      printf("Press Enter for back to menu.");
      scanf("%c", &trash);
      fseek(stdin, 0, SEEK_END);
      return;
    } else if (action == 4) {
      size_t id;
      char opt;
      system("clear");
      printf("📕 PHONE BOOK. Remove the contact.\n");
      printf("Type ID of contact for edit and press Enter: ");
      scanf("%zu", &id);
      fseek(stdin, 0, SEEK_END);
      printf("Type y for remove or any char for cancel: ");
      scanf("%c", &opt);
      fseek(stdin, 0, SEEK_END);
      if (opt == 'y') {
        if (Remove(id)) {
          printf("Contact succefull removed.\n");
        } else {
          printf("Contact NOT removed.\n");
        }
      } else {
        printf("Remove operation canceled.\n");
      }
      printf("Press Enter for back to menu.");
      scanf("%c", &trash);
      fseek(stdin, 0, SEEK_END);
      return;
    } else if (action == 5) {
      system("clear");
      printf("📕 PHONE BOOK. Watch all.\n");
      Watch();
      printf("Press Enter for back to menu.");
      scanf("%c", &trash);
      fseek(stdin, 0, SEEK_END);
      return;
    }

    while (1) {
      system("clear");
      printf("📕 HELLO! I'AM PHONE BOOK [%zu]:\n", phonebook_data_size);
      printf("1 - Add new contact;\n");
      printf("2 - Search;\n");
      printf("3 - Edit;\n");
      printf("4 - Remove.\n");
      printf("5 - Watch all.\n");
      printf("0 - Quit.\n");
      printf("Please, type menu key and press Enter: ");
      scanf("%d", &key);
      fseek(stdin, 0, SEEK_END); // fix: scanf + while
      switch (key) {
        case 1:
          phonebook(1);
          key = -1;
          break;
        case 2:
          phonebook(2);
          key = -1;
          break;
        case 3:
          phonebook(3);
          key = -1;
          break;
        case 4:
          phonebook(4);
          key = -1;
          break;
        case 5:
          phonebook(5);
          key = -1;
          break;
        case 0:
          return;
      }
      if (key == -1) {
        break;
      }
    }
  }
}

int main (void) {
  phonebook(0);
  return 0;
}
