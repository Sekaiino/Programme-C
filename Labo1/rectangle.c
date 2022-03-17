#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main ()
{

    setlocale (LC_ALL, "");
    int lon, larg, diag, peri, aire;

    printf (" Longueur et largeur du rectangle ? ");
    scanf ("%d %d", &lon, &larg);

    if (lon <= 0 || larg <= 0)
    {
        printf (" Données incorrects !\n");
    }

    else
    {
        diag = sqrt (lon * lon + larg * larg);
        peri = (lon + larg) * 2;
        aire = lon * larg;

        printf ("\n\n\n");
        printf (" Diagonale = %d cm \n\n", diag);
        printf (" Périmètre = %d cm \n\n", peri);
        printf (" Aire = %d cm² \n\n", aire);
    }

}