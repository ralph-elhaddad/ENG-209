/*
 * Controleur.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#include "Controleur.h"
#include "xml_utils.h"  // utility functions
#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;
using namespace tinyxml2_utils;

Controleur::Controleur(int id_in, Etat* etat_in, XMLElement* p_control, Serveur* observateur_in):
			Processus(id_in),
			etat(etat_in),
			val_satu(get_elem_dbl(p_control, "val_satu")),
			val_control(get_elem_dbl(p_control, "val_control")),
			observateur(observateur_in){
}

Controleur::~Controleur() {
}

void Controleur::refresh() {



}

void Controleur::notify(){
	observateur->update(this);
}
