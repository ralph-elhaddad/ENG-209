/**
 * Camion.h
 *
 *  Created on: Oct 12, 2019
 *      Author: pcoo21
**/

#ifndef EXERCICE2_CAMION_H_
#define EXERCICE2_CAMION_H_

#include "Vehicule.h"

namespace Parking {

class Camion : public Vehicule {
	private:
		double charge_utile; //OK
	public:
	Camion(std::string plaque_in, double charge_utile_in):
		Vehicule(plaque_in), charge_utile(charge_utile_in) {
		set_camion();
	}//OK
	double get_charge_utile();
};

} /* namespace Parking */

#endif /* EXERCICE2_CAMION_H_ */
