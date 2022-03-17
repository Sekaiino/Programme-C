#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int main ()
{

    setlocale (LC_ALL, "");
    srand (time(NULL));
    int tour, val1, val2, val, nbcorr, rep;
    float moyenne;
    nbcorr = 0;
    tour = 0;

    printf (" Programme de calcul mental \n");
    printf (" -------------------------- \n\n");

    do
    {
        tour = tour + 1;
        val1 = rand() % 10 +1;
        val2 = rand() % 10 + 1;
        val = val1 * val2;

        printf (" %d * %d = ", val1, val2);
        scanf ("%d", &rep);

        if (rep == val)
        {
            nbcorr = nbcorr + 1;
            printf (" Réponse correcte.\n");
            printf (" Votre résultat = %d sur %d\n\n ", nbcorr, tour);
        }
        else
        {
            printf (" Réponse incorrecte !\n");
            printf (" Votre résultat = %d sur %d\n\n ", nbcorr, tour);
        }
        

    } while (!(nbcorr == 5));
    
    moyenne = (5 * 100) / tour;
    printf (" Votre pourcentage de réussite est de %.1f %%\n ", moyenne);
    
}