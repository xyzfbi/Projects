#include <stdio.h>
#include <stdlib.h>
#define lmax 200
#include <locale.h>
int main()
{
    int k, arr[lmax], count = 0, i, rev, last_digit, temp_n;
    int n;
    int palindromes[lmax];

    setlocale (LC_ALL, "Russian");
    printf("**************************************\n");
    printf("* Лабораторная работа №2. Задание №2 *\n");
    printf("**************************************\n");

    do
    {
        printf("\nВведите длину массива от 1 до %d: ", lmax);
        k = scanf("%d",&n);
        // NOTICE CHECK THE NUMS IN ONLINE COMPILIER!!!!
        // специально вводится переменная для проверки количества введенных величин
	    while(getchar()!='\n');
    } while(n > lmax|| n < 0||k != 1);

    // Enter array
    printf("Введите элементы массива:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Введенный массив: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Формирование массива палиндромов
    for (i = 0; i < n; i++)
    {
        temp_n = arr[i];
        rev = 0;

        // Проверка, является ли число палиндромом
        while (arr[i] != 0)
        {
            last_digit = arr[i] % 10;
            rev = rev * 10 + last_digit;
            arr[i] /= 10;
        }

        if (temp_n == rev)
        {
            palindromes[count++] = temp_n;
        }
    }
    // Вывод массива палиндромов
    if (count == 0)
    {
        printf("\nМассив пуст!\n");
    }
    else{
    printf("\nМассив палиндромов:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", palindromes[i]);
    }
    }
    return 0;
}
