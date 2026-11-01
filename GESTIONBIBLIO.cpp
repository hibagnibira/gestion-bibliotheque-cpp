
#include "Biblio.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "===== DEBUT DU PROGRAMME =====" << endl;

    // 1. Creation des dates
    Date d1(15, 5, 2020);
    Date d2(10, 8, 2022);
    Date d3(20, 3, 2024);

    // 2. Creation de la bibliotheque
    Biblioteque B1("Bibliotheque Universitaire", 5);

    // 3. Creation des livres
    Livre L1(0, "Dune", "Frank Herbert", d1);
    Livre L2(0, "1984", "George Orwell", d2);
    Livre L3(0, "Le Petit Prince", "Antoine de Saint-Exupery", d3);

    // Afficher le nombre de livres existants
    cout << "\nNombre de livres existants : "
        << Livre::getNbInstance() << endl;

    // 4. Ajouter les livres a la bibliotheque
    cout << "\n===== AJOUT DES LIVRES =====" << endl;

    B1.Ajouterlivre(L1);
    B1.Ajouterlivre(L2);
    B1 += L3;

    // 5. Enregistrer plusieurs notes
    cout << "\n===== ENREGISTREMENT DES NOTES =====" << endl;

    L1.AjouterNote(15);
    L1.AjouterNote(18);
    L1.AjouterNote(12);

    L2.AjouterNote(16);
    L2.AjouterNote(14);

    L3.AjouterNote(19);
    L3.AjouterNote(17);
    L3.AjouterNote(20);

    // 6. Recherche d'un livre existant
    cout << "\n===== RECHERCHE REUSSIE =====" << endl;

    B1.rechercherLivre("Dune");

    // 7. Recherche d'un livre inexistant
    cout << "\n===== RECHERCHE INFRUCTUEUSE =====" << endl;

    B1.rechercherLivre("Harry Potter");

    // 8. Affichage du catalogue
    cout << "\n===== AFFICHAGE DU CATALOGUE =====" << endl;

    B1.Affichercataloge();

    // 9. Affichage des informations et des moyennes
    cout << "\n===== MOYENNES DES LIVRES =====" << endl;

    L1.afficher();
    L2.afficher();
    L3.afficher();

    // 10. Nombre de livres existants
    cout << "\nNombre de livres existants : "
        << Livre::getNbInstance() << endl;

    cout << "\n===== FIN DU PROGRAMME =====" << endl;

    return 0;
}

