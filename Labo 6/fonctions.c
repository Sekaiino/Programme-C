#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdbool.h> 

/* Déclarations des fonctions */

/// <summary>Vérifier la validité d'un jour donné par l'utilisateur.</summary>
/// <param name=jour">Entier saisi par l'utilisateur.</param>
/// <returns>Booléens Vrai si jour valide Faux sinon.</returns>
int jourValide(int jour);

/// <summary>Vérifier la validité d'un mois donné par l'utilisateur.</summary>
/// <param name=mois">Entier saisi par l'utilisateur.</param>
/// <returns>Booléens Vrai si mois valide Faux sinon.</returns>
int moisValide(int mois);

/// <summary>Vérifier la validité d'une annee donné par l'utilisateur.</summary>
/// <param name=annee">Entier saisi par l'utilisateur.</param>
/// <returns>Booléens Vrai si annee valide Faux sinon.</returns>
int anneeValide(int annee);

/// <summary>Vérifier la validité d'une date donnée par l'utilisateur.</summary>
/// <param name=jour">Entier jour saisi par l'utilisateur.</param>
/// <param name=mois">Entier mois saisi par l'utilisateur.</param>
/// <param name=annee">Entier annee saisi par l'utilisateur.</param>
/// <returns>Booléens Vrai si date valide Faux sinon.</returns>
int dateValide(int jour, int mois, int annee);

/// <summary>Donner le numéro du jour d'une date donnée par l'utilisateur.</summary>
/// <param name=jour">Entier jour saisi par l'utilisateur.</param>
/// <param name=mois">Entier mois saisi par l'utilisateur.</param>
/// <param name=annee">Entier annee saisi par l'utilisateur.</param>
/// <returns>Numéro du jour de la date de l'utilisateur.</returns>
int numeroJourSemaine(int jour, int mois, int annee);

/// <summary>Donner le nom du jour d'une date donnée par l'utilisateur.</summary>
/// <param name=jour">Entier jour saisi par l'utilisateur.</param>
/// <param name=mois">Entier mois saisi par l'utilisateur.</param>
/// <param name=annee">Entier annee saisi par l'utilisateur.</param>
/// <returns>Nom du jour de la date de l'utilisateur.</returns>
int afficherJourDeLaSemaine(int numeroJour);

/* Programme principal */
int main()
{
    setlocale(LC_ALL, "");

    int jour, mois, annee, numeroJour;
    printf("Résultats = %d \n", dateValide(jour, mois, annee));
    printf("Numéro du jour de la semaine = %d \n", numeroJourSemaine(jour, mois, annee));
    afficherJourDeLaSemaine(numeroJour);


}
/* Définitions des fonctions */

int jourValide(int jour)
{
    if(jour >0 && jour < 32)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int moisValide(int mois)
{
    if(mois>0 && mois<13)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int anneeValide(int annee)
{
    if(annee>1582 && annee<10000)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int dateValide(int jour, int mois, int annee)
{
    printf("Date (dd/mm/aaaa) ? ");
    scanf("%d/%d/%d", &jour, &mois, &annee);

    if(jourValide(jour) == true && moisValide(mois) == true && anneeValide(annee) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int numeroJourSemaine(int jour, int mois, int annee)
{
    int c, a, m, j;

    c = (14 - mois) / 12;
    a = annee - c;
    m = mois + 12 * c - 2;

    return j = (jour + a + a / 4 - a / 100 + a / 400 + 31 * m / 12) % 7;
}
int afficherJourDeLaSemaine(int numeroJour)
{
    int j;

    numeroJour = j;
    switch (numeroJour)
    {
    case 0:
        printf("Jour = Dimanche\n");
        break;
    
    case 1:
        printf("Jour = Lundi\n");
        break;

    case 2:
        printf("Jour = Mardi\n");
        break;

    case 3:
        printf("Jour = Mercredi\n");
        break;

    case 4:
        printf("Jour = Jeudi\n");
        break;

    case 5:
        printf("Jour = Vendredi\n");
        break;

    case 6:
        printf("Jour = Samedi\n");
        break;
    }

}