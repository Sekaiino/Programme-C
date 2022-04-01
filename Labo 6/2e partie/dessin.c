#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdbool.h>

void afficherLigne(char car, int largeur);
void nouvelleLigne();
void afficherRectangle(char car, int largeur, int hauteur);
void afficherCarre(char car, int taille);
void afficherTriangle(char car, int hauteur);

int main ()
{
    setlocale(LC_ALL, "");
}
void afficherLigne(char car, int largeur)
{
    for (int i=0; i < largeur; i++)
    {
        printf("%c", car);
    }
}
void nouvelleLigne()
{
    printf("\n");
}
void afficherRectangle(char car, int largeur, int hauteur)
{
    for (int i=0; i < hauteur; i++)
    {
        afficherLigne(car, largeur);
        nouvelleLigne();
    }
}
void afficherCarre(char car, int taille)
{
    int largeur, hauteur;

    largeur = taille;
    hauteur = taille;

    afficherRectangle(car, largeur, hauteur);
}
void afficherTriangle(char car, int hauteur)
{
    int largeur, nbCar = 1;

    for(int i=0; i < hauteur; i++)
    {
        nbCar = nbCar + 2;
    }
}