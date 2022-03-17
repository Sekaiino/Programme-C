#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

#define TVA 1.21

int main ()
{
    setlocale (LC_ALL, "");
    float qte, pu, htva, tvac;

    printf ("Quantité ?");
    scanf ("%f", &qte);

    printf ("Prix unitaire ?");
    scanf ("%f", &pu);

    htva = qte * pu;
    printf ("Prix HTVA = %.2feuros \n", htva);

    tvac = htva * TVA;
    printf ("Prix TVAC = %.2feuros \n", tvac);
}