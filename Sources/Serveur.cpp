/*
 * Serveur.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#include "Serveur.h"

Serveur::Serveur() {
	// TODO Auto-generated constructor stub

}

Serveur::~Serveur() {
	// TODO Auto-generated destructor stub
}

void Serveur::refresh(){


}
Serveur& Serveur::serveur() {
	static Serveur serv();
	return serv;
}
