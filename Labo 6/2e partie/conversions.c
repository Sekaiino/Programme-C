#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include "conversionsTests.h"

#define INCH 25.4
#define FOOT 304.8
#define YARD 914.4
#define MILE 1609344
#define LEAGUE 4828032

int estUniteAnglo(char unite);
float convertirAngloEnMm(float mesure, char unite);
void afficherMesureSI(float mesureEnMm);

int main()
{
    setlocale(LC_ALL, "");

    float mesure, mesureEnMm;
    char unite, uniteSI;
    
    printf("Unités anglo-saxonnes\n");
    printf("=====================\n");
    printf("i (inch)\n");
    printf("f (foot)\n");
    printf("y (yard)\n");
    printf("m (mile)\n");
    printf("l (league)\n\n");
    printf("Une mesure suivie de son unité ? ");
    scanf("%f  %c", &mesure, &unite);

    if (estUniteAnglo(unite) == true)
    {
        mesureEnMm = convertirAngloEnMm(mesure, unite);
        printf("%.3f %c = ", mesure, unite);
        afficherMesureSI(mesureEnMm);
    }
    else
    {
        printf("Unité anglo-saxonne inconnue !\n");
    }

}
int estUniteAnglo(char unite)
{
    unite = unite;

    if (unite == 'i' || unite == 'f' || unite == 'y' || unite == 'm' || unite == 'l')
    {
        return true;
    }
    else
    {
        return false;
    }
}
float convertirAngloEnMm(float mesure, char unite)
{
    mesure = mesure;
    unite = unite;

    if (unite == 'i')
    {
        mesure = mesure * INCH;
    }
    else if(unite == 'f')
    {
        mesure = mesure * FOOT;
    }
    else if(unite == 'y')
    {
        mesure = mesure * YARD;
    }
    else if(unite == 'm')
    {
        mesure = mesure * MILE;
    }
    else if(unite == 'l')
    {
        mesure = mesure * LEAGUE;
    }
    return mesure;
}
void afficherMesureSI(float mesureEnMm)
{
    mesureEnMm = mesureEnMm;

    if (mesureEnMm >= 1000000)
    {
        mesureEnMm = mesureEnMm / 1000000;
        printf("%.3f km\n", mesureEnMm);
    }
    else if(mesureEnMm >= 1000 && mesureEnMm < 1000000)
    {
        mesureEnMm = mesureEnMm / 1000;
        printf("%.3f m\n", mesureEnMm);
    }
    else
    {
        printf("%.3f mm\n", mesureEnMm);
    }
}