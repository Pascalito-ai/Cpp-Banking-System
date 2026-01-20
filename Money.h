#include <iostream> 
#include <string.h> 
using namespace std;

enum Devise{EUR,USD,JPY};

class Money{
    private:
        float montant;
        Devise devise;
    public:
        Money(float montant = 0, Devise devise = EUR);
        friend ostream& operator<< (ostream& flot, const Money& money);
        float getmontant()const;
        Devise getdevise() const;
        float montantEn(Devise devise2)const;
        bool operator== (const Money& autre)const;
        bool operator< (const Money& autre)const; 
        Money operator+ (const Money& autre)const; 
        Money operator- (const Money& autre)const; 

};


