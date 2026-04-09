#ifndef CArc_H
#define CArc_H

#include <iostream>

class CSommet; // pas faire include "CSommet.h" parce que y aura dépendance mutuelle)

using namespace std;

class CArc {
protected:
	CSommet* SMTSommetDep;
	CSommet* SMTSommetArr;

public:
	// const & dest

	// CArc();

	CArc(CSommet* s1, CSommet* s2);

	//par numéro (recherche dans graphe)
	CArc(unsigned int SommetDep, unsigned int SommetArr);
		
	~CArc() {
		SMTSommetArr->retirerArcD(this);
		SMTSommetDep->retirerArcA(this);
	}

	// méthodes  



	// toString
	string toString();

	// accesseurs 
	unsigned int LireSommetDep();
	unsigned int LireSommetArr();
	void ModifierSommetDep(unsigned int uiNumero);
	void ModifierSommetArr(unsigned int uiNumero);

	
};

#endif // !CArc_H



