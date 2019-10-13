/**
 * Voiture.h
 *
 *  Created on: Oct 12, 2019
 *      Author: pcoo21
**/

#ifndef EXERCICE2_VOITURE_H_
#define EXERCICE2_VOITURE_H_

#include "Vehicule.h"


namespace Parking {

class Voiture : public Vehicule{
	private:
	public:
		Voiture(std::string plaque_in): Vehicule(plaque_in) {}
};
} /*! namespace Parking */

#endif /*! EXERCICE2_VOITURE_H_ */
