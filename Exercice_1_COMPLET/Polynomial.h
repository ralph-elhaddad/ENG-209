#ifndef EXERCICE1_POLYNOMIAL_H_
#define EXERCICE1_POLYNOMIAL_H_
#include <iostream>
#include <vector>

namespace std {

	class Polynomial{ /*! Classe du polynôme */
		public:
			Polynomial(); /*!< Constructeur par défaut */
			Polynomial(vector<double> liste); /*!< Constructeur avec un liste de nombre en entrée */

			double get_coeff(size_t a); /*!< Retourne le coefficient du a-ième degré */
			size_t get_degre(); /*!< Retourne le degré du polynôme */
			void newcoef(double a); /*!< Ajoute un nouveau coefficient a (le degré augmente d'un) */
			void newcoef(double a, size_t i); /*!< Change le coefficient à la place i par a */
			void set_degre(size_t i); /*!< Permet de créer un polynôme de degré i avec des 0 */
									/*!< L'affiche n'y est pas affectée car le degré est vérifié */
			void verif_degre(); /*!< Permet de vérifier le degré du polynôme (pas de 0 en trop) */

		private:
			size_t degre;
			vector<double> coeff; 
	};


	Polynomial operator+(Polynomial& p1, Polynomial& p2); /*!< Surcharge p1 + p2 */
	Polynomial operator*(Polynomial p1, Polynomial p2); /*!< Surcharge p1*p2 */
	ostream& operator<<(ostream& sortie, Polynomial& p); /*!< Surcharge cout << p */

}

#endif /* EXERCICE1_POLYNOMIAL_H_ */
