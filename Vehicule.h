* Vehicule.h
 *
 *  Created on: Oct 12, 2019
 *      Author: pcoo21
 */

#ifndef EXERCICE2_VEHICULE_H_
#define EXERCICE2_VEHICULE_H_
#include <string>

namespace Parking {

class Vehicule{
	protected:
		std::string plaque; //OK
		unsigned int n_place; //N° dans la liste de place du parking
		bool parking; //vrai s'il est dans le parking
		bool camion;

	public:
		Vehicule(std::string plaque_in): plaque(plaque_in), n_place(0), parking(false),
		                                 camion(false){}
		void parking_in(size_t place); //Rentre dans le parking donc parking=true
		void parking_out();//met parking=false et n_place=0
		void set_camion(); //sets camion as true in case the vehicle is one
		bool get_camion();
		virtual double get_charge_utile();
		std::string get_plaque();

};

} /* namespace Parking */

#endif /* EXERCICE2_VEHICULE_H_ */
