#include "compte.h"
#include "Money.h"

Compte::Compte(string n,float montant):nom(n),montant(montant){}

void Compte::afficher(){
    cout<<"Client :"<<nom<<"montant :"<<montant<<endl;
}

bool Compte::crediter(const Money& money){
    montant+= money.montantEn(EUR);
    return true; 
}

bool Compte::debiter(const Money& money){
    if(montant-money.montantEn(EUR) < 0){return false;}
    else{
        montant-= money.montantEn(EUR);
    }
    return true;
}

string Compte::getNom()const{
    return(nom);
}

float Compte::getMontant()const{
    return(montant);
}


CompteLimite::CompteLimite(string n, float l,float m):Compte(n,m),limite(l){}

void CompteLimite::afficher(){
    cout<<"Client :"<<nom<<"montant :"<<montant<<"motant à ne pas dépasser :"<< limite<<endl;

}

bool CompteLimite::crediter(const Money& money){
    if(montant+money.montantEn(EUR) > limite){return false;}
    else{
        montant+= money.montantEn(EUR);
    }
    return true;
}
