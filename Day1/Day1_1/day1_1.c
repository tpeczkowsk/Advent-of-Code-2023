#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"
#define MAX_BUFFER 128

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
        }
        printf("%s %d\n", buffer, first_digit * 10 + last_digit);
        sum += first_digit * 10 + last_digit;
    }
    fclose(file);
    printf("%d\n", sum);
    return 0;
}
