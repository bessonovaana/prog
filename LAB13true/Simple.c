#include"head.h"

// Функция сортировки методом простого включения (Insertion Sort)
void insertion_sort(int arr[], int n) {
    int i, key, j, swap = 0, count = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        swap++;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            count++;
            arr[j + 1] = arr[j];
            j = j - 1;
            swap += 2;
        }
        arr[j + 1] = key;
        swap ++;
    }
    printf("M+C = %d", swap+count);
}