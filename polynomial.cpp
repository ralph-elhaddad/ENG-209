#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Polynomial{
	public:
	Polynomial(): degre(0) {coeff.push_back(0);}
	Polynomial(vector<double> liste): degre(liste.size() - 1), coeff(liste) {}
	double get_coeff(size_t a) {return coeff[a];}
	size_t get_degre() {return degre;}
	void newcoef(double a);
	void newcoef(double a, size_t i);
	void set_degre(size_t i);
	
	private:
	size_t degre;
	vector<double> coeff;
	};

void Polynomial::newcoef(double a) {
	coeff.push_back(a);
	degre = coeff.size() - 1;
}

	void Polynomial::newcoef(double a, size_t i) {
	coeff[i] = a; //i<=degre
	}

	void Polynomial::set_degre(size_t i){
		for(size_t j(coeff.size()); j<=i ; ++j) coeff.push_back(0);
		degre = coeff.size() - 1;
	}

Polynomial operator+(Polynomial& p1, Polynomial& p2) {
	Polynomial addition;
	bool max(p1.get_degre() > p2.get_degre()); //vrai si degP1>degP2  faux = degP1<=degP2
	
	addition.newcoef(p1.get_coeff(0) + p2.get_coeff(0), 0);
	size_t i(1);
	while((max and i<=p1.get_degre()) or (!max and i<=p2.get_degre())){
		if (max and i<=p2.get_degre()) addition.newcoef(p1.get_coeff(i) + p2.get_coeff(i));
		else if (max and i>p2.get_degre()) addition.newcoef(p1.get_coeff(i));
		else if (!max and i<=p1.get_degre()) addition.newcoef(p1.get_coeff(i) + p2.get_coeff(i));
		else if (!max and i>p1.get_degre()) addition.newcoef(p2.get_coeff(i));

		++i;
	}
	return addition;
}

Polynomial operator*(Polynomial p1, Polynomial p2) {
	Polynomial mult;
	mult.set_degre(p1.get_degre() + p2.get_degre());
	
	for(size_t i(0); i <= p1.get_degre();++i) { //p1
		Polynomial addition;
		addition.set_degre(p1.get_degre() + p2.get_degre());
		
		for(size_t j(0); j<=p2.get_degre(); ++j){ //p2

			addition.newcoef(p1.get_coeff(i)*p2.get_coeff(j), i+j);
		}
		mult = mult + addition;
	}
	return mult;
}

ostream& operator<<(ostream& sortie, Polynomial& p){
	sortie << "Le polynome de degre " << p.get_degre() << " est : ";
	size_t i(p.get_degre());
	do{
		if (i>1) sortie << p.get_coeff(i) << "*x^" << i << " + ";
		else if (i==1) sortie << " + "<< p.get_coeff(i) << "*x";
		else if (i==0) sortie << p.get_coeff(i);
		if (i!=0) --i;
	}while(i != 0);
	if (p.get_degre() != 0) sortie << " + " << p.get_coeff(0);
	sortie << endl;
	return sortie;
}


int main() {
	Polynomial p;
	p.set_degre(5);
	vector <double> salut;
	salut.push_back(3);
	salut.push_back(2);
	salut.push_back(3);
	salut.push_back(2);
	salut.push_back(3);
	salut.push_back(2);
	Polynomial p1(salut);
	cout << p;
	cout << p1;
	Polynomial p3;
	Polynomial p4;
	p3 = p + p1;
	p4 = p1*p1;
	cout << p3;
	cout << p4;
	return 0;
}
