#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILED_SIZE 64
#define PB_SIZE 256

struct contact
{
  char name[FILED_SIZE];
  char surname[FILED_SIZE];
  char phone[FILED_SIZE];
  unsigned char property; // & 0b00010000 init, & 0b00010001 used, & 0b00010000 empty
};

struct contact phonebook_data[PB_SIZE];

void phonebook(unsigned char action) {
  int field = FILED_SIZE;
  int size = PB_SIZE;
  int space;
  unsigned char init;
  char trash;
  int key;

  while (1) {
    space = size;
    init = 1;

    for (int i = 0; i < size; i++) {
      if (!(phonebook_data[i].property & 0b00010000)) {
        init = 0;
        break;
      } else {
        if (phonebook_data[i].property & 0b00000001) {
          space--;
        }
      }
    }

    if (!init) {
      for (int i = 0; i < size; i++) {
        phonebook_data[i].property = 0b00010000;
      }
      init = 1;
    }

    if (action == 1) {
      system("clear");
      if (!space) {
        printf("⚠️ Not enough free space in phonebook_data array.\n");
        printf("Please, remove one contact. Type any key.\n");
        scanf("%c", &trash);
        fseek(stdin, 0, SEEK_END);
        return;
      }
      int i = 0;
      for (; i != size; i++) {
        if (!(phonebook_data[i].property & 0b00000001)) {
          break;
        }
      }
      printf("📕 PHONE BOOK. Add new contact.\n");
      printf("Help: type * and press Enter for exit.\n");
      printf("Assidned ID #%d.\n", i);
      printf("Type NAME and press Enter: ");
      scanf("%s", phonebook_data[i].name);
      fseek(stdin, 0, SEEK_END);
      if (phonebook_data[i].name[0] == '*') {
        return;
      }
      printf("Type SURNAME and press Enter: ");
      scanf("%s", phonebook_data[i].surname);
      fseek(stdin, 0, SEEK_END);
      if (phonebook_data[i].surname[0] == '*') {
        return;
      }
      printf("Type PHONE and press Enter: ");
      scanf("%s", phonebook_data[i].phone);
      fseek(stdin, 0, SEEK_END);
      if (phonebook_data[i].phone[0] == '*') {
        return;
      }
      phonebook_data[i].property |= 0b00000001;
      printf("Contact succefull added: %s. %s. %s.\n", phonebook_data[i].name, phonebook_data[i].surname, phonebook_data[i].phone);
      printf("Press Enter for back to menu.");
      scanf("%c", &trash);
      fseek(stdin, 0, SEEK_END);
      return;
    } else if (action == 2) {
      while (1) {
        char * input = (char *)malloc(sizeof(char) * field);
        system("clear");
        printf("📕 PHONE BOOK. Search ID of contact.\n");
        printf("Help: type * and press Enter for exit.\n");
        printf("Type Search query and press Enter: ");
        scanf("%s", input);
        fseek(stdin, 0, SEEK_END);
        if (input[0] == '*') {
          free(input);
          return;
        }
        for (int i = 0; i < size; i++) {
          if (phonebook_data[i].property & 0b00000001) {
            if (!strcmp(input, phonebook_data[i].name) || !strcmp(input, phonebook_data[i].surname) || !strcmp(input, phonebook_data[i].phone)) {
              printf("Found #%d: %s. %s. %s.\n", i, phonebook_data[i].name, phonebook_data[i].surname, phonebook_data[i].phone);
              printf("Press Enter for back to menu.");
              scanf("%c", &trash);
              fseek(stdin, 0, SEEK_END);
              free(input);
              return;
            }
          }
        }
        printf("Not Found.\n");
        printf("Press Enter to continue.");
        scanf("%c", &trash);
        fseek(stdin, 0, SEEK_END);
      }
    } else if (action == 3) {
      char * input = (char *)malloc(sizeof(char) * field);
      int id;
      int opt;
      system("clear");
      printf("📕 PHONE BOOK. Edit the contact.\n");
      printf("Type ID of contact for edit and press Enter: ");
      scanf("%d", &id);
      fseek(stdin, 0, SEEK_END);
      if ((-1 < id) && (id < size) && ((phonebook_data[id].property & 0b00000001))) {
        printf("Which filed do you wanna chage?\n");
        printf("1 - name;\n");
        printf("2 - surname;\n");
        printf("3 - phone.\n");
        printf("Type field number and press Enter: ");
        scanf("%d", &opt);
        fseek(stdin, 0, SEEK_END);
        if (opt == 1) {
          printf("Type new value instead <%s>: ", phonebook_data[id].name);
          scanf("%s", input);
          fseek(stdin, 0, SEEK_END);
          if (input[0] == '*') {
            free(input);
            return;
          }
          strcpy(phonebook_data[id].name, input);
          printf("Field of contact succefull changed: %s. %s. %s.\n", phonebook_data[id].name, phonebook_data[id].surname, phonebook_data[id].phone);
          printf("Press Enter for back to menu.");
          scanf("%c", &trash);
          fseek(stdin, 0, SEEK_END);
          free(input);
          return;
        } else if (opt == 2) {
          printf("Type new value instead <%s>: ", phonebook_data[id].surname);
          scanf("%s", input);
          fseek(stdin, 0, SEEK_END);
          if (input[0] == '*') {
            free(input);
            return;
          }
          strcpy(phonebook_data[id].surname, input);
          printf("Field of contact succefull changed: %s. %s. %s.\n", phonebook_data[id].name, phonebook_data[id].surname, phonebook_data[id].phone);
          printf("Press Enter for back to menu.");
          scanf("%c", &trash);
          fseek(stdin, 0, SEEK_END);
          free(input);
          return;
        } else if (opt == 3) {
          printf("Type new value instead <%s>: ", phonebook_data[id].phone);
          scanf("%s", input);
          fseek(stdin, 0, SEEK_END);
          if (input[0] == '*') {
            free(input);
            return;
          }
          strcpy(phonebook_data[id].phone, input);
          printf("Field of contact succefull changed: %s. %s. %s.\n", phonebook_data[id].name, phonebook_data[id].surname, phonebook_data[id].phone);
          printf("Press Enter for back to menu.");
          scanf("%c", &trash);
          fseek(stdin, 0, SEEK_END);
          free(input);
          return;
        }
      }
      printf("⚠️ Incorrect ID or contact slot is empty. Use value from 0 to %d.\n", (size - 1));
      printf("Press Enter to continue.");
      scanf("%c", &trash);
      fseek(stdin, 0, SEEK_END);
      free(input);
      return;
    } else if (action == 4) {
      int id;
      char opt;
      system("clear");
      printf("📕 PHONE BOOK. Remove the contact.\n");
      printf("Type ID of contact for edit and press Enter: ");
      scanf("%d", &id);
      fseek(stdin, 0, SEEK_END);
      if ((-1 < id) && (id < size) && ((phonebook_data[id].property & 0b00000001))) {
        printf("Are you really wanna to remove the contact: %s. %s. %s?\n", phonebook_data[id].name, phonebook_data[id].surname, phonebook_data[id].phone);
        printf("Type y for remove or any char for cancel: ");
        scanf("%c", &opt);
        fseek(stdin, 0, SEEK_END);
        if (opt == 'y') {
          phonebook_data[id].property = 0b00000000 & 0b00000001;
          printf("Contact succefull removed.\n");
        } else {
          printf("Remove operation canceled.\n");
        }
      }
      printf("Press Enter for back to menu.");
      scanf("%c", &trash);
      fseek(stdin, 0, SEEK_END);
      return;
    } else if (action == 5) {
      system("clear");
      printf("📕 PHONE BOOK. Watch all.\n");
      printf("#\tName\tSurname\tPhone\n");
      for (int i = 0; i < size; i++) {
        if (phonebook_data[i].property & 0b00000001) {
          printf("%d\t%s\t%s\t%s\n", i, phonebook_data[i].name, phonebook_data[i].surname, phonebook_data[i].phone);
        }
      }
      printf("Press Enter for back to menu.");
      scanf("%c", &trash);
      fseek(stdin, 0, SEEK_END);
      return;
    }

    while (1) {
      system("clear");
      printf("📕 HELLO! I'AM PHONE BOOK [%d/%d]:\n", (size - space), size);
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
