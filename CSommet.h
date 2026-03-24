#ifndef CSommet_H
#define CSommet_H

#include <vector>
#include "CArc.h"

using namespace std;

class CSommet {
protected:
	unsigned uiNumero;
	vector<CArc*>vArcDep; //vecteur contenant les pointeur de type CArc* (les arcs sortant)
	vector<CArc*>vArcArr; //vecteur contenant les pointeur de type CArc* (les arcs entrant)

public:
	// const & dest
	CSommet();
	CSommet(unsigned int SommetDep, unsigned int SommetArr);
	CSommet(unsigned int numero);

	~CSommet();

	// méthodes 


	// accesseurs 
	unsigned int LireNumero();
};

#endif // !CSommet_H



