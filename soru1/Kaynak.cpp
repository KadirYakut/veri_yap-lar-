#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

int main()
{
    int arr[MAX_SIZE];
    int freq[MAX_SIZE];
    int size, i, j, count;

    printf("Dizinin boyutunu girin: ");
    scanf("%d", &size);

    printf("Dizi elemanlarini girin:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }

    for (i = 0; i < size; i++)
    {
        count = 1;
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0)
        {
            freq[i] = count;
        }
    }

    printf("\nTum elemanlar ve frekanslari:\n");
    for (i = 0; i < size; i++)
    {
        if (freq[i] != 0)
        {
            printf("%d rakami %d defa\n", arr[i], freq[i]);
        }
    }

    return 0;
}