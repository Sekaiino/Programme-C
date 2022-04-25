#ifndef __DATE_H
#define __DATE_H

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
#include <stdbool.h>

/// <summary>Retourne la valeur du jour du mois de la date actuelle.</summary>
/// <returns>La valeur du jour du mois comprise entre 1 & 31.</returns>
int jourAjd();

/// <summary>Retourne la valeur du mois de la date actuelle.</summary>
/// <returns>La valeur du mois comprise entre 1 & 12.</returns>
int moisAjd();

/// <summary>Retourne la valeur de l'annee de la date actuelle.</summary>
/// <returns>La valeur complete de l'annee (2020 et non 20).</returns>
int anneeAjd();

/// <summary>Retourne la valeur de la date actuelle.</summary>
/// <remarks>Cette fonction utilise la technique des pointeurs pour "retourner" 3 valeurs.</remarks>
/// <param name="jour">L'adresse a laquelle la valeur du jour doit etre ecrite.</param>
/// <param name="mois">L'adresse a laquelle la valeur du mois doit etre ecrite.</param>
/// <param name="annee">L'adresse a laquelle la valeur de l'annee doit etre ecrite.</param>
void dateAjd(int *jour, int *mois, int *annee);

/// <summary>Affiche une date sous la forme jj/mm/[aa]aa.</summary>
/// <param name="jour">La valeur du jour.</param>
/// <param name="mois">La valeur du mois.</param>
/// <param name="annee">La valeur de l'annee.</param>
void afficherDate(int jour, int mois, int annee);

bool estBissextile(int annee);

int dernierJourDuMois(int mois, int annee);

bool dateValide(int jour, int mois, int annee);

#endif 