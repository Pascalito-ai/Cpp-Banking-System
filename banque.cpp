#include "banque.h"

Banque::Banque():nb_comptes(0){}

bool Banque::ajouter(Compte* compte){
    for(int i =0; i<nb_comptes; i++){
        if(comptes[i]->getNom() == compte->getNom()){return false;}
    }
    
    comptes[nb_comptes] = compte;
    nb_comptes+=1;
    return true;
}

void Banque::afficher(){
    for(int i =0; i<nb_comptes; i++){
        comptes[i]->afficher();
    }
}


void Banque::afficherCompte(const string& nom){
    for(int i = 0; i<nb_comptes; i++){
        if(comptes[i]->getNom() == nom){
            comptes[i]->afficher();
            return;
        }
    }
    cout<<"erreur pas de compte à ce nom"<<endl;
}



bool Banque::crediter(const string& nom, const Money& money) const{
    for(int i = 0; i<nb_comptes; i++){
        if(comptes[i]->getNom() == nom){return comptes[i]->crediter(money);}
    }
    return false;
    
}

bool Banque::debiter(const string& nom, const Money& money) const{
    for(int i = 0; i<nb_comptes; i++){
        if(comptes[i]->getNom() == nom){return comptes[i]->debiter(money);}
    }
    return false;
    
}
