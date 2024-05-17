#include <stdio.h>
#include <cstdlib>
#include <sys/time.h>
#include "../headers/utils.h"
#include "../headers/bubble_sort.h"
#include "../headers/heap_sort.h"
#include "../headers/quick_sort.h"
#include "../headers/selection_sort.h"
#include "../headers/insert_sort.h"
#include "../headers/shell_sort.h"

int main() {
    int sizes[] = {100,  500, 1000, 10000, 20000, 50000, 100000};

    int special = 1;
    int ascending = 1;

    // 1 & 1 => data sorted ascending - TEST 3
    // 1 & 0 => data sorted descending - TEST 2
    // 0 & 1 => data random - TEST 1
    // 0 & 0 => data random - TEST 1

    for (int i = 0; i < 7; i++) {
        int size = sizes[i];
        printf("Running for size %d\n", size);
        {
            generate_random_data(size);
            int *data_read;
            int read_size = read_from_file(&data_read);
            if (special) {
                if (ascending) {
                    quickSort(data_read, 0, read_size - 1);
                } else {
                    quickSort(data_read, 0, read_size - 1);
                    reverse_array(data_read, read_size);
                }
            }
            printf("Bubble sort! \n");
            struct timeval start, end;
            gettimeofday(&start, NULL);
            bubbleSort(data_read, read_size);
            gettimeofday(&end, NULL);
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Requried time to sort: %ld mikrosekund\n", micros);
            free(data_read);
        }
        {
            generate_random_data(size);
            int *data_read;
            int read_size = read_from_file(&data_read);
            if (special) {
                if (ascending) {
                    quickSort(data_read, 0, read_size - 1);
                } else {
                    quickSort(data_read, 0, read_size - 1);
                    reverse_array(data_read, read_size);
                }
            }
            printf("Selection sort! \n");
            struct timeval start, end;
            gettimeofday(&start, NULL);
            selectionSort(data_read, read_size);
            gettimeofday(&end, NULL);
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Requried time to sort: %ld mikrosekund\n", micros);
            free(data_read);
        }
        {
            generate_random_data(size);
            int *data_read;
            int read_size = read_from_file(&data_read);
            if (special) {
                if (ascending) {
                    quickSort(data_read, 0, read_size - 1);
                } else {
                    quickSort(data_read, 0, read_size - 1);
                    reverse_array(data_read, read_size);
                }
            }
            printf("Insert sort! \n");
            struct timeval start, end;
            gettimeofday(&start, NULL);
            insertionSort(data_read, read_size);
            gettimeofday(&end, NULL);
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Requried time to sort: %ld mikrosekund\n", micros);
            free(data_read);
        }
        // Advanced methods
        {
            generate_random_data(size);
            int *data_read;
            int read_size = read_from_file(&data_read);
            if (special) {
                if (ascending) {
                    quickSort(data_read, 0, read_size - 1);
                } else {
                    quickSort(data_read, 0, read_size - 1);
                    reverse_array(data_read, read_size);
                }
            }
            printf("Quick sort! \n");    
            struct timeval start, end;
            gettimeofday(&start, NULL);
            quickSort(data_read, 0, read_size - 1);
            gettimeofday(&end, NULL);
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Requried time to sort: %ld mikrosekund\n", micros);   
            free(data_read); 
        }
        {
            generate_random_data(size);
            int *data_read;
            int read_size = read_from_file(&data_read);
            if (special) {
                if (ascending) {
                    quickSort(data_read, 0, read_size - 1);
                } else {
                    quickSort(data_read, 0, read_size - 1);
                    reverse_array(data_read, read_size);
                }
            }
            printf("Heap sort! \n");
            struct timeval start, end;
            gettimeofday(&start, NULL);
            heapSort(data_read, read_size);
            gettimeofday(&end, NULL);
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Requried time to sort: %ld mikrosekund\n", micros);
            free(data_read);
        }
        {
            generate_random_data(size);
            int *data_read;
            int read_size = read_from_file(&data_read);
            if (special) {
                if (ascending) {
                    quickSort(data_read, 0, read_size - 1);
                } else {
                    quickSort(data_read, 0, read_size - 1);
                    reverse_array(data_read, read_size);
                }
            }
            printf("Shell sort! \n");
            struct timeval start, end;
            gettimeofday(&start, NULL);
            shellSort(data_read, read_size);
            gettimeofday(&end, NULL);
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Requried time to sort: %ld mikrosekund\n", micros);
            free(data_read);
        }
        printf("=====================================\n");
    }
    return 0;
}
