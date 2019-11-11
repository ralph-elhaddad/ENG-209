/*
 * main.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */
#include "Parseur.h"
#include "Simulation.h"
#include <iostream>
using namespace std;

int main() {
	Parseur parseur("initialisation.xml");
	cout << parseur.get_tick();
	//Simulation& sim = Simulation::simulation();
	//sim.initialise(parseur.get_vecteur(), parseur.get_tick());
	return 0;
}


