#ifndef COMPTE_H
#define COMPTE_H


#include <iostream> 
#include <string> 
#include "Money.h"
using namespace std;

class Compte{
    protected:
        string nom;
        float montant;
    public:
        Compte(string nom, float montant = 0);
        virtual void afficher();
        virtual bool crediter(const Money& money);
        bool debiter(const Money& money);
        string getNom()const;
        float getMontant()const;
};

class CompteLimite : public Compte{
    private:
        float limite;
    public:
        CompteLimite(string nom, float limite,float montant = 0);
        void afficher();
        bool crediter (const Money& money);
};

