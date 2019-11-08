/*
 * Processus.h
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#ifndef SOURCES_PROCESSUS_H_
#define SOURCES_PROCESSUS_H_

class Processus {
public:
	Processus(int id_in = 0);
	virtual ~Processus();
	virtual void refresh() ;
private:
	int id; //zone du processus
};

#endif /* SOURCES_PROCESSUS_H_ */
