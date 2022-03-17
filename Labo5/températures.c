#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define NB_MAX_JOUR 31

int main()
{
	setlocale(LC_ALL, "");

    float temperatures[NB_MAX_JOUR], max, min, bInf, bSup;

    int nbJours, i, lgPeriode, lgPeriodeMax, nbTemp, dbPeriode;

    nbJours = 31;

    while (nbJours <= 0 || nbJours > 31)
    {
        printf("Nombre de jours (de 1 à 31) ? ");
        scanf("%d", &nbJours);
    }

    for(i = 0; i < nbJours; i++)
    {
        printf("Jour %d ? ", i+1);
        scanf("%f", &temperatures[i]);
    }

    printf("Intervalle de températures ? ");
    scanf("%f %f", &bInf, &bSup);

    max = temperatures[0];
    min = temperatures[0];
    lgPeriode = 0;
    lgPeriodeMax = 0;
    nbTemp = 0;

    for(i = 0; i < nbJours; i++)
    {
        if(temperatures[i] > max)
        {
            max = temperatures[i];
        }
        else if(temperatures[i] < min)
        {
            min = temperatures[i];
        }
        if(temperatures[i] >= bInf && temperatures[i] <= bSup)
        {
            lgPeriode = lgPeriode + 1;
            nbTemp = nbTemp + 1;
            dbPeriode = i;
            
            if(lgPeriode > lgPeriodeMax)
            {
                lgPeriodeMax = lgPeriode;
            }
        }
        else
        {
            lgPeriode = 0;
        }
    }

    printf("Température max. = %.1f\n", max);
    printf("Température min. = %.1f\n", min);

    printf("Nombre de températures comprises dans l'intervalle = %d\n", nbTemp);
    printf("Durée en jours de la plus longue période = %d\n", lgPeriodeMax);
    printf("Températures de la plus longue période = ");
    
    for(i = 0; i < lgPeriodeMax; i++)
    {
        if(i == lgPeriodeMax - 1)
        {
            printf("%.1f.\n", temperatures[dbPeriode]);
        }
        else
        {
            printf("%.1f, ", temperatures[dbPeriode]);
        }
        dbPeriode = dbPeriode - 1;
    }
}    