#include "CArc.h"
#include "CSommet.h"   // ici c'est ok, pas de circularité

CArc::CArc(CSommet* s1, CSommet* s2) {
	pSOMSommetDep = s1;
	pSOMSommetArr = s2;

	pSOMSommetDep->SOMsetvArcDep(this);
	pSOMSommetArr->SOMsetvArcArr(this);
}

CArc::~CArc() {
	pSOMSommetArr->SOMretirerArcA(this);
	pSOMSommetDep->SOMretirerArcD(this);
}

string CArc::ARCtoString() {
	string s = "";
	s += "Arc(dep:";
	s += to_string(pSOMSommetDep->SOMgetNumero());
	s += ", arr:";
	s += to_string(pSOMSommetArr->SOMgetNumero());
	s += ")";
	return s;
}

unsigned int CArc::ARCLireSommetDep() {
	return pSOMSommetDep->SOMgetNumero(); // renovyer le numéro du sommet de départ
}

unsigned int CArc::ARCLireSommetArr() {
	return pSOMSommetArr->SOMgetNumero(); // renovyer le numéro du sommet de d'arrivé
}
