#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main ()
{

    setlocale (LC_ALL, "");
    int a, b, c, max;

    printf (" Trois entiers ? ");
    scanf ("%d %d %d", &a, &b, &c);
    printf ("\n\n");

    if ( a > b && a > c)
    {
        max = a;
    }

    else if (b > a && b > c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    printf (" Le maximum est %d", max);
    printf ("\n\n");

}