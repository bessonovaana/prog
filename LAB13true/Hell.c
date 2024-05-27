#include"head.h"

// Функция сортировки методом Шелла
void shell_sort(int arr[], int n) {
    int gap, i, j, temp, count = 0, swap = 0;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            count ++;
            temp = arr[i];
            swap ++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                count ++;
                arr[j] = arr[j - gap];
                swap ++;
            }
            arr[j] = temp;
            swap ++;
        }
    }
    printf("M+C = %d", swap+count);
}