#include <stdio.h>
#include <stdlib.h>
int *function_to_count_characters(int argc, char **argv)
{
    int buffer_size = 128;
    int *arr = calloc(sizeof(int), buffer_size + 1);

    int i = 1;
    int j = 0;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            arr[(int)argv[i][j]]++;
            j++;
        }
        i++;
    }
    return arr;
}

void print_calculated_items(int *arr)
{
    int i = 0;
    while (i < 128)
    {
        if (arr[i] > 0)
        {
        printf("%c:%d\n", i, arr[i]);
        }
        i++;
    }
}

void my_ngram(int argc, char **argv)
{
    int *arr = function_to_count_characters(argc, argv);
    print_calculated_items(arr);
}

int main(int argc, char **argv)
{
    my_ngram(argc, argv);
    return 0;
}