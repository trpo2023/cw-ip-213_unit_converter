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
    int struLength = 0;
    int uHLength = -1;
    int uWLength = 0;
    double result = 0;

    FILE* units = fopen("UnitsData", "r");
    if (units == NULL) {
        printf("Error: incorrect file path\n");
        return 1;
    }
    while (1) {
        printf("You have: ");
        fgets(input, MAX_LENGTH, stdin);
        result = strtod(input, &ptrEnd);
        for (int i = 1; *(ptrEnd + i) != '\0'; i++) {
            HAVEunit[i - 1] = *(ptrEnd + i);
            uHLength++;
        }
        printf("You want: ");
        fgets(WANTunit, 7, stdin);
        for (int i = 1; WANTunit[i] != '\0'; i++)
            uWLength++;

        while (fgets(str, 100, units)) {
            struLength = 0;
            for (int i = 0; str[i] != ' '; i++)
                struLength++;

            if (!(strncmp(HAVEunit, str, struLength))
                && struLength == uHLength) {
                printf("1");
                result *= strtod(strchr(str, ' '), NULL);
            }

            if (!(strncmp(WANTunit, str, struLength))
                && struLength == uWLength) {
                printf("2");
                result /= strtod(strchr(str, ' '), NULL);
            }
        }
        fseek(units, 0, SEEK_END);
        rewind(units);
        printf("\t* %f\n", result);
        for (int i = 0; i < 7; i++) {
            HAVEunit[i] = ' ';
            WANTunit[i] = ' ';
        }
        uWLength = 0;
        uHLength = -1;
    }
    return 0;
}