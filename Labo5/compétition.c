#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int nombreAleatoire(int min, int max);

#define NB_MAX_EQUIPES 22

int main()
{
	setlocale(LC_ALL, "");

    char nomsEquipes[NB_MAX_EQUIPES], f;
    int nbEquipes, nbJournees, nbMatchsParJournee;
    int posAleat = nombreAleatoire(0, nbEquipes - 1);

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
    for (int i = 0; i < nbEquipes; i++)
    {
        f = nomsEquipes[i];
        nomsEquipes[i] = nomsEquipes[posAleat];
        nomsEquipes[posAleat] = f;
    }
    
    nbJournees = nbEquipes - 1;
    nbMatchsParJournee = nbEquipes / 2;

    for (int j = 1; j <= nbJournees; j++)
    {
        f = nomsEquipes[nbEquipes - 1];
        printf("\n");
        printf("Journée %d\n", j);

        for (int i = nbEquipes-1; i > 0; i--)
            {
                nomsEquipes[i] = nomsEquipes[i-1];
                if(i==1)
                {
                    nomsEquipes[1] = f;
                }
            }

        for (int k = 0, l = nbEquipes - 1; k < nbMatchsParJournee; k++, l--)
        {
            printf("%c - %c\n", nomsEquipes[k], nomsEquipes[l]);
        }
    }
}
int nombreAleatoire(int min, int max)
{
    static bool init = false;
    if (!init)
    {
        srand(time(NULL));
        init = true;
    }
    return rand() % (max - min + 1) + min;
}