#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define lmax 200

int main() {
    int n, i, n1 = -1, new_size;
    float x, h, a, sr, r[lmax];
    printf("Лабораторная работа №1\n");
    printf("Задание №1\n");

    // Задание 1: Вычисление массива R
    do {
        printf("Введите длину массива R от 1 до %d: ", lmax);
        scanf("%d", &n);
    } while (n <= 0 || n > lmax); // Ограничение массива по размерности
    printf("Введите x, h, a: ");
    scanf("%f", &x);
    scanf("%f", &h);
    scanf("%f", &a);
    for (i = 0; i < n; i++)
        r[i] = 6 * cos(a * x + h * i); // Вычисление элементов массива R по формуле
    printf("Массив R из %d элементов:\n", n);
    for (i = 0; i < n; i++)
        printf("%8.3f ", r[i]); // Вывод элементов массива R
    printf("\n");

    // Задание 2: Удаление положительных элементов после первого отрицательного
    printf("Задание №2\n");
    for (i = 0; i < n; i++) {
        if (r[i] < 0) {
            n1 = i;
            break; // Остановка цикла после первого отрицательного элемента
        }
    }

    if (n1 == -1) {
        printf("Нет отрицательных элементов\n");
    } else {
        new_size = n1 + 1;
        for (i = n1 + 1; i < n; i++) {
            if (r[i] <= 0) {
                r[new_size++] = r[i]; // Перемещение отрицательных элементов в начало массива, элементы до первого отрицательного остаются на своих местах
            }
        }
        n = new_size;

        printf("Массив R из %d элементов:\n", n);
        for (i = 0; i < n; i++) {
            printf("%8.3f ", r[i]); // Вывод измененного массива R
        }
        printf("\n");
    }

    // Задание 3: Вычисление среднего арифметического
    printf("Задание №3\n");
    if (n <= 1) {
        printf("Недостаточно элементов для вычисления среднего значения\n"); // Проверка на наличие элементов в массиве
        return 0;
    }

    int nmin = 0, nmax = 0;
    for (i = 1; i < n; i++) {
        if (fabs(r[i]) > fabs(r[nmax])) {
            nmax = i; // Нахождение элемента с максимальным значением по модулю
        }
        if (fabs(r[i]) < fabs(r[nmin])) {
            nmin = i; // Нахождение элемента с минимальным значением по модулю
        }
    }

    if (nmin > nmax) {
        int temp = nmin;
        nmin = nmax;
        nmax = temp; // Обмен значений, если nmin больше nmax, для корректного их использования в цикле
    }

    if (nmax - nmin == 1) {
        printf("Нет среднего значения\n");
    } else {
        sr = 0;
        for (i = nmin + 1; i < nmax; i++) {
            sr += r[i]; // Суммирование элементов между минимальным и максимальным по модулю
        }
        sr /= (nmax - nmin - 1); // Вычисление среднего арифметического
        printf("Среднее значение: %.3f\n", sr);
    }

    return 0;
}
