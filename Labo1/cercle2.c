#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

#define PI 3.14159

/*
 * Programme qui permet de calculer le
 * périmètre et l'aire d'un cercle.
 *
 * Version 2 avec utilisation de variables.
 */
int main()
{
    setlocale (LC_ALL, "");

    float rayon, perimetre, aire;

    printf ("Rayon ?");
    scanf ("%f", &rayon);

    perimetre = 2 * PI * rayon;
    aire = PI * rayon * rayon;
    
    printf("Périmètre = %fcm \n", perimetre);
    printf("Aire = %fcm² \n", aire);
}