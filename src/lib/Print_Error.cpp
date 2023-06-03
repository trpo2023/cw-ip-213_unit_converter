#include <stdio.h>

void Print_Error(int n)
{
    if (n == 1)
        printf("Error: required unit not found!(You have)\n");
    if (n == 2)
        printf("Error: required unit not found!(You want)\n");
    if (n == 3)
        printf("Error: сonformability error\n");
    if (n == 4)
        printf("Error: a space was expected after the number!\n");
    if (n == 5)
        printf("Error: number expected first!\n");
    return;
}