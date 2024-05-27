#include"head.h"

// Функция сортировки методом пузырьковой сортировки
void bubble_sort(int arr[], int n) {
    int i, j, temp, swap = 0, count = 0;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                count++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap += 3;
            }
        }
    }
    printf("M+C = %d", swap+count);
}   