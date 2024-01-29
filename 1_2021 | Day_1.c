#include <stdio.h>
#include <stdlib.h>

int SIZE = 2000;

// print all the numbers
void print(int numbers[SIZE]) {
  for (int n = 0; n < SIZE; n++) {
    printf("%d\n", numbers[n]);
  }
}

// add your solution here
void solve(int numbers[SIZE]) {
  int counter = 0;
  int sum[1999];
  sum[0] = numbers[0] + numbers[1] + numbers[2];
  for (int i = 1; i < SIZE - 1; i++) {
    sum[i] = numbers[i] + numbers[i + 1] + numbers[i + 2];
    if (sum[i - 1] < sum[i]) {
      counter++;
    }
  }
  printf("counter = %d\n", counter);
}
int main() {
  FILE *file;

  // Open the file for reading - file name is 1_2020.txt
  file = fopen("1_2021.txt", "r");

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
  print(numbers);

  // TODO: add your solution here
  solve(numbers);

  // Close the file before exiting
  fclose(file);

  return 0;
}
