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
  char property; // & 0b00010000 init, & 0b00010001 used, & 0b00010000 empty
};

struct contact phonebook_data[PB_SIZE];

void Pause() {
  printf("\nPress Enter for continue.");
  getchar();
}

char Getchar() {
  char c = getchar();
  getchar();
  return c;
}

void phonebook(unsigned char action) {
  size_t field = FILED_SIZE;
  size_t phonebook_data_size = PB_SIZE;
  size_t space;
  char init;
  int key;

  while (1) {
    space = phonebook_data_size;
    init = 1;

    for (size_t i = 0; i < phonebook_data_size; i++) {
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
      for (size_t i = 0; i < phonebook_data_size; i++) {
        phonebook_data[i].property = 0b00010000;
      }
      init = 1;
    }

    if (action == 1) {
      system("clear");
      if (!space) {
        printf("/!\\ Not enough free space in phonebook_data array.\n");
        printf("Please, remove one contact. Type any key.\n");
        Pause();
        return;
      }
      size_t i = 0;
      for (; i != phonebook_data_size; i++) {
        if (!(phonebook_data[i].property & 0b00000001)) {
          break;
        }
      }
      printf("|J| PHONE BOOK. Add new contact.\n");
      printf("Help: type * and press Enter for exit.\n");
      printf("Assidned ID #%zu.\n", i);
      printf("Type NAME and press Enter: ");
      fgets(phonebook_data[i].name, FILED_SIZE, stdin);
      sscanf(phonebook_data[i].name, "%s", phonebook_data[i].name);
      printf("Type SURNAME and press Enter: ");
      fgets(phonebook_data[i].surname, FILED_SIZE, stdin);
      sscanf(phonebook_data[i].surname, "%s", phonebook_data[i].surname);
      printf("Type PHONE and press Enter: ");
      fgets(phonebook_data[i].phone, FILED_SIZE, stdin);
      sscanf(phonebook_data[i].phone, "%s", phonebook_data[i].phone);
      phonebook_data[i].property |= 0b00000001;
      printf("Contact succefull added: %s. %s. %s.\n", phonebook_data[i].name, phonebook_data[i].surname, phonebook_data[i].phone);
      Pause();
      return;
    } else if (action == 2) {
      if (phonebook_data_size == space) {
        return;
      }
      char query[FILED_SIZE];
      system("clear");
      printf("[J] PHONE BOOK. Search # of contact.\n");
      printf("Type SEARCH QUERY and press Enter: ");
      fgets(query, FILED_SIZE, stdin);
      sscanf(query, "%s", query);
      for (int i = 0; i < phonebook_data_size; i++) {
        if (phonebook_data[i].property & 0b00000001) {
          if (!strcmp(query, phonebook_data[i].name) || !strcmp(query, phonebook_data[i].surname) || !strcmp(query, phonebook_data[i].phone)) {
            printf("Contact found at #%d %s %s. Phone: %s.\n", i, phonebook_data[i].name, phonebook_data[i].surname, phonebook_data[i].phone);
            Pause();
            return;
          }
        }
      }
      printf("Not found by query: %s\n", query);
      Pause();
      return;
    } else if (action == 3) {
      if (phonebook_data_size == space) {
        return;
      }
      char id_[10];
      size_t id;
      char key;
      char field[FILED_SIZE];
      system("clear");
      printf("[J] PHONE BOOK. Contact edit.\n");
      printf("Type # of contact for edit and press Enter: ");
      fgets(id_, 10, stdin);
      sscanf(id_, "%zu", &id);
      if (id >= phonebook_data_size) {
        printf("Edit operation canceled. Incorrect #.\n");
        Pause();
        return;
      }
      if ((id < phonebook_data_size) && ((phonebook_data[id].property & 0b00000001))) {
        printf("Type key of filed <1> NAME, <2> SURNAME, <3> PHONE and press Enter: ");
        key = Getchar();
        printf("Type NEW VALUE and press Enter: ");
        fgets(field, FILED_SIZE, stdin);
        sscanf(field, "%s", field);
        switch (key) {
          case '1':
            strcpy((phonebook_data + id)->name, field);
            break;
          case '2':
            strcpy((phonebook_data + id)->surname, field);
            break;
          case '3':
            strcpy((phonebook_data + id)->phone, field);
            break;
          }
        Pause();
      }
      return;
    } else if (action == 4) {
      char id_[10];
      size_t id;
      char opt;
      system("clear");
      printf("|J| PHONE BOOK. Remove the contact.\n");
      printf("Type # of contact for edit and press Enter: ");
      fgets(id_, 10, stdin);
      sscanf(id_, "%zu", &id);
      if ((id < phonebook_data_size) && ((phonebook_data[id].property & 0b00000001))) {
        printf("Type <y> for remove or any char for cancel: ");
        opt = Getchar();
        if (opt == 'y') {
          phonebook_data[id].property = 0b00000000 & 0b00000001;
          printf("Contact succefull removed.\n");
        } else {
          printf("Remove operation canceled.\n");
        }
      } else {
        printf("Remove operation canceled. Incorrect #.\n");
      }
      Pause();
      return;
    } else if (action == 5) {
      system("clear");
      printf("|J| PHONE BOOK. Watch all.\n");
      printf("#\tName\tSurname\tPhone\n");
      for (size_t i = 0; i < phonebook_data_size; i++) {
        if (phonebook_data[i].property & 0b00000001) {
          printf("%zu\t%s\t%s\t%s\n", i, phonebook_data[i].name, phonebook_data[i].surname, phonebook_data[i].phone);
        }
      }
      Pause();
      return;
    } else if (action == 6) {
      char names[5][FILED_SIZE] = {"Olivia", "Hana", "Kevin", "Nicole", "Dave"};
      char surnames[5][FILED_SIZE] = {"Johnson", "Kim", "Jones", "Taylor", "Wilson"};
      char phones[5][FILED_SIZE] = {"+1-(205)-(111)-(1111)", "+1-(907)-(222)-(2222)", "+1-(479)-(333)-(333)", "+1-(303)-(444)-(4444)", "+1-(239)-(555)-(5555)"};
      for (size_t i = 0; i < 5; i++) {
        strcpy(phonebook_data[phonebook_data_size - space + i].name, names[i]);
        strcpy(phonebook_data[phonebook_data_size - space + i].surname, surnames[i]);
        strcpy(phonebook_data[phonebook_data_size - space + i].phone, phones[i]);
        phonebook_data[phonebook_data_size - space + i].property |= 0b00000001;
      }
      return;
    }

    while (1) {
      system("clear");
      printf("|J| HELLO! I'AM PHONE BOOK [%zu/%zu]:\n", (phonebook_data_size - space), phonebook_data_size);
      printf("1 - Add new contact;\n");
      printf("2 - Search;\n");
      printf("3 - Edit;\n");
      printf("4 - Remove.\n");
      printf("5 - Watch all.\n");
      printf("6 - Demo (autofill).\n");
      printf("Q - Quit.\n");
      printf("Please, type menu key and press Enter: ");
      key = Getchar();
      switch (key) {
        case '1':
          phonebook(1);
          key = 0;
          break;
        case '2':
          phonebook(2);
          key = 0;
          break;
        case '3':
          phonebook(3);
          key = 0;
          break;
        case '4':
          phonebook(4);
          key = 0;
          break;
        case '5':
          phonebook(5);
          key = 0;
          break;
        case '6':
          phonebook(6);
          key = 0;
          break;
        case 'q':
          return;
        case 'Q':
          return;
      }
      if (key == 0) {
        break;
      }
    }
  }
}

int main (void) {
  phonebook(0);
  return 0;
}
