#ifndef CSommet_H
#define CSommet_H

#include <iostream>
#include <vector>
#include "CArc.h"
#include <string>

using namespace std;

class CSommet {
protected:
	unsigned uiNumero;
	vector<CArc*>vArcDep; //vecteur contenant les pointeur de type CArc* (les arcs sortant)
	vector<CArc*>vArcArr; //vecteur contenant les pointeur de type CArc* (les arcs entrant)

public:
	// const & dest
	// CSommet();
	
	CSommet(unsigned int numero) {
		uiNumero = numero;
	}

	// ne pas le mettre pour appeler le constructeur de recopie par défaut
	// CSommet(CSommet& param){}

	~CSommet();

	// méthodes 

	void retirerArcD(CArc* pArc) {
		vArcDep.erase(remove(vArcDep.begin(), vArcDep.end(), pArc),vArcDep.end());
	}


	void retirerArcA(CArc* pArc) {
		vArcArr.erase(remove(vArcArr.begin(), vArcArr.end(), pArc), vArcArr.end());
	}


	// toString
	string toString();

	// accesseurs 
	unsigned int getNumero() {
		return uiNumero;
	}

	// getters (constate pour assurer de pas modifier CArc)
	const vector<CArc*>& getvArcDep() const {
		return vArcDep;
	}

	const vector<CArc*>& getvArcArr() const {
		return vArcArr;
	}
	

	// setters
	void setvArcDep(CArc* a) {
		vArcDep.push_back(a);

	}

	void setvArcArr(CArc* a) {
		vArcArr.push_back(a);
	}

	


	

};

#endif // !CSommet_H



