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
	Camion camion1("GN 614183", 2);
	Camion camion2("VD 23568", 6);
	Camion camion3("VS 45781", 12);

	Voiture voiture1("VD 376529");
	Voiture voiture2("VD 3486");
	Voiture voiture3("VS 56135");

	Parking::Parking park(3);
	Voiture* vptr1(&voiture1);
	Voiture* vptr2(&voiture2);
	Voiture* vptr3(&voiture3);
	Camion* cptr1(&camion1);
	Camion* cptr2(&camion2);
	Camion* cptr3(&camion3);
	
	park.check_in(vptr1);
	park.check_in(vptr2);
	park.check_in(cptr1);
	park.etat();
	park.check_out(2);
	park.check_in(vptr3);
	park.check_in(cptr2);
	park.check_out(vptr2);
	park.check_out(vptr3);
	park.check_in(cptr3);

	park.check_in(vptr3);
	size_t i(1);
	park.check_out(i);
	park.check_out(cptr1);
	park.check_out(vptr1);
	park.check_out(vptr3);
	park.check_out(3);
	park.etat();

	return 0;
}
