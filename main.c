#include <math.h>
#include <stdio.h>
#include <limits.h>

float FindAreaTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
int InputCoordinates(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3); //указаетли чтобы передавать ссылку на элемент
int main()
{
    int x1, x2, x3, y1, y2, y3;
    float result;

    printf("Laboratory work 3. Task 1\n");
    if (InputCoordinates(&x1, &y1, &x2, &y2, &x3, &y3)) {
        printf("\nPoint 1 coordinates is x = %d and y = %d\n", x1, y1);
        printf("Point 2 coordinates is x = %d and y = %d\n", x2, y2);
        printf("Point 3 coordinates is x = %d and y = %d\n", x3, y3);
    }

    result = FindAreaTriangle(x1, y1, x2, y2, x3, y3);
    !result ? printf("\nEntered triangle doesnt exist") : printf("\nThe area of the entered triangle is equal to: %.2f", result);
    return 0;
}

int InputCoordinates(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3) {
    float fx1, fx2, fx3, fy1, fy2, fy3;

    do {
        printf("Please enter an integer coord of points: \n"); //ввод по точке или ввод всех коорд сразу(?)
        scanf("%f %f %f %f %f %f", &fx1, &fy1, &fx2, &fy2, &fx3, &fy3);
        *x1 = (int) fx1, *y1 = (int) fy1;
        *x2 = (int) fx2, *y2 = (int) fy2;
        *x3 = (int) fx3, *y3 = (int) fy3;
        while(getchar()!='\n');
        if (*x1 > INT_MAX || *x2 > INT_MAX || *x3 > INT_MAX || *x1 < INT_MIN || *x2 < INT_MIN || *x3 < INT_MIN
        || *y1 > INT_MAX || *y2 > INT_MAX || *y3 > INT_MAX || *y1 < INT_MIN || *y2 < INT_MIN || *y3 < INT_MIN
        || *x1 != fx1 || *x2 != fx2 || *x3 != fx3 || *y1 != fy1 || *y2 != fy2 || *y3 != fy3 ) {
            printf("\nMake sure that u have entered int coordinates and try again\n");
            continue;
        }
        return 1;
    } while (1);
}

float FindAreaTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    float result = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return result;
}