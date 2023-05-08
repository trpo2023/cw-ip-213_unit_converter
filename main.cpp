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
    int uHLength = 0;
    int uWLength = 0;
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
        uHLength++;
    }
    ptrEnd = 0;
    printf("You want: ");
    fgets(WANTunit, 7, stdin);

    for (int i = 1; WANTunit[i] != '\0'; i++)
        uWLength++;

    while (fgets(str, 100, units)) {
        if (!(strncmp(HAVEunit, str, uHLength - 1))) {
            result *= strtod(strchr(str, ' '), NULL);
        }

        if (!(strncmp(WANTunit, str, uWLength)))
            result /= strtod(strchr(str, ' '), NULL);
    }
    printf("\t* %f\n", result);

    return 0;
}