#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
#include "../headers/utils.h"

// Function to write data to file
void write_to_file(int data[], int size) {
    FILE *file;
    file = fopen("dane.txt", "w");

    if (file != NULL) {
        for (int i = 0; i < size; i++) {
            fprintf(file, "%d ", data[i]);
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

// Function to read data from file
int read_from_file(int **data) {
    FILE *file;
    file = fopen("dane.txt", "r");

    if (file != NULL) {
        int value, count = 0;
        while (fscanf(file, "%d", &value) != EOF) {
            count++; // Increment count for each value read
        }
        rewind(file); // Reset file pointer to the beginning of the file

        // Allocate memory dynamically for the array
        *data = (int *)malloc(count * sizeof(int));
        if (*data == NULL) {
            printf("Error allocating memory.\n");
            return -1; // Return -1 to indicate memory allocation failure
        }

        // Read values from file into dynamically allocated array
        for (int i = 0; i < count; i++) {
            fscanf(file, "%d", &((*data)[i]));
        }
        
        fclose(file);
        return count; // Return the number of elements read
    } else {
        printf("Error opening file for reading.\n");
        return -1; // Return -1 to indicate file opening failure
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void generate_random_data(int size) 
{
    // Seed the random number generator
    srand(time(NULL));

    // Open the file for writing
    FILE *outFile = fopen("dane.txt", "w");
    if (outFile == NULL) {
        perror("Error opening file for writing");
        return;
    }

    // Generate and write 1,000 random numbers to the file
    for (int i = 0; i < size; ++i) {
        // Generate a random number between -100 and 100
        int num = rand() % 201 - 100; // rand() % (max - min + 1) + min

        // Write the number to the file
        fprintf(outFile, "%d", num);

        // If it's not the last number, add a space
        if (i != 999) {
            fprintf(outFile, " ");
        }
    }

    // Close the file
    fclose(outFile);
}

void reverse_array(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move towards the middle of the array
        start++;
        end--;
    }
}