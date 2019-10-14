/** Parking.h
 *
 *  Created on: Oct 12, 2019
 *      Author: pcoo21
**/

#ifndef EXERCICE2_PARKING_H_
#define EXERCICE2_PARKING_H_

#include <vector>
#include "Vehicule.h"
#include <iostream>


namespace Parking {

	class Parking{
		private:
			unsigned int nb_place_max; 
			unsigned int nb_place_prise;
			std::vector<Vehicule*> place;//! liste des places du parking
			int nb_voiture;
			int nb_camion;
			bool etat_plein; //! true si le parking est plein
		public:
			Parking(size_t max): nb_place_max(max), nb_place_prise(0),
					nb_voiture(0), nb_camion(0), etat_plein(false) {
						for(size_t i(0); i < nb_place_max; ++i) {
							place.push_back(nullptr);
						}//! parking vide avec max places
					}

			~Parking(){}//! doit d�truire toutes les places et mettre tous les vehicules à parking false
			void check_in(Vehicule* entree);//! rentre le vehicule si possible dans le parking
			void check_out(Vehicule* sortie);//!sort le vehicule
			void check_out(size_t i);/*! libère la place */
			void etat();
	};

} /*! namespace Parking */

#endif /* EXERCICE2_PARKING_H_ */
