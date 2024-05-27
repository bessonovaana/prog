#include"head.h"

// Функция для заполнения массива случайными числами
void fill_random(int arr[], int n) {
    srand(time(NULL)); // инициализация генератора случайных чисел
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // случайное число от 0 до 999
    }
}
