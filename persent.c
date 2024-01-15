#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void sort_characters(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)  //1
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char *arr = calloc(100, sizeof(char));
    int ind = 0;
    int key = open("num.txt", O_RDONLY);
    if (key == -1)
    {
        printf("\n");
        return 1;
    }
    int charactersRead;
    while ((charactersRead = read(key, &arr[ind], 1)) != 0)
    {
        if (charactersRead == -1)
        {
            printf("\n");
            return 1;
        }
        ind++;
    }
    close(key);
    sort_characters(arr, ind);

    for (int i = 0; i < ind; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
    return 0;
}
