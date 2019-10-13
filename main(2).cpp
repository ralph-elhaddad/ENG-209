#include <iostream>
#include <vector>
#include <string>
#include "Parking.h"
#include "Vehicule.h"
#include "Camion.h"
#include "Voiture.h"


using namespace std;
using namespace Parking;


int main() {
	Camion camion("GN 614183", 2);
	Voiture voiture("VD 376529");

	Parking::Parking park(3);
	Voiture* vptr(&voiture);
	Camion* cptr(&camion);
	park.check_in(vptr);
	park.check_in(cptr);
	park.etat();
	park.check_out(1);
	size_t i(3);
	park.check_out(i);
	park.check_out(cptr);

	return 0;
}
