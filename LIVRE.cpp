
#include "LIVRE.h"
#include "Date.h"

// Initialisation des attributs statiques
int Livre::compteurid = 0;
int Livre::nbinstance = 0;

// Constructeur
Livre::Livre(int id, string titre, string auteur, Date parution)
    : id(++compteurid), titre(titre), auteur(auteur),
    parution(parution)
{
    notes = nullptr;
    nbnotes = 0;
    disponible = true;

    nbinstance++;

    cout << "Livre cree : " << this->titre << endl;
}

// Constructeur de copie
Livre::Livre(const Livre& L)
    : id(++compteurid), titre(L.titre),
    auteur(L.auteur), parution(L.parution)
{
    nbnotes = L.nbnotes;
    disponible = L.disponible;

    if (nbnotes > 0)
    {
        notes = new int[nbnotes];

        for (int i = 0; i < nbnotes; i++)
        {
            notes[i] = L.notes[i];
        }
    }
    else
    {
        notes = nullptr;
    }

    nbinstance++;

    cout << "Copie du livre : " << titre << endl;
}

// Operateur d'affectation
bool Livre::operator=(const Livre L)
{
    if (this == &L)
        return true;

    // Copier les informations
    titre = L.titre;
    auteur = L.auteur;
    parution = L.parution;
    disponible = L.disponible;

    // Liberer l'ancien tableau
    delete[] notes;

    // Copier les notes
    nbnotes = L.nbnotes;

    if (nbnotes > 0)
    {
        notes = new int[nbnotes];

        for (int i = 0; i < nbnotes; i++)
        {
            notes[i] = L.notes[i];
        }
    }
    else
    {
        notes = nullptr;
    }

    return true;
}

double Livre::calculerMoyenne() const
{
    if (nbnotes == 0)
        return 0.0;

    int somme = 0;

    for (int i = 0; i < nbnotes; i++)
    {
        somme += notes[i];
    }

    return (double)somme / nbnotes;
}

void Livre::afficher() const
{
    cout << "\n========== INFORMATIONS DU LIVRE ==========" << endl;
    cout << "ID : " << id << endl;
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << endl;

    cout << "Date de parution : ";
    parution.Consulter();

    cout << "Disponibilite : ";

    if (disponible)
        cout << "Disponible" << endl;
    else
        cout << "Non disponible" << endl;

    cout << "Notes : ";
    if (nbnotes == 0)
    {
        cout << "Aucune note" << endl;
    }
    else
    {
        for (int i = 0; i < nbnotes; i++)
        {
            cout << notes[i] << " ";
        }

        cout << endl;
    }
    cout << "Moyenne : " << calculerMoyenne() << endl;

    cout << "===========================================" << endl;
}


int Livre::getId() const
{
    return id;
}

string Livre::getTitre() const
{
    return titre;
}

void Livre::AjouterNote(int note)
{
    if (note < 0 || note > 20)
    {
        cout << "Note invalide !" << endl;
        return;
    }

    int* nouveau = new int[nbnotes + 1];

    for (int i = 0; i < nbnotes; i++)
    {
        nouveau[i] = notes[i];
    }

    nouveau[nbnotes] = note;

    delete[] notes;

    notes = nouveau;
    nbnotes++;
}

int Livre::getNbInstance()
{
    return nbinstance;
}

// Destructeur
Livre::~Livre()
{
    delete[] notes;
    nbinstance--;

    cout << "Livre detruit : " << titre << endl;
}
