#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/utils.h"

void write_to_file(int data[], int size)
{
    FILE *file;
    file = fopen("dane.txt", "w");

    if (file != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(file, "%d ", data[i]);
        }
        fclose(file);
    }
    else
    {
        printf("Error opening file for writing.\n");
    }
}

int read_from_file(int **data)
{
    FILE *file;
    file = fopen("dane.txt", "r");

    if (file != NULL)
    {
        int value, count = 0;
        while (fscanf(file, "%d", &value) != EOF)
        {
            count++;
        }
        rewind(file);

        *data = (int *)malloc(count * sizeof(int));
        if (*data == NULL)
        {
            printf("Error allocating memory.\n");
            return -1;
        }

        for (int i = 0; i < count; i++)
        {
            fscanf(file, "%d", &((*data)[i]));
        }

        fclose(file);
        return count;
    }
    else
    {
        printf("Error opening file for reading.\n");
        return -1;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void generate_random_data(int size)
{

    srand(time(NULL));

    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        array[i] = i;
    }

    for (int i = size - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    FILE *outFile = fopen("dane.txt", "w");
    if (outFile == NULL)
    {
        perror("Error opening file for writing");
        free(array);
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        fprintf(outFile, "%d", array[i]);

        if (i != size - 1)
        {
            fprintf(outFile, " ");
        }
    }

    fclose(outFile);

    free(array);
}

int generate_random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
