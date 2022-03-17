#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

int main ()
{

    setlocale (LC_ALL, "");
    int an, biss;

    printf (" Année ?"); 
    scanf ("%d", &an);
    printf ("\n\n");

    if (an % 400 == 0)
    {
        printf (" %d est une année bissextile. \n\n", an);
    }

    else if (an % 4 == 0 && an % 100 != 0)
    {
        printf (" %d est une année bissextile. \n\n", an);
    }

    else
    {
        printf (" %d n'est pas une année bissextile.\n\n ", an);
    }

}