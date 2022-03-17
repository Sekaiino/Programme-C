// VULLO Enzo 1AR23
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

void main ()
{

    setlocale (LC_ALL, "");

    float poids, prix, prixtot, reduction;
    int nbrcolis, colis;

    prixtot = 0;
    reduction = 0;

    printf (" Nombre de colis à envoyer ? ");
    scanf ("%d", &nbrcolis);

    while (nbrcolis <= 0)
    {
        printf ("Le nombre de colis à envoyer doit être supérieur à 0. Recommencez... \n");
        printf (" Nombre de colis à envoyer ? ");
        scanf ("%d", &nbrcolis);
    }

    colis = 0;

    do
    {
        colis = colis + 1;

        printf (" Poids du colis %d (en kg) ? ", colis);
        scanf ("%f", &poids);

         while (poids > 30)
         {
            printf (" Poids du colis incorrect ! Recommencez...\n ");
            printf (" Poids du colis %d (en kg) ? ", colis);
            scanf ("%f", &poids);
         }

        if (poids > 0 && poids <= 2)
        {
            prix = 7.20;
        }
        else if (poids > 2 && poids <= 10)
        {
            prix = 9.64;
        }
        else if (poids > 10 && poids <= 30)
        {
            prix = 12.07;
        }

        printf (" Tarif = %f EUR\n ", prix);
        printf ("\n");
        
        prixtot = prixtot + prix;
            
    } while (!(colis == nbrcolis));
    
    if (nbrcolis >= 10)
    {
        reduction = prixtot / 100 * 5;
        prixtot = prixtot - reduction;
    }

    printf ("\n");
    printf (" Réduction = %.2f EUR.\n ", reduction);
    printf (" Montant total à payer = %.2f EUR.\n ", prixtot);

    _getch ()
}