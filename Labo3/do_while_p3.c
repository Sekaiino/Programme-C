#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

int main ()
{

    setlocale (LC_ALL, "");
    char c, result;

    do
    {
        printf (" Aimez-vous programmer : (O)ui, (N)on ?");
        scanf (" %c", &c);
        result = tolower (c);

    } while (!(result == 'o' || result == 'n'));

    if (result == 'o')
    {
        printf (" Super :-)\n\n");
    }
    else if (result == 'n')
    {
        printf (" Dommage :-(\n\n");
    }

}