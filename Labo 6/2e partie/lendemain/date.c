#include "date.h"

int jourAjd()
{
	time_t maintenant;
	struct tm aujourdhui;

	time(&maintenant);
	aujourdhui = *localtime(&maintenant);

	return aujourdhui.tm_mday;
}

int moisAjd()
{
	time_t maintenant;
	struct tm aujourdhui;

	time(&maintenant);
	aujourdhui = *localtime(&maintenant);

	return aujourdhui.tm_mon + 1;
}

int anneeAjd()
{
	time_t maintenant;
	struct tm aujourdhui;

	time(&maintenant);
	aujourdhui = *localtime(&maintenant);

	return aujourdhui.tm_year + 1900;
}

void dateAjd(int *jour, int *mois, int *annee)
{
	time_t maintenant;
	struct tm aujourdhui;

	time(&maintenant);
	aujourdhui = *localtime(&maintenant);

	*jour = aujourdhui.tm_mday;
	*mois = aujourdhui.tm_mon + 1;
	*annee = aujourdhui.tm_year + 1900;
}

void afficherDate(int jour, int mois, int annee)
{
	printf("%02d/%02d/%02d", jour, mois, annee);
}