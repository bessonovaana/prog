#include "head.h"

// Главная функция
int main() {
    int n_values[] = {100, 200, 300, 400, 500};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);
    
    printf("n\tShell Sort\tBinary Insertion Sort\tCocktail Sort\tBubble Sort\tInsertion Sort\n");

    for (int i = 0; i < num_values; i++) {
        int n = n_values[i];
        int arr[n];
        double time_taken;
        int choice, sorting_method;

        
        printf("Выберите способ заполнения массива (1 - случайные числа, 2 - ввод с клавиатуры): ");
        scanf("%d", &choice);
        printf("%d\n",choice);

        // Заполнение массива в зависимости от выбора пользователя
        switch(choice) {
            case 1:
                fill_random(arr, n);
                break;
            case 2:
                printf("Введите %d элементов массива:\n", n);
                for (int i = 0; i <n; i++)
                {
                    arr[i]=i+1;
                }
                break;
            default:
                printf( RED "Некорректный выбор.   \n" );
                return 1;
        }
        print_array(arr, n);

        printf("Выберите метод сортировки (1 - Шелл, 2 - Бинарное включение, 3 - Шейкерная, 4 - Пузырьковая, 5 - Простое включение): ");
        scanf("%d", &sorting_method);
        printf("%d\n", sorting_method);
       
        // Засекаем время перед сортировкой
        clock_t t_start, t_end;
        
        
        // Выполняем сортировку в зависимости от выбранного метода
        switch(sorting_method) {
            case 1:
                t_start = clock();
                shell_sort(arr, n);
                t_end = clock();
                break;
            case 2:
                t_start = clock();
                binary_insertion_sort(arr, n);
                t_end = clock();
                break;
            case 3:
                t_start = clock();
                cocktail_sort(arr, n);
                t_end = clock();
                break;
            case 4:
                t_start = clock();
                bubble_sort(arr, n);
                t_end = clock();
                break;
            case 5:
                t_start = clock();
                insertion_sort(arr, n);
                t_end = clock();
                break;
            default:
                printf(RED "Некорректный выбор метода сортировки.\n");
                return 1;
        }

        // Вычисляем время сортировки
        time_taken = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
        printf("\n");
        print_array(arr, n);

        // Выводим результаты
        printf("   %d\t%f\n", n, time_taken);
    }

    return 0;
}
