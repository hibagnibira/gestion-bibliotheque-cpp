
#include "Biblio.h"

// Initialisation de l'attribut statique
int Biblioteque::nbBibliotheques = 0;


// Constructeur
Biblioteque::Biblioteque(string nom, int capacitemax)
{
    this->nom = nom;
    this->capacitemax = capacitemax;

    nblivres = 0;

    livre = new Livre * [capacitemax];

    for (int i = 0; i < capacitemax; i++)
    {
        livre[i] = nullptr;
    }

    nbBibliotheques++;

    cout << "Bibliotheque creee : " << nom << endl;
}


// Operateur d'affectation
Biblioteque& Biblioteque::operator=(const Biblioteque& B)
{
    if (this == &B)
        return *this;

    // Liberer l'ancienne memoire
    for (int i = 0; i < nblivres; i++)
    {
        delete livre[i];
    }

    delete[] livre;

    // Copier les attributs
    nom = B.nom;
    capacitemax = B.capacitemax;
    nblivres = B.nblivres;

    // Allocation du nouveau tableau
    livre = new Livre * [capacitemax];

    for (int i = 0; i < capacitemax; i++)
    {
        livre[i] = nullptr;
    }

    // Copie profonde des livres
    for (int i = 0; i < nblivres; i++)
    {
        livre[i] = new Livre(*B.livre[i]);
    }

    return *this;
}


// Ajouter un livre
bool Biblioteque::Ajouterlivre(const Livre& L)
{
    if (nblivres >= capacitemax)
    {
        cout << "Bibliotheque pleine !" << endl;
        return false;
    }

    livre[nblivres] = new Livre(L);

    nblivres++;

    cout << "Livre ajoute avec succes !" << endl;

    return true;
}


// Operateur +=
bool Biblioteque::operator+=(const Livre& L)
{
    return Ajouterlivre(L);
}


// Recherche par ID
void Biblioteque::rechercherLivre(int id)
{
    for (int i = 0; i < nblivres; i++)
    {
        if (livre[i]->getId() == id)
        {
            cout << "Livre trouve !" << endl;
            livre[i]->afficher();
            return;
        }
    }

    cout << "Aucun livre trouve avec cet ID." << endl;
}


// Recherche par titre
void Biblioteque::rechercherLivre(string titre)
{
    for (int i = 0; i < nblivres; i++)
    {
        if (livre[i]->getTitre() == titre)
        {
            cout << "Livre trouve !" << endl;
            livre[i]->afficher();
            return;
        }
    }

    cout << "Aucun livre trouve avec ce titre." << endl;
}


// Afficher le catalogue
void Biblioteque::Affichercataloge()
{
    cout << "\n========== CATALOGUE ==========" << endl;

    cout << "Nom : " << nom << endl;

    cout << "Nombre de livres : "
        << nblivres << "/" << capacitemax << endl;

    for (int i = 0; i < nblivres; i++)
    {
        livre[i]->afficher();
    }

    cout << "===============================" << endl;
}


// Destructeur
Biblioteque::~Biblioteque()
{
    for (int i = 0; i < nblivres; i++)
    {
        delete livre[i];
    }

    delete[] livre;

    nbBibliotheques--;

    cout << "Bibliotheque detruite : " << nom << endl;
}
