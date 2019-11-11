/*
 * Serveur.h
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#ifndef SOURCES_SERVEUR_H_
#define SOURCES_SERVEUR_H_

#include "Processus.h"

class Controleur;

class Serveur: public Processus {
public:
	static Serveur& serveur();
	void refresh() override; //se fait executer a chaque tick
	virtual void update (Controleur* subject) = 0;

private:
	Serveur();
	~Serveur();
	Serveur& operator=(const Serveur&);

};

#endif /* SOURCES_SERVEUR_H_ */
