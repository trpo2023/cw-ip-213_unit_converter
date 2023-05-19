#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 25

double
Convert(FILE* units,
        char* HAVEunit,
        int uHLength,
        char* WANTunit,
        int uWLength,
        double result)
{
    char str[30];
    while (fgets(str, 30, units)) {
        int struLength = 0;
        for (int i = 0; str[i] != ' '; i++)
            struLength++;

        if (!(strncmp(HAVEunit, str, struLength)) && struLength == uHLength) {
            result *= strtod(strchr(str, ' '), NULL);
        }

        if (!(strncmp(WANTunit, str, struLength)) && struLength == uWLength) {
            result /= strtod(strchr(str, ' '), NULL);
        }
    }
    return result;
}