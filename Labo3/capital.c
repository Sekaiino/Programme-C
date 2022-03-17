#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

int main ()
{

    setlocale (LC_ALL, "");
    float capital, interet, result, an;
    an = 0;

    printf (" Capital à placer (en euros) ? ");
    scanf ("%f", &capital);
    printf (" Taux d'intérêt (en %%) ? ");
    scanf ("%f", &interet);
    
    result = capital;

    do
    {
        an = an + 1;
        result = result * (1 + (interet / 100));
        if (an == 1)
        {
            printf (" Après %.0f an = %.2f \n", an, result);
        }
        else if (an > 1)
        {
            printf (" Après %.0f ans = %.2f \n", an, result);
        }

    } while (!(result >= capital * 2));
    
}