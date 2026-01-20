#include "Money.h"
#include <cmath>
#include <cstring>
#include <cctype>

const float TAUX_EUR = 1.0;
const float TAUX_USD = 0.95;
const float TAUX_JPY = 0.0062;

Money::Money(float m, Devise d):montant(m),devise(d){}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    char d[10];
    switch(money.devise){
        case EUR: strcpy(d,"EUR");break;
        case USD: strcpy(d,"USD");break;
        case JPY: strcpy(d,"JPY");break;
            default: strcpy(d,"INCONNU");break;
        }
    os << money.montant << " " << d;
    return os;
}

float Money::getmontant()const{
    return(montant);
}

Devise Money::getdevise()const{
    return(devise);
}

float Money::montantEn(Devise d)const{
        float taux1;
        float taux2;
        switch(d){
            case EUR: taux1=TAUX_EUR;break;
            case USD: taux1=TAUX_USD;break;
            case JPY: taux1=TAUX_JPY;break;
            default: taux1 = 0;break;
        }
         switch(devise){
            case EUR: taux2=TAUX_EUR;break;
            case USD: taux2=TAUX_USD;break;
            case JPY: taux2=TAUX_JPY;break;
            default: taux2 = 0;break;
        }
        return(montant*taux2/taux1);
}

bool Money::operator==(const Money& autre) const { 
    return(montantEn(EUR) == autre.montantEn(EUR));
}

bool Money::operator<(const Money& autre) const { 
    return(montantEn(EUR) < autre.montantEn(EUR));
}

Money Money::operator+(const Money& autre)const{
        Money m;
        m.montant = montant +autre.montantEn(devise);
        m.devise = devise;
        return m;
}

Money Money::operator-(const Money& autre)const{
        Money m;
        m.montant = montant -autre.montantEn(devise);
        m.devise = devise;
        return m;
}