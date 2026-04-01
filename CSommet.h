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
	CSommet(){} 
	
	CSommet(unsigned int numero) {
		uiNumero = numero;
	}

	// ne pas le mettre pour appeler le constructeur de recopie par défaut
	// CSommet(CSommet& param){}

	~CSommet(){} //devra supprimer les arcs de départ et d'arrivé

	// méthodes 



	// toString
	string toString() {
		string s = "";
		s += "Sommet(";
		s += to_string(uiNumero);
		s += ")";
		// s = "CSommet(uiNumero=" << getNumero() << ")" << endl;
		return s;
	}

	// accesseurs 
	unsigned int getNumero() {
		return uiNumero;
	}
};

#endif // !CSommet_H



