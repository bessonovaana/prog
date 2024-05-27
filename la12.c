#include<stdio.h>
#include<stdlib.h>
#include"str.h"
int main(){
    int n;
    printf("Введите количество параллелепипедов: ");
    scanf("%d", &n);
    printf("\n");
    paral *pps=(paral*)malloc(n*sizeof(paral));
    for (int i=0; i<n; i++){
        printf("введите сторону а %d параллелипида: ", i+1);
        scanf ("%lf",&pps[i].a);
        printf("введите сторону b %d параллелипипеда: ", i+1);
        scanf("%lf", &pps[i].b);
        printf("введите высоту %d параллелипипеда: ", i+1);
        scanf("%lf", &pps[i].h);
        printf("\n");
    }
    double min=1000000;
    int index=-1;
    for (int i=0;i<n;i++){
        if (voluem(pps[i])<min){
            min=voluem(pps[i]);
            index=i+1;
        }
    }
    printf("наимешьший объем у %d\n", index);
    free(pps);
}