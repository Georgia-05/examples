#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;

  // Open the file for reading - file name is 1_2020.txt
  file = fopen("test.txt", "r");

  // Check if the file was opened successfully
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Read the file line by line
  // char line[100];  // Declare a buffer to hold the line we're reading (max characters per line is
  // 100)

  // TODO: add your solution here
  int result[100000];
  int i = 0, number = 0, counter = 0;
  int temp = 0;
  int last_number = 0;
  char ch;
  int sum = 0;

  while ((ch = fgetc(file)) != EOF) {
    if (ch >= '0' && ch <= '9') {
      counter++;
      temp = ch - '0';
      if (counter == 1) {
        number = temp * 10;
        // printf("number = %d\n", number);
      }
    } else if (ch == '\n') {
      number += temp;
      result[i] = number;
      printf("result = %d\n", result[i]);
      sum += result[i];
      i++;
      counter = 0;
    }
  }

  if (ch == EOF) {
    number += temp;
    result[i] = number;
    sum += result[i];
    printf("result = %d\n", result[i]);
    printf("sum = %d\n", sum);
  }

  // Close the file before exiting
  fclose(file);

  return 0;
}
