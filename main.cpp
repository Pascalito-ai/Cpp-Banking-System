#include <iostream>
#include "banque.h"
#include "compte.h"
#include "Money.h"

using namespace std;

int main() {
    Banque maBanque;

    // Quelques devises
    Money m_eur(100, EUR);
    Money m_usd(500, USD); // ~475 EUR

    // Creation des comptes
    Compte* c1 = new Compte("Mickael", 1000.0);
    // Compte avec plafond : Limite a 2000, solde actuel 200
    CompteLimite* c2 = new CompteLimite("Pierre", 2000.0, 200.0); 

    // Ajout
    maBanque.ajouter(c1);
    maBanque.ajouter(c2);

    cout << "--- ETAT INITIAL ---" << endl;
    maBanque.afficher();

    // Test operations
    cout << "\n--- OPERATIONS ---" << endl;
    
    cout << "Credit de 500 USD sur Mickael..." << endl;
    maBanque.crediter("Mickael", m_usd);

    cout << "Tentative de credit de 100 EUR sur Pierre..." << endl;
    if(maBanque.crediter("Pierre", m_eur)){
        cout << "Succes." << endl;
    } else {
        cout << "Echec : Plafond atteint." << endl;
    }

    cout << "\n--- ETAT FINAL ---" << endl;
    maBanque.afficher();

    return 0;
}