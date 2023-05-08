#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>

#define MAX_LENGTH 25

int main()
{
    char input[MAX_LENGTH];
    double number;
    char unit[7];
    char* ptrEnd;

    printf("You have: ");
    fgets(input, MAX_LENGTH, stdin);
    number = strtod(input, &ptrEnd);
    for (int i = 1; *(ptrEnd + i) != '\0'; i++) {
        unit[i - 1] = *(ptrEnd + i);
    }

    return 0;
}