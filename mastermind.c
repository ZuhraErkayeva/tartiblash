#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int my_strlen(char *str_1)
{
    int len = 0;
    while (str_1[len] != '\0')
    {
        len++;
    }
    return len;
}

int my_strcmp(char *str_1, char *str_2)
{
    int len_1 = my_strlen(str_1);
    int len_2 = my_strlen(str_2);
    if (len_1 != len_2)
        return 1;
    for (int i = 0; i < len_1; i++)
    {
        if (str_1[i] != str_2[i])
        {
            return 1;
        }
    }
    return 0;
}

char *my_strcpy(char *p1, char *p2)
{
    int i = 0;
    while (p2[i])
    {
        p1[i] = p2[i];
        i++;
    }
    return p1;
}

// 1234
int my_atoi(char *str_1)
{
    int res = 0, i = 0;

    while (str_1[i])
    {
        res *= 10;
        res += (int)str_1[i] - 48;
        i++;
    }
    return res;
}

int check_character(char *str1, char c)
{
    int i = 0;
    while (str1[i])
    {
        if (str1[i] == c)
        {
            return 1;

        }
        i++;
    }
    return 0;
}

char *my_random()
{
    char *Secredcode = calloc(sizeof(char), 5);
    char c;
    time_t t1;
    srand((unsigned)time(&t1));
    int i = 0;
    while ( i < 4)
    {
        c = (rand() % 9) + 48;
        if ((check_character(Secredcode, c)) == 0)
        {
            Secredcode[i] = c;
            i++;
        }
    }
    return Secredcode;
}

void my_mastermind(int argc, char **argv)
{
    int attemp = 10, i = 0;
    char *SecretCode = calloc(sizeof(char), 5);

    while (i < argc)
    {
        if ((my_strcmp(argv[i], "-c")) == 0)
        {
            SecretCode = my_strcpy(SecretCode, argv[i + 1]);
        }
        else if ((my_strcmp(argv[i], "-t")) == 0)
        {
            attemp = my_atoi(argv[i + 1]);
        }
        i++;
    }
    if (SecretCode[0] == 0)
    {
        SecretCode = my_random();
    }
    printf("%d : %s", attemp, SecretCode);
}

int main(int argc, char **argv)
{
    my_mastermind(argc, argv);
    return 0;
}