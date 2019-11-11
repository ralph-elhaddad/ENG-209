/*
 * Parseur.h
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#ifndef SOURCES_PARSEUR_H_
#define SOURCES_PARSEUR_H_
#include <string>

#include "Processus.h"
#include "Controleur.h"
#include "Etat.h"
#include "Phenomene.h"
#include "Serveur.h"
#include <vector>

class Parseur {
public:
	Parseur(const std::string xml_file_in);
	virtual ~Parseur();
	vector <Processus*> get_vecteur();
	unsigned int get_tick();

private:
	const std::string xml_file_name;
	vector<Processus*> list_processus;
	unsigned int tick;
	void xml_parser();
};

#endif /* SOURCES_PARSEUR_H_ */
