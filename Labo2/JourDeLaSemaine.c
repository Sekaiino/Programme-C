#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

int main ()
{

    setlocale (LC_ALL, "");
    int jour, mois, annee, c, j, m, a;
    

    printf (" Date (j m a) ? ");
    scanf ("%d %d %d", &jour, &mois, &annee);

    if ( jour < 1 || jour > 31 || mois < 1 || mois > 12 || annee < 1583 || annee > 9999)
    {
        printf (" Date incorrecte !\n\n");
    }

    else
    {
        c = (14 - mois) / 12;
        a = annee - c;
        m = mois + 12 * c - 2;
        j = (jour + a + a / 4 - a / 100 + a / 400 + 31 * m / 12) % 7;
    
        switch (j)
        {
            case 0:
            printf (" Le %d/%d/%d est un dimanche. \n\n", jour, mois, annee);
            break;

            case 1:
            printf (" Le %d/%d/%d est un lundi. \n\n", jour, mois, annee);
            break;

            case 2:
            printf (" Le %d/%d/%d est un mardi. \n\n", jour, mois, annee);
            break;

            case 3:
            printf (" Le %d/%d/%d est un mercredi. \n\n", jour, mois, annee);
            break;

            case 4:
            printf (" Le %d/%d/%d est un jeudi. \n\n", jour, mois, annee);
            break;

            case 5:
            printf (" Le %d/%d/%d est un vendredi. \n\n", jour, mois, annee);
            break;

            case 6:
            printf (" Le %d/%d/%d est un samedi. \n\n", jour, mois, annee);
            break;
        }
    }

}