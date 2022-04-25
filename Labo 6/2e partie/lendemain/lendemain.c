#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include "date.h"
#include "date.c"
#include "dateTests.h"
#include "dateTests.c"

int main()
{
    setlocale(LC_ALL, "");
    int jour = jourAjd(), mois = moisAjd(), annee = anneeAjd();

    printf("La date du jour est le ");
    afficherDate(jour, mois, annee);
    

}