/*
 * Controleur.h
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#ifndef SOURCES_CONTROLEUR_H_
#define SOURCES_CONTROLEUR_H_

#include "Processus.h"
#include "Etat.h"
#include "Serveur.h"
#include "xml_utils.h"  // utility functions
#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;
using namespace tinyxml2_utils;

using namespace std;


class Controleur: public Processus {
public:
	Controleur(int id_in, Etat* etat_in, XMLElement* p_control, Serveur* observateur_in);
	virtual ~Controleur();
	void refresh() override;
	void notify();

private:
	Etat* etat;
	double val_satu;
	double val_control;
	Serveur* observateur;
};

#endif /* SOURCES_CONTROLEUR_H_ */

