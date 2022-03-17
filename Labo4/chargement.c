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
    float max, mtot, mcaisse, nbcaisse;

    printf (" Charge maximale en kg ? ");
    scanf ("%f", &max);
    printf ("\n\n");

    mtot = 0;
    nbcaisse = 0;

    while (mtot < max)
    {

        nbcaisse = nbcaisse + 1;

        printf (" Caisse %.0f en kg ? ", nbcaisse);
        scanf ("%f", &mcaisse);

        mtot = mtot + mcaisse;

    }

    mtot = mtot - mcaisse;
    nbcaisse = nbcaisse - 1;

    printf (" le chargement contient %.0f caisse(s) \n ", nbcaisse);
    printf(" La charge vaut %.1f kg \n ", mtot);

}