/* VULLO Enzo 1AR23 */
#define _CRT_SECURE_NO_WARNINGS
/* Bibliothèques */
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Programme principal */
int main()
{
    setlocale(LC_ALL, "");

    int paquetInitial[52] = { 8, 2, 12, 11, 5, 5, 3, 7, 4, 8, 2, 1, 4, 9, 7, 13, 7, 5, 12, 3, 1, 13, 6, 9, 
    9, 6, 2, 9, 8, 6, 11, 10, 12, 1, 12, 13, 1, 3, 11, 4, 4, 2, 5, 10, 8, 10, 13, 7, 10, 6, 3, 11 };

    int paquet1[26] = {0}, paquet2[26] = {0}, pointJoueur = 10, pointIA = 10, userChoice;

    for (int i = 0, j = 0; i < 52; i = i + 2, j++)
    {
        paquet1[j] = paquetInitial[i];
    }
    for (int i = 1, j = 0; i <= 52; i = i + 2, j++)
    {
        paquet2[j] = paquetInitial[i];
    }

    printf("Joueur %d - %d IA\n\n", pointJoueur, pointIA);

    for(int i = 0; i < 26; i++)
    {
        printf("TOUR %d\n", i+1);
        printf("Paquet choisi ( 1 ou 2 ) ? ");
        scanf("%d", &userChoice);
        if (userChoice == 1)
        {
            printf("Votre carte = %d\n", paquet1[i]);
            printf("La carte de l'IA = %d\n", paquet2[i]);
            if (paquet1[i] > paquet2[i])
            {
                pointJoueur = pointJoueur + abs(paquet1[i]-paquet2[i]);
                pointIA = pointIA - abs(paquet1[i]-paquet2[i]);
            }
            else
            {
                pointJoueur = pointJoueur - abs(paquet1[i]-paquet2[i]);
                pointIA = pointIA + abs(paquet1[i]-paquet2[i]);
            }
        }
        else
        {
            printf("Votre carte = %d\n", paquet2[i]);
            printf("La carte de l'IA = %d\n", paquet1[i]);
            if (paquet2[i] > paquet1[i])
            {
                pointJoueur = pointJoueur + abs(paquet1[i]-paquet2[i]);
                pointIA = pointIA - abs(paquet1[i]-paquet2[i]);
            }
            else
            {
                pointJoueur = pointJoueur - abs(paquet1[i]-paquet2[i]);
                pointIA = pointIA + abs(paquet1[i]-paquet2[i]);
            }
        }
        printf("\n");
        printf("Joueur %d - %d IA\n\n", pointJoueur, pointIA);

        if(pointJoueur <= 0 || pointIA <= 0)
        {
            break;
        }
    }
    printf("PARTIE TERMINEE\n");
}