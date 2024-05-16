#include <stdio.h>
#include <cstdlib>
#include "../headers/utils.h"
#include "../headers/bubble_sort.h"
#include "../headers/heap_sort.h"
#include "../headers/quick_sort.h"
#include "../headers/selection_sort.h"
#include "../headers/insert_sort.h"
#include "../headers/shell_sort.h"

int main() {
    int *data_read;
    int read_size = read_from_file(&data_read);

    printArray(data_read, read_size);
    {
        printf("Bubble sort! \n");
        bubbleSort(data_read, read_size);
        printArray(data_read, read_size);   
    }
    {
        printf("Heap sort! \n");
        heapSort(data_read, read_size);
        printArray(data_read, read_size);   
    }
    {
        printf("Quick sort! \n");
        quickSort(data_read, 0, read_size - 1);
        printArray(data_read, read_size);   
    }
    {
        printf("Selection sort! \n");
        selectionSort(data_read, read_size);
        printArray(data_read, read_size);   
    }
    {
        printf("Insert sort! \n");
        insertionSort(data_read, read_size);
        printArray(data_read, read_size);   
    }
    {
        printf("Shell sort! \n");
        shellSort(data_read, read_size);
        printArray(data_read, read_size);
    }

    free(data_read);
    return 0;
}
