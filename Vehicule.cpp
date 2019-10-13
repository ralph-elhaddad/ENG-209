* Vehicule.cpp
 *
 *  Created on: Oct 12, 2019
 *      Author: pcoo21
 */

#include "Vehicule.h"
#include <iostream>

namespace Parking {

void Vehicule::set_camion(){
	camion = true;
}

bool Vehicule::get_camion(){
	return camion;
}

double Vehicule::get_charge_utile(){
	std::cout<<"watch out!"<<std::endl;
	return 0;
}

std::string Vehicule::get_plaque(){
	return plaque;
}

} /* namespace Parking */
