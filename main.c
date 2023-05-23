#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "HelperFuncs.h"

long long int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

long long int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    return a * power(a, b - 1);
}

int find_max(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int max_of_rest = find_max(arr + 1, n - 1);
    return arr[0] > max_of_rest ? arr[0] : max_of_rest;
}


int main()
{
    srand(time(NULL));
    int menuChoice;
    int count;  // Перемещаем объявление переменной count сюда
    while (1)
    {
        system("cls");
        printf("1. Fibonacci\n"
               "2. Power\n"
               "3. Find Max\n"
               "0. Exit\n"
               "Enter your choice");
        menuChoice = range_scan(0, 3);
        int *arr;  // Используем указатель для массива

        switch (menuChoice)
        {
            case 1:
                system("cls");
                printf("Fibonacci\n"
                       "Enter n");
                int n = range_scan(0, INT_MAX);

                printf("%lld\n", fib(n));
                break;
            case 2:
                system("cls");
                printf("Power (a^b)\n"
                       "Enter a");
                int a = scan_safe_func_int();
                printf("Enter b");
                int b = scan_safe_func_int();

                printf("%lld\n", power(a, b));
                break;
            case 3:
                system("cls");
                printf("Find Max\n"
                       "Enter count of elements");
                count = scan_safe_func_int();
                printf("Generate %d random numbers in array\n", count);
                arr = (int *) malloc(count * sizeof(int));  // Динамическое выделение памяти

                int i;
                for (i = 0; i < count; i++)
                {
                    arr[i] = rand() % 100;
                    printf("%d ", arr[i]);
                }

                printf("max = %d\n", find_max(arr, count));

                free(arr);  // Освобождаем выделенную память
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
        system("pause");
    }
}
