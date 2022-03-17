#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>

int main ()
{

    setlocale(LC_ALL, "");

    float vitEnMops, vitEnMbps, tailleEnMo;
    int dureeEnSec, h, m, s;
    char c;

    printf("+-----------------+\n");
    printf("| UPLOAD/DOWNLOAD |\n");
    printf("+-----------------+\n\n");

    do {

        printf("(E)nvoi ou (T)éléchargement ? ");
        scanf(" %c", &c);
        c = tolower(c);

    } while(c != 'e' && c != 't');
    printf("\n\n");

    if (c == 't')
    {
        printf("Vitesse de téléchargement (en Mbps) ? ");
    }
    else
    {
        printf("Vitesse d'envoi (en Mbps) ? ");
    }
    scanf("%f", &vitEnMbps);
    

    vitEnMops = vitEnMbps / 8;

    printf("Taille du fichier (en Mo) ? ");
    scanf("%f", &tailleEnMo);
    printf("\n\n");

    dureeEnSec = tailleEnMo / vitEnMops;
    h = dureeEnSec / 3600;
    dureeEnSec = dureeEnSec % 3600;
    m = dureeEnSec / 60;
    s = dureeEnSec % 60;

    if (c == 't')
    {
        printf("La durée de téléchargement est de %d:%.2d:%.2d\n\n", h, m, s); 
    }
    else
    {
        printf("La durée d'envoi est de %d:%.2d:%.2d\n\n", h, m, s);
    }

    printf("Appuyez sur une touche pour quitter l'application...\n");
}