#ifndef EXERCICE1_POLYNOMIAL_H_
#define EXERCICE1_POLYNOMIAL_H_
#include <iostream>
#include <vector>

namespace std {

class Polynomial{
	public:
	Polynomial();
	Polynomial(vector<double> liste);

	double get_coeff(size_t a);
	size_t get_degre();
	void newcoef(double a);
	void newcoef(double a, size_t i);
	void set_degre(size_t i);
	void verif_degre();

	private:
	size_t degre;
	vector<double> coeff;
	};


Polynomial operator+(Polynomial& p1, Polynomial& p2);
Polynomial operator*(Polynomial p1, Polynomial p2);
ostream& operator<<(ostream& sortie, Polynomial& p);

}

#endif /* EXERCICE1_POLYNOMIAL_H_ */
