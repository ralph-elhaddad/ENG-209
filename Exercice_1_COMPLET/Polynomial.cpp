#include "Polynomial.h"
#include <iostream>
#include <vector>

namespace std {

	Polynomial::Polynomial(): degre(0) {
		coeff.push_back(0);
	}

	Polynomial::Polynomial(vector<double> liste): degre(liste.size() - 1), coeff(liste) {}

	double Polynomial::get_coeff(size_t a) {
		return coeff[a];
	}

	size_t Polynomial::get_degre() {
		return degre;
	}

	void Polynomial::verif_degre(){
		size_t a(degre);
		for(size_t i(0) ; i<a; ++i){
			if (coeff[degre] == 0){ /*! Si le coefficient à la dernière case est 0. On peut
									alors réduire le polynôme d'un degré qui était "virtuel"*/
				coeff.pop_back();
				degre = coeff.size() - 1;
			}
		}
	}

	void Polynomial::newcoef(double a) {
		coeff.push_back(a);
		degre = coeff.size() - 1;
	}

	void Polynomial::newcoef(double a, size_t i) {
		coeff[i] = a; /*!< On admet que i<=degre */
	}

	void Polynomial::set_degre(size_t i){
			for(size_t j(coeff.size()); j<=i ; ++j) coeff.push_back(0);
			degre = coeff.size() - 1;
	}

	Polynomial operator+(Polynomial& p1, Polynomial& p2) {
		Polynomial addition;
		bool max(p1.get_degre() > p2.get_degre()); /*!< vrai si degP1>degP2 */

		addition.newcoef(p1.get_coeff(0) + p2.get_coeff(0), 0);
		size_t i(1);
		while((max and i<=p1.get_degre()) or (!max and i<=p2.get_degre())){
			if (max and i<=p2.get_degre()) addition.newcoef(p1.get_coeff(i) + p2.get_coeff(i));
			else if (max and i>p2.get_degre()) addition.newcoef(p1.get_coeff(i));
			else if (!max and i<=p1.get_degre()) addition.newcoef(p1.get_coeff(i) + p2.get_coeff(i));
			else if (!max and i>p1.get_degre()) addition.newcoef(p2.get_coeff(i));

	/**
	*	Dans la boucle while, teste toutes les possibilités, en fonction des différences
	* de degré entre les 2 polynômes. Il faut bien faire attention à ne pas chercher
	* dans les vecteurs listes de coefficients de chaque polynôme des nombres qui "n'existent"
	* pas lorsque l'on est au dessus du degré par exemple
	*/
			++i;
		}
		return addition;
	}


	Polynomial operator*(Polynomial p1, Polynomial p2) {
		Polynomial mult; /*!< Créeation d'un polynôme vide de degré deg.p1+deg.p2 */
		mult.set_degre(p1.get_degre() + p2.get_degre());

		for(size_t i(0); i <= p1.get_degre();++i) { /*!< Boucle reliée à p1 */
			Polynomial addition;
				addition.set_degre(p1.get_degre() + p2.get_degre());

			for(size_t j(0); j<=p2.get_degre(); ++j){ /*!< Boucle reliée à p2 */
				addition.newcoef(p1.get_coeff(i)*p2.get_coeff(j), i+j);
			}
			mult = mult + addition;
		}
		return mult;
	}

	ostream& operator<<(ostream& sortie, Polynomial& p){
		p.verif_degre(); /*!< Vérifie le degré de p */
		sortie << "Le polynome de degre " << p.get_degre() << " est : ";

		size_t i(p.get_degre());
		do{
			if (i>1) sortie << p.get_coeff(i) << "*x^" << i << " + ";
			if (i!=0) --i; /*!< Vu que i est size_t, il ne faudrait pas aller en -1 */
		}while(i != 0); /*!< Affiche tout les coefficients pour des degrés > 1 */

		if (p.get_degre() > 1) sortie << " + "<< p.get_coeff(1) << "*x" << " + " << p.get_coeff(0);
		else if (p.get_degre() == 1) sortie << p.get_coeff(1) << "*x" << " + " << p.get_coeff(0);
		else if (p.get_degre() == 0) sortie << p.get_coeff(0);
		sortie << endl;
		return sortie;
	}
}
