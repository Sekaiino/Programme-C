#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main ()
{

    setlocale (LC_ALL, "");
    float x, result;

    do
    {

        printf (" Un réel compris entre -10 et 10 ? ");
        scanf ("%f", &x);
        result = fabs (x);
        printf ("\n");

    } while (result >= 0 && result > 10);

    printf (" Nombre correct.\n\n ");
    
}