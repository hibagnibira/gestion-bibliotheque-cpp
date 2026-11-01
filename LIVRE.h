#include "Date.h"
#pragma once

#include <iostream>
using namespace std;

class Livre
{
private :
	int const id;
	string titre;
	string auteur;
	Date parution;

	int* notes;
	int nbnotes;
	bool disponible;
	static int compteurid;
	static int nbinstance;


public:
	Livre(int const, string, string, Date);
	Livre(const Livre&);
    bool operator=(const Livre);
	double calculerMoyenne() const;
	void afficher() const;
	int getId() const;
	string getTitre() const;
	void AjouterNote(int note);
	static int getNbInstance();
	~Livre();

}; 
