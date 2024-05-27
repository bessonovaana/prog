#include"head.h"
 

// Функция сортировки методом бинарного включения
void binary_insertion_sort(int arr[], int n) {
    int i, loc, j, selected, swap = 0, count = 0;

    for (i = 1; i < n; ++i) {
        count++;
        j = i - 1;
        selected = arr[i];

        // находим позицию для вставки
        loc = binary_search(arr, selected, 0, j);
        count += 3;
        // передвигаем большие элементы вправо
        while (j >= loc) {
            arr[j + 1] = arr[j];
            swap++;
            j--;
        }
        arr[j + 1] = selected;
        swap++;
    }
    printf("M+C =  %d ", swap+count);
}