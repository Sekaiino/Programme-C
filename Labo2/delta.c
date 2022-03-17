#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

int main ()
{

    setlocale (LC_ALL, "");
    int a, b, c, rho, x1, x2;

    printf (" Coefficients a, b et c ? ");
    scanf ("%d %d %d", &a, &b, &c);
    printf ("\n\n");

    rho = b * b - 4 * a * c;
    if (rho > 0)
    {
        x1 = (-b - sqrt (rho)) / (2 * a);
        x2 = (-b + sqrt (rho)) / (2 * a);
        printf (" %dx²+%dx+%d=0 possède deux solutions : %.1d et %.1d.\n\n ", a, b, c, x1, x2);
    }
    else if (rho == 0)
    {
        x1 = (-b) / (2 * a);
        printf (" %dx²+%dx+%d=0 possède une solution : %.1d.\n\n ", a, b, c, x1);
    }
    else if (rho < 0)
    {
        printf (" %dx²+%dx+%d=0 ne possède pas de solution.\n\n ", a,b,c);
    }
}