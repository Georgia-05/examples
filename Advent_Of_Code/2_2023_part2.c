#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /* Open the file for reading */
  FILE *file = fopen("day2.txt", "r");
  if (file == NULL) {
    perror("Failed to open file");
    return 1;
  }

  /*Define variables*/
  char *lines[100] = {0};
  char *buffer = NULL;
  size_t buffersize = 0;
  int number = 0, round = 0, i = 0;
  char color[20];
  char game[4];
  long int set = 0, sum = 0;

  int red[100], blue[100], green[100];

  /* Initialize arrays to zero */
  for (i = 0; i < 100; i++) {
    red[i] = blue[i] = green[i] = 0;
  }

  i = 0;

  /*With getline() function we get one line of the input file each time */
  while ((getline(&buffer, &buffersize, file) != -1)) {
    printf("%s", buffer);

    const char *ptr = buffer;

    /*Each line has a specific format*/
    /*For start, we extract game and round*/
    sscanf(ptr, "%s %d:", game, &round);
    printf("Parsed game and round: %s %d\n\n", game, round);

    ptr = strchr(ptr, ':') + 1; /*Mone past ':' */

    const char *semicolon = strchr(ptr, ';') + 1; /* Move past ';' */

    /*sscanf() function is used to parse number and color*/
    while ((sscanf(ptr, "%d %s", &number, color) == 2)) {
      printf("Parsed number and color: %d %s\n", number, color);

      if ((strcmp(color, "red,") == 0) || (strcmp(color, "red;") == 0) ||
          ((strcmp(color, "red") == 0))) {
        if (number > red[i]) {
          red[i] = number;
        }
      } else if ((strcmp(color, "blue,") == 0) || (strcmp(color, "blue;") == 0) ||
                 ((strcmp(color, "blue") == 0))) {
        if (number > blue[i]) {
          blue[i] = number;
        }
      } else if ((strcmp(color, "green,") == 0) || (strcmp(color, "green;") == 0) ||
                 (strcmp(color, "green") == 0)) {
        if (number > green[i]) {
          green[i] = number;
        }
      }

      ptr = strchr(ptr, ','); /* Move to the next ',' or the end of the string */
      if (ptr) {
        ptr++; /* Move past ',' */
      } else {
        break;
      }
    }

    printf("\nSemicolon phrase: %s\n", semicolon);

    /* Parse the part after the semicolon */
    while ((sscanf(semicolon, "%d %s", &number, color) == 2)) {
      printf("Parsed number and color: %d %s\n", number, color);

      if ((strcmp(color, "red,") == 0) || (strcmp(color, "red;") == 0) ||
          ((strcmp(color, "red") == 0))) {
        if (number > red[i]) {
          red[i] = number;
        }
      } else if ((strcmp(color, "blue,") == 0) || (strcmp(color, "blue;") == 0) ||
                 ((strcmp(color, "blue") == 0))) {
        if (number > blue[i]) {
          blue[i] = number;
        }
      } else if ((strcmp(color, "green,") == 0) || (strcmp(color, "green;") == 0) ||
                 (strcmp(color, "green") == 0)) {
        if (number > green[i]) {
          green[i] = number;
        }
      }

      semicolon = strchr(semicolon, ';');
      if (semicolon) {
        semicolon++;
      } else {
        break; /* Exit the inner while loop if no more ';' */
      }
    }

    printf("red[%d] = %d, blue[%d] = %d, green[%d] = %d\n", i, red[i], i, blue[i], i, green[i]);

    /* Calculate set value and update the sum */
    set = red[i] * blue[i] * green[i];
    sum += set;
    printf("Set = %ld\n==============\n\n", set);
    i++;
  }

  printf("Sum is: = %ld\n", sum);

  free(buffer);
  fclose(file);
  return 0;
}
