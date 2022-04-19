#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include "date.h"
#include "dateTests.h"

int main()
{
    setlocale(LC_ALL, "");
    int jour, mois, annee;

    jour = jourAjd();
    mois = moisAjd();
    annee = anneeAjd();

    printf("La date du jour est le ");
    afficherDate(jour, mois, annee);
}