#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main ()
{

    setlocale (LC_ALL, "");
    float kelvin, farhenheit, t;

    printf ("Température en degrés Celsius ? ");
    scanf ("%f", &t);
    printf ("\n\n");

    // Valeur Kelvin/Farhenheit pour t-1
    kelvin = (t-1) + 273.15;
    farhenheit = (t-1) * 9/5 + 32;

    printf(" Celsius |  Kelvin | Fahrenheit\n");
    printf (" %7.2f | %7.2f | %7.2f\n", (t-1), kelvin, farhenheit);
    
    // Valeur Kelvin/Farhenheit pour t
    kelvin = t + 273.15;
    farhenheit = t * 9/5 + 32;

    printf (" %7.2f | %7.2f | %7.2f\n", t, kelvin, farhenheit);

    // Valeur Kelvin/Farhenheit pour t+1
    kelvin = (t+1) + 273.15;
    farhenheit = (t+1) * 9/5 + 32;

    printf (" %7.2f | %7.2f | %7.2f\n", (t+1), kelvin, farhenheit);
    printf ("\n\n");

}