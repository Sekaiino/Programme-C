#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "");

    int entiers[5] = { 15, -9, 4, 26 }, i, position;

    printf("a) Affichage des éléments sans boucle.\n");

    printf("entiers[0] = %d\n", entiers[0]);
    printf("entiers[1] = %d\n", entiers[1]);
    printf("entiers[2] = %d\n", entiers[2]);
    printf("entiers[3] = %d\n", entiers[3]);
    printf("entiers[4] = %d\n", entiers[4]);

    printf("b) Débordement de tableau.\n");

    printf("entiers[-1] = %d\n", entiers[-1]);
    printf("entiers[5] = %d\n", entiers[5]);

    printf("c) Affichage des éléments avec une boucle.\n");

    for(i = 0; i < 5; i++)
    {
        printf("entiers[%d] = %d\n", i, entiers[i]);
    }

    printf("d) Affichage d'un élément sur base de sa position.\n");

    printf("Position (de 0 à 4) ? ");
    scanf("%d", &position);
    while(position < 0 || position > 4)
    {
        printf("Position incorrecte !\n");
        printf("Position (de 0 à 4) ? ");
        scanf("%d", &position);
    }
    printf("entiers[%d] = %d\n", position, entiers[position]);

}