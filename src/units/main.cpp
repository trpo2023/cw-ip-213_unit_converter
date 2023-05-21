#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#include <iostream>
#include <conversion.h>
#include <Check_Error.h>
#include <Print_Error.h>

#define MAX_LENGTH 25

int main()
{
    char input[MAX_LENGTH];

    char HAVEunit[7];
    char WANTunit[7];
    char* ptrEnd;
    int uHLength = -1;
    int uWLength = 0;
    double result = 0;

    while (1) {
        printf("You have: ");
        fgets(input, MAX_LENGTH, stdin);

        Print_Error(Check_number(input));

        result = strtod(input, &ptrEnd);

        Print_Error(Check_space(input));

        for (int i = 1; *(ptrEnd + i) != '\0'; i++) {
            HAVEunit[i - 1] = *(ptrEnd + i);
            uHLength++;
        }
        printf("You want: ");
        fgets(WANTunit, 7, stdin);
        for (int i = 1; WANTunit[i] != '\0'; i++)
            uWLength++;

        if (Check_Units_Name(HAVEunit, uHLength, WANTunit, uWLength, result))
            Print_Error(Check_Units_Name(
                    HAVEunit, uHLength, WANTunit, uWLength, result));
        else
            result = Convert(HAVEunit, uHLength, WANTunit, uWLength, result);
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
