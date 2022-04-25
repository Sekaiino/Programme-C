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
bool estBissextile(int annee)
{
	if (annee % 400 == 0 || annee % 4 == 0 && annee % 100 != 0)
	{
		return true;
	}
	else
	{
		return false;

	}
}
int dernierJourDuMois(int mois, int annee)
{
	int dernier_jour;

	if (estBissextile(annee) == true && mois == 2)
	{
		dernier_jour = 29;
	}
	else if(estBissextile(annee) == false && mois == 2)
	{
		dernier_jour = 28;
	}
	else if (mois != 2 && mois % 2 == 1)
	{
		dernier_jour == 31;
	}
	else if(mois != 2 && mois % 2 == 0)
	{
		dernier_jour = 30;
	}
	return dernier_jour
}
bool dateValide(int jour, int mois, int annee)
{
	
}