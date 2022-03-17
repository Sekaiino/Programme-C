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
    int borne, essais, SearchedVal, ans;
    srand (time(NULL));

    printf (" Nombre secret de 1 à ... ? ");
    scanf ("%d", &borne);

    printf (" Nombre d'essais ? ");
    scanf ("%d", &essais);

    if (borne < 1)
    {
        borne = 10;
        printf (" Valeur de borne incorrecte ! Nouvelle valeur = %d \n", borne);
        
    }
    else if ( essais < 1)
    {
        essais = sqrt (borne);
        printf (" Nombre d'essais incorrect ! Nouvelle valeur = %d \n", essais);
    }

    SearchedVal = rand() % borne;
    printf ("\n\n");

    do
    {
        
        essais = essais - 1;
        printf (" Nombre de 1 à %d ? ", borne);
        scanf ("%d", &ans);
        if (ans > SearchedVal)
        {
            printf (" Le nombre secret est plus petit, encore %d essai(s).\n\n", essais);
        }
        else if (ans < SearchedVal)
        {
            printf (" Le nombre secret est plus grand, encore %d essai(s).\n\n", essais);
        }

    } while (!(essais == 0 || ans == SearchedVal));

    if (essais == 0 && ans != SearchedVal)
    {
        printf (" Dommage ! Le nombre secret était %d. \n", SearchedVal);
    }
    else if (essais == 0 && ans == SearchedVal)
    {
        printf (" Félicitation ! Vous avez trouvé le nombre. \n");
    }
    else if (ans == SearchedVal)
    {
        printf (" Félicitation ! Vous avez trouvé le nombre. \n");
    }
    else if (essais == 0)
    {
        printf (" Dommage ! Le nombre secret était %d. \n", SearchedVal);
    }

}