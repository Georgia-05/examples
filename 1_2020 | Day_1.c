#include <stdio.h>
#include <stdlib.h>

/*
You need you to find the two entries that sum to 2020 and then multiply those two numbers together.

For example, suppose your expense report contained the following:

* 1721
* 979
* 366
* 299
* 675
* 1456
In this example list, the two entries that sum to 2020 are 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the correct answer is 514579.

Open the file 1_2020.txt which contains 200 numbers, and find the two entries that sum to 2020; what do you get if you multiply them together?

NOTE: The part that reads the file is already written for you. You need to add your solution in the solve(int[200]) function.
*/

// print all the numbers 
void print(int numbers[200]) {
    for (int n = 0; n < 200; n++) {
        printf("%d\n", numbers[n]);
    }
}

// add your solution here
void solve(int numbers[200]) {
  for(int i = 0; i < 200; i++){
    for(int  j = i; j < 200; j++) {
      for(int n = j; n < 200; n++) {
        if(numbers[i] + numbers[j] + numbers[n]== 2020) {
          long int result = numbers[i]*numbers[j]*numbers[n];
          printf("%d * %d * %d = %ld\n", numbers[i], numbers[j], numbers[n], result);
        }
      }
    }
  }
}

int main() {
    FILE *file;

    // Open the file for reading - file name is 1_2020.txt
    file = fopen("1_2020.txt", "r"); 

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file line by line
    char line[100];    // Declare a buffer to hold the line we're reading (max characters per line is 100)
    int numbers[200];  // Declare an array to hold all the numbers (total is 200)
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
