#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main ()
{

    setlocale (LC_ALL, "");
    int x, result1, result2;

    do
    {

        printf (" Un entier non divisible par 2 ou 3 ? ");
        scanf ("%d", &x);
        result1 = x % 2;
        result2 = x % 3;
        printf ("\n");

    }
    while (!(x > 0 && result1 > 0 && result2 > 0));

    printf (" Nombre correct.\n\n ");

}