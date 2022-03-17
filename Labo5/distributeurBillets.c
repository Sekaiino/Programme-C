#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define NB_VALEURS_BILLET 6

int main()
{
	setlocale(LC_ALL, "");

    // Variable pour le montant à retirer
    int montant;
    
    // Variables pour les quantités
    int quantitesParBillet[NB_VALEURS_BILLET]={0, 0, 0, 0, 0, 0}, valeursBillet[NB_VALEURS_BILLET]={500, 200, 100, 50, 20, 10}, 
		quantitesDispoParBillet[NB_VALEURS_BILLET], i;

	// Variable pour le choix de l'utilisateur	
	char c;

	c = 'c';

	for(i = 0; i < NB_VALEURS_BILLET; i++)
	{
		quantitesDispoParBillet[i] = 5;
	}

    while (c == 'c')
	{
		// Acquisition
		printf("Montant ? ");
		scanf("%d", &montant);

		while(montant % valeursBillet[NB_VALEURS_BILLET - 1] != 0)
		{
			printf("Montant incorrect !\n");
			printf("Montant ? ");
			scanf("%d", &montant);
		}

		// Traitement
		for(i = 0; i < NB_VALEURS_BILLET; i++)
		{
			quantitesParBillet[i] = montant / valeursBillet[i];
			montant = montant % valeursBillet[i];

			if(quantitesParBillet[i] <= 5 && quantitesDispoParBillet[i] > 0)
			{
				quantitesDispoParBillet[i] = quantitesDispoParBillet[i] - quantitesDispoParBillet[i];
			}
			else if(quantitesDispoParBillet[i] <= 0)
			{
				printf("Billets disponibles insuffisants !\n");
				break;
			}
			if(quantitesParBillet[i] != 0)
			{
				printf("%d fois %d EUR\n",quantitesParBillet[i], valeursBillet[i]);
			}
		}
		
		printf("(C)ontinuer, (q)uitter ? ");
		scanf(" %c", &c);
		c = tolower(c);
		
		while(c != 'c' || c != 'q')
		{
			printf("(C)ontinuer, (q)uitter ? ");
			scanf(" %c", &c);
			c = tolower(c);
		}
	}
}