#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main ()
{

    setlocale (LC_ALL, "");
    float ang, droit, math, prog, proj, total, pourcentage;

    printf ("Anglais (/30) ? ");
    scanf ("%f", &ang);

    printf ("Droit commercial (/30) ? ");
    scanf ("%f", &droit);

    printf ("Mathématiques (/30) ? ");
    scanf ("%f", &math);

    printf ("Programmation (/30) ? ");
    scanf ("%f", &prog);

    printf ("Projet d'entreprise (/30) ? ");
    scanf ("%f", &proj);
    printf ("\n\n\n");
    
    total = ang + droit + math + prog + proj;
    printf ("TOTAL = %.1f /150,0\n\n", total);

    pourcentage = total / 150 * 100;
    printf ("Pourcentage = %.1f %%", pourcentage);

}