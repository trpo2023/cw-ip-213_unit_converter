#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Chek_Units_Name(
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
                    i = 0;
                    while (HAVEunitName[i] != '\n')
                        i++;
                    HAVEunitName[i] = '\0';
                    break;
                }
        }
    }
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
                    i = 0;
                    while (WANTunitName[i] != '\n')
                        i++;
                    WANTunitName[i] = '\0';
                    break;
                }
        }
    }
    if (strcmp(HAVEunitName, WANTunitName) != 0) {
        printf("Error: different values ​​are compared, the result may not "
               "be correct!\n");
        printf("Error: you are trying to compare %s with %s!\n",
               HAVEunitName,
               WANTunitName);
    }
}

bool Chek_space(char* input)
{
    char* ptrEnd;
    strtod(input, &ptrEnd);
    if (*ptrEnd != ' ') {
        printf("Error: a space was expected after the number!\n");
        return 1;
    }
    return 0;
}

bool Chek_number(char* input)
{
    if ((input[0] >= '0') && (input[0] <= '9'))
        return 0;
    printf("Error: number expected first!\n");
    return 1;
}
