#include "Date.h"
#include <iostream>
using namespace std;

// instructeur sans param parceque c'est une relation dde composition
//instructeur avec param (est valide pour bien initialiser par une valeur default)
Date::Date(int j, int m, int a)
{

	if (estValide(j, m, a)) {
	
		this->jour = j;
		this->mois = m;
		this->annee = a;

	}
	else {
		cout << "Date invalide !" << endl;
		this->jour = 1;
		this->mois = 1;
		this->annee = 2000;
	}
	
}

bool Date::estBissextile(int a)
{
	if (a % 4 == 0 && a % 100 !=0) return true;
	if (a % 400 == 0) return false;
	else return false;
}

// methode pour valider la date donnee (needs the bi one)
bool Date::estValide(int j, int m, int a)
{
	if (j < 0 || j>31 || m < 1 || m>12 || a < 1 || a>2026) {
		cout << "erreur" << endl;
		return false;
	}
	else {
		if (m == 2 && estBissextile(a) && j<=29) {
			return true;
		}
		if (m == 2 && estBissextile(a) == false && j <= 28) {
			return true;
		}
		if ((m == 4 || m == 6 || m == 8 || m == 10 || m == 12) && j <= 30) { return true; }
		if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 9 || m == 11) && j <= 31) { return true; }
		else {
			cout << "erreur" << endl;
			return false;
		
		}
	}
}

// afficher la date sans 
void Date::Consulter() const
{
	cout << this->jour << "/" << this->mois << "/" << this->annee << endl;
}

//destructeur date (ne fait rien parce que c'est une relation de composition)
Date::~Date()
{
}

bool Date::operator==(Date d)
{
	if (this->annee == d.annee && this->mois == d.mois && this->jour == d.jour) {
		return true;
	}
	else {
		return false;
	}
	
}

bool Date::operator<(Date d)
{
	if (this->annee < d.annee )  return true;
	if (this->annee == d.annee && this->mois < d.mois ) return true;
	if (this->annee == d.annee && this->mois == d.mois && this->jour < d.jour) {
		return true;
	}
	else return false;
	
}

