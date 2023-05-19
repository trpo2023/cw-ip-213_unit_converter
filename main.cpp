#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#include <iostream>

#define MAX_LENGTH 25

/*void ChekErorr(char input)
{

}*/

int main()
{
    char input[MAX_LENGTH];
    char str[100];
    char HAVEunitName[100];
    char WANTunitName[100];
    char HAVEunit[7];
    char WANTunit[7];
    char* ptrEnd;
    int struLength = 0;
    int uHLength = -1;
    int uWLength = 0;
    double result = 0;
    int i = 0;

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
                result *= strtod(strchr(str, ' '), NULL);
                while (fgets(str, 100, units))
                    if (str[0] == '#') {
                        strcpy(HAVEunitName, str);
                        i = 0;
                        while (HAVEunitName[i] != '\n')
                            i++;
                        HAVEunitName[i] = '\0';
                        break;
                    }
            }

            if (!(strncmp(WANTunit, str, struLength))
                && struLength == uWLength) {
                result /= strtod(strchr(str, ' '), NULL);
                while (fgets(str, 100, units))
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
        fseek(units, 0, SEEK_END);
        rewind(units);
        if (strcmp(HAVEunitName, WANTunitName) != 0) {
            printf("Different values ​​are compared, the result may not be "
                   "correct!\n");
            printf("You are trying to compare %s with %s!\n",
                   HAVEunitName,
                   WANTunitName);
        }
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
