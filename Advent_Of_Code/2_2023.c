#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /*Open file for reading*/
  FILE *file = fopen("day2.txt", "r");
  if (file == NULL) {
    perror("Failed to open file");
    return 1;
  }

  /*Define variables*/
  char *lines[100] = {0};
  char *buffer = NULL;
  size_t buffersize = 0;
  int red = 12, blue = 14, green = 13, number = 0, round = 0, total = 0;
  char color[20];
  char game[4];
  int counter = 0;

  /*With getline() function we get one line of the input file each time */
  while ((getline(&buffer, &buffersize, file) != -1)) {
    printf("%s", buffer);

    const char *ptr = buffer;

    /*Each line has a specific format*/
    /*For start, we extract game and round*/
    sscanf(ptr, "%s %d:", game, &round);
    printf("Parsed game and round: %s %d\n\n", game, round);

    ptr = strchr(ptr, ':') + 1; /* Move past ':' */

    const char *semicolon = strchr(ptr, ';') + 1; /* Move past ';' */

    /*sscanf() function is used to parse number and color*/
    while ((sscanf(ptr, "%d %s", &number, color) == 2)) {
      printf("Parsed number and color: %d %s\n", number, color);

      if ((strcmp(color, "red,") == 0) || (strcmp(color, "red;") == 0) ||
          ((strcmp(color, "red") == 0))) {
        if (number > red) {
          counter = round;
          break; /* Exit the inner while loop */
        }
      } else if ((strcmp(color, "blue,") == 0) || (strcmp(color, "blue;") == 0) ||
                 ((strcmp(color, "blue") == 0))) {
        if (number > blue) {
          counter = round;
          break; /* Exit the inner while loop */
        }
      } else if ((strcmp(color, "green,") == 0) || (strcmp(color, "green;") == 0) ||
                 (strcmp(color, "green") == 0)) {
        if (number > green) {
          counter = round;
          break; /* Exit the inner while loop */
        }
      }

      ptr = strchr(ptr, ','); /*Move to the next ',' or the end of the string*/
      if (ptr) {
        ptr++; /*Continue after ','*/
      } else {
        break; /* Exit the inner while loop if no more ',' */
      }
    }

    printf("\nSemicolon phrase: %s\n", semicolon);

    /* Parse the part after the semicolon */
    while ((sscanf(semicolon, "%d %s", &number, color) == 2)) {
      printf("Parsed number and color: %d %s\n", number, color);

      if ((strcmp(color, "red,") == 0) || (strcmp(color, "red;") == 0) ||
          ((strcmp(color, "red") == 0))) {
        if (number > red) {
          counter = round;
          break; /* Exit the inner while loop */
        }
      } else if ((strcmp(color, "blue,") == 0) || (strcmp(color, "blue;") == 0) ||
                 ((strcmp(color, "blue") == 0))) {
        if (number > blue) {
          counter = round;
          break; /* Exit the inner while loop */
        }
      } else if ((strcmp(color, "green,") == 0) || (strcmp(color, "green;") == 0) ||
                 (strcmp(color, "green") == 0)) {
        if (number > green) {
          counter = round;
          break; /* Exit the inner while loop */
        }
      }

      semicolon = strchr(semicolon, ';');
      if (semicolon) {
        semicolon++;
      } else {
        break; /* Exit the inner while loop if no more ';' */
      }
    }

    if (round != counter) {
      total += round;
    }

    printf("Total = %d\n==============\n\n", total);
  }

  printf("Sum of rounds = %d\n", total);

  free(buffer);
  fclose(file);
  return 0;
}
