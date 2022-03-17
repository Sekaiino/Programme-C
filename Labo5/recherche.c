#define _CRT_SECURE_NO_WARNINGS

#include <locale.h> 
#include <stdio.h>
#define NB_VALEURS 10

int main()
{
    setlocale(LC_ALL, "");

    int valeurs[NB_VALEURS] = { 15, -9, 4, 26, 0, -11, -3, 26, 26, -9 }, valRech, i, j, nbVal[NB_VALEURS], p;

    printf("Valeur recherchée ? ");
    scanf("%d", &valRech);

    j = 0;
    /* i = 0;

    while(i < NB_VALEURS && valeurs[i] != valRech)
    {
        i = i + 1;
    }

    if (i < NB_VALEURS)
    {
        printf("Valeur trouvée à la position %d", i);
    }
    else
    {
        printf("Valeur non trouvée ! ");
    } */

    for(i = 0; i < NB_VALEURS; i++)
    {
        if(valeurs[i] == valRech)
        {
            j = j + 1;
            nbVal[j] = i;
        }
    }

    if (j == 1)
    {
        printf("Valeur trouvée %d fois à la position : %d\n", j, nbVal[j]);
    }
    else if (j > 1)
    {
        printf("Valeur trouvée %d fois aux positions : ", j);

        for(i = 1; i < j + 1; i++)
        {
            if(i == j)
            {
                printf("%d.\n", nbVal[i]);
            }
            else
            {
                printf("%d, ", nbVal[i]);
            }
        }
    }
    else
    {
        printf("Valeur non trouvée !\n");
    }
    
}