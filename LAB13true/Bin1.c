#include"head.h"

// Функция для выполнения бинарного поиска
int binary_search(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binary_search(arr, item, mid + 1, high);
    return binary_search(arr, item, low, mid - 1);
}