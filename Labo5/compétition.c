#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define NB_MAX_EQUIPES 22

int main()
{
	setlocale(LC_ALL, "");

    char nomsEquipes[NB_MAX_EQUIPES];
    int nbEquipes, nbJournees, nbMatchsParJournee;

    printf("Nombre d’équipes (de 2 à 22) ? ");
    scanf("%d", &nbEquipes);
    while(nbEquipes < 2 || nbEquipes > 22 || nbEquipes % 2 != 0)
    {
        printf("Le nombre d'équipes doit être pair et compris entre 2 et 22 ! \n");
        printf("Nombre d’équipes (de 2 à 22) ? ");
        scanf("%d", &nbEquipes);
    }

    for (int i = 0, nomEquipe = 'A'; i < nbEquipes; i++, nomEquipe++)
    {
        nomsEquipes[i] = nomEquipe;
    }
    
    nbJournees = nbEquipes - 1;
    nbMatchsParJournee = nbEquipes / 2;

    for (int j = 1; j <= nbJournees; j++)
    {
        printf("Journée %d\n", j);

        for (int k = 0, l = nbEquipes - 1; k < nbMatchsParJournee; k++, l--)
        {
            for (int i = nbEquipes; i > 0; i--)
            {
                if (i == 1)
                {
                    nomsEquipes[i] = nomsEquipes[nbEquipes];
                }
                else
                {
                    nomsEquipes[i] = nomsEquipes[i - 1];
                }
            }
            if (k == 2)
            {
                printf("%c - %c\n\n", nomsEquipes[k], nomsEquipes[l]);
            }
            else
            {
                printf("%c - %c\n", nomsEquipes[k], nomsEquipes[l]);
            }
        }
    }
}