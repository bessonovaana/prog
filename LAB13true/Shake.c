#include"head.h"

// Функция сортировки методом шейкерной сортировки (шейкерной сортировки)
void cocktail_sort(int arr[], int n) {
    int left = 0, right = n - 1, swapped = 0, count = 0, swap = 0;

    while (left < right && !swapped) {
        count++;
        swapped = 1;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                count++;
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap += 3;
                swapped = 0;
            }
        }
        right--;

        if (!swapped) {
            swapped = 1;
            for (int i = right; i > left; i--) {
                if (arr[i] < arr[i - 1]) {
                    count++;
                    int temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                    swap += 3;
                    swapped = 0;
                }
            }
            left++;
        }
    }
        printf("M+C = %d", swap+count);

}