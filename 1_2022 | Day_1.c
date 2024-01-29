#include <stdio.h>
#include <stdlib.h>

int SIZE = 2243;

// print all the numbers
void print(int numbers[SIZE]) {
  for (int n = 0; n < SIZE; n++) {
    printf("%d\n", numbers[n]);
  }
}

// add your solution here
void solve(int numbers[SIZE]) {
  int sum[SIZE];
  int i = 0;
  int j = 0;

  for (i = 0; i < SIZE; i++) {
    if (numbers[i] == 0) {
      ++i;
      ++j;
    }
    // printf("i = %d j = %d numbers[%d] = %d\n", i, j, i, numbers[i]);
    sum[j] += numbers[i];
  }
  // int max = sum[0], second = 0, third = 0;
  // for (int n = 1; n < j; n++) {
  //   if (sum[n] > max) {
  //     third = second;
  //     second = max;
  //     max = sum[n];
  //   }
  // }
  int max = sum[0], second = sum[1], third = sum[2];
  for (int n = 1; n < j; n++) {
    if (sum[n] > max) {
      max = sum[n];
    }
  }
  for (int n = 2; n < j; n++) {
    if (sum[n] > second && sum[n] != max) {
      second = sum[n];
    }
  }
  for (int n = 3; n < j; n++) {
    if (sum[n] > third && sum[n] != max && sum[n] != second) {
      third = sum[n];
    }
  }
  printf("max = %d second = %d third = %d\n", max, second, third);
  int total = max + second + third;
  printf("total = %d\n", total);
}
int main() {
  FILE *file;

  // Open the file for reading - file name is 1_2020.txt
  file = fopen("1_2022.txt", "r");

  // Check if the file was opened successfully
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Read the file line by line
  char line[100];     // Declare a buffer to hold the line we're reading (max characters per line is
                      // 100)
  int numbers[SIZE];  // Declare an array to hold all the numbers (total is 200)
  int i = 0;          // Declare an index to keep track which number we're reading
  while (fgets(line, 100, file) != NULL) {
    // Convert the line to an integer and store it in the array
    numbers[i] = atoi(line);
    i++;
  }

  // print all the numbers for to check if they were read correctly
  // print(numbers);

  // TODO: add your solution here
  solve(numbers);

  // Close the file before exiting
  fclose(file);

  return 0;
}
