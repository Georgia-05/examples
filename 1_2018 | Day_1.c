#include <stdio.h>
#include <stdlib.h>

// print all the numbers 
void print(int numbers[973]) {
    for (int n = 0; n < 973; n++) {
      printf("%d\n", numbers[n]);
    }
}

// add your solution here
void solve(int numbers[973]) {
  long int frequency = 0;
  for(int i = 0; i < 973; i++) {
    frequency += numbers[i];
  }
  // for(int i = 0; i)
  printf("frequency  = %ld\n", frequency);  
}

int main() {
    FILE *file;

    // Open the file for reading - file name is 1_2019.txt
    file = fopen("1_2018.txt", "r"); 

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file line by line
    char line[973];    // Declare a buffer to hold the line we're reading (max characters per line is 100)
    int numbers[973];  // Declare an array to hold all the numbers (total is 200)
    int i = 0;         // Declare an index to keep track which number we're reading
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


