#ifndef BANQUE_H
#define BANQUE_H


#include <iostream> 
#include <string> 
#include "Money.h"
#include "Compte.h"

#define MAX_COMPTES 100
using namespace std;
//Pour que banque marche bien il faut passer afficher et crediter en virtual

class Banque{
    private:
        Compte* comptes[MAX_COMPTES];
        int nb_comptes;
    public: 
        Banque();
        bool ajouter(Compte* compte);
        void afficher();
        void afficherCompte(const string& nom)const;
        bool crediter(const string& nom, const Money& money) const;
        bool debiter(const string& nom, const Money& money) const;

};
