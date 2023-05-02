#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE * 2];
    int size1, size2, mergeSize;
    int i, j, k;

    printf("1. dizinin boyutunu girin: ");
    scanf("%d", &size1);

    printf("1. dizinin elemanlarýný girin:\n");
    for (i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("2. dizinin boyutunu girin: ");
    scanf("%d", &size2);

    printf("2. dizinin elemanlarýný girin:\n");
    for (i = 0; i < size2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            merged[k] = arr1[i];
            i++;
        }
        else
        {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    mergeSize = k;

    printf("\nBirleþtirilmiþ ve sýralanmýþ dizi:\n");
    for (i = 0; i < mergeSize; i++)
    {
        printf("%d ", merged[i]);
    }

    return 0;
}