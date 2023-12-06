#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"
#define MAX_BUFFER 128

typedef struct
{
    char string[6];
    int len;
} NUMBER_MAP;

NUMBER_MAP MAP[9] = {
    {"one", 3},
    {"two", 3},
    {"three", 5},
    {"four", 4},
    {"five", 4},
    {"six", 3},
    {"seven", 5},
    {"eight", 5},
    {"nine", 4}};

int check_with_map(char *buf, int remain)
{
    for (size_t i = 0; i < 9; i++)
    {
        if (remain >= MAP[i].len)
        {
            if (!strncmp(buf, MAP[i].string, MAP[i].len))
            {
                return i + 1;
            }
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    char buffer[MAX_BUFFER];
    int sum;
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Error: unable to open input file!\r\n");
        fclose(file);
        return 1;
    }
    while (fgets(buffer, MAX_BUFFER, file))
    {
        int digit = 0;
        int first_digit = -1;
        int last_digit = -1;
        int len = strlen(buffer);
        int value = 0;
        for (size_t j = 0; j < len; j++)
        {
            if (isdigit(buffer[j]))
            {
                digit = buffer[j] - 0x30;
                if (first_digit == -1)
                {
                    first_digit = digit;
                }
                last_digit = digit;
            }
            else
            {
                value = check_with_map(buffer + j, (len - j));
                if (value != 0)
                {
                    if (first_digit == -1)
                    {
                        first_digit = value;
                    }
                    last_digit = value;
                }
            }
        }
        printf("%s %d\n", buffer, first_digit * 10 + last_digit);
        sum += first_digit * 10 + last_digit;
    }
    fclose(file);
    printf("%d\n", sum);
    return 0;
}
