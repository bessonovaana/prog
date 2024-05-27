#include<stdio.h>
#include <stdlib.h>
#define RED     "\033[1;31m"
#define RESET   "\033[0m" // == in hex "\x1B[0m"
#define BLACK   "\e[0;30m"
#define WHITE   "\e[0;37m"
#include <time.h>

void print_array(int arr[], int n);
void fill_keyboard(int arr[], int n);
void fill_random(int arr[], int n);
void insertion_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void cocktail_sort(int arr[], int n);
int binary_search(int arr[], int item, int low, int high) ;
void binary_insertion_sort(int arr[], int n);
void shell_sort(int arr[], int n);
