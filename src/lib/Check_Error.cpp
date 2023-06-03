#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Check_Units_Name(
        char* HAVEunit,
        int uHLength,
        char* WANTunit,
        int uWLength,
        double result)
{
    FILE* units = fopen("UnitsData", "r");
    char str[30];
    char HAVEunitName[30];
    char WANTunitName[30];
    int i = 0;
    while (fgets(str, 30, units)) {
        int struLength = 0;
        for (int i = 0; str[i] != ' '; i++)
            struLength++;
        if (!(strncmp(HAVEunit, str, struLength)) && struLength == uHLength) {
            result *= strtod(strchr(str, ' '), NULL);
            while (fgets(str, 30, units))
                if (str[0] == '#') {
                    strcpy(HAVEunitName, str);
                    while (HAVEunitName[i] != '\n')
                        i++;
                    HAVEunitName[i] = '\0';
                    break;
                }
            break;
        }
    }
    if (i == 0) {
        return 1;
    }
    i = 0;
    units = fopen("UnitsData", "r");
    while (fgets(str, 30, units)) {
        int struLength = 0;
        for (int i = 0; str[i] != ' '; i++)
            struLength++;
        if (!(strncmp(WANTunit, str, struLength)) && struLength == uWLength) {
            result /= strtod(strchr(str, ' '), NULL);
            while (fgets(str, 30, units))
                if (str[0] == '#') {
                    strcpy(WANTunitName, str);
                    while (WANTunitName[i] != '\n')
                        i++;
                    WANTunitName[i] = '\0';
                    break;
                }
        }
    }
    if (i == 0) {
        return 2;
    }
    if (strcmp(HAVEunitName, WANTunitName) != 0) {
        return 3;
    }
    return 0;
}

int Check_space(char* input)
{
    char* ptrEnd;
    strtod(input, &ptrEnd);
    if (*ptrEnd != ' ') {
        return 4;
    }
    return 0;
}

int Check_number(char* input)
{
    if ((input[0] >= '0') && (input[0] <= '9'))
        return 0;
    return 5;
}
