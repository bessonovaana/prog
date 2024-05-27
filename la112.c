#include<stdio.h>
#include<stdlib.h>
int h(int* A, int n, int index){
    if (0>index){
        return 0;
    }
    int count=h( A, n, index-1);
    if ((A[index]>=-2)&&(A[index])<=2){
        count++;
    }
    return count;
}
int main(void){
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    int* A=(int*)malloc(n*sizeof(int));
    printf("Массив: ");
    for (int i=0; i<n; i++){
        A[i]=rand()%10-5;
        printf("%d ", A[i]);
    }
    int end=h(A, n,n-1);
    
    printf("\nВ данном массиве в интервал попадают %d числа\n", end);
    free(A);
}