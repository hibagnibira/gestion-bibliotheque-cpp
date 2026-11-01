#pragma once

#include "LIVRE.h"

#include <iostream>
using namespace std;

class Biblioteque
{
private :
	string nom;
	Livre** livre;
	int capacitemax;
	int nblivres;
	static int nbBibliotheques;

public :
	Biblioteque(string, int); // int pour capacitemax
	Biblioteque& operator=(const Biblioteque&);
	bool Ajouterlivre(const Livre&);
	bool operator+=(const Livre&);
	void rechercherLivre(int);
	void rechercherLivre(string); //par titre
	void Affichercataloge();
	~Biblioteque();
};

