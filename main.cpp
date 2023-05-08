#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cctype>

#define MAX_LENGTH 25

int main()
{
    char input[MAX_LENGTH];
    char str[100];
    char HAVEunit[7];
    char WANTunit[7];
    char* ptrEnd;
    int uLength = 0;
    double k = 1;
    double result = 0;

    FILE* units = fopen("UnitsData", "r");
    if (units == NULL) {
        printf("Error: incorrect file path\n");
        return 1;
    }

    printf("You have: ");
    fgets(input, MAX_LENGTH, stdin);
    result = strtod(input, &ptrEnd);
    for (int i = 1; *(ptrEnd + i) != '\0'; i++) {
        HAVEunit[i - 1] = *(ptrEnd + i);
        uLength++;
    }
    ptrEnd = 0;
    printf("You want: ");
    fgets(input, MAX_LENGTH, stdin);
    strcpy(WANTunit, input);

    while (fgets(str, 100, units)) {
        if (!(strncmp(HAVEunit, str, uLength - 1))) {
            k = strtod(strchr(str, ' '), NULL);
            result = result * k;
        }
    }
    printf("\t* %.3f", result);

    return 0;
}