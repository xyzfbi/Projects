#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lmax 20000
int main(){
    int flag = 1;
    int n, i, arr[lmax], num, temp = 0;
    printf("HI YO!!!\n");
    printf("Enter array length: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        num = rand() % 100;
        arr[i] = num;
    }
    printf("Unsorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    do{
    flag = 1;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            flag = 0;
        }
    }
    } while (flag != 1);

    printf("\nSorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

