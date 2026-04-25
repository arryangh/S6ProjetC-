#include "CArc.h"
#include "CSommet.h"   // ici c'est ok, pas de circularité

CArc::CArc(CSommet* s1, CSommet* s2) {
	SMTSommetDep = s1;
	SMTSommetArr = s2;

	SMTSommetDep->SOMsetvArcDep(this);
	SMTSommetArr->SOMsetvArcArr(this);
}

CArc::~CArc() {
	SMTSommetArr->SOMretirerArcA(this);
	SMTSommetDep->SOMretirerArcD(this);
}

string CArc::ARCtoString() {
	string s = "";
	s += "Arc(dep:";
	s += to_string(SMTSommetDep->SOMgetNumero());
	s += ", arr:";
	s += to_string(SMTSommetArr->SOMgetNumero());
	s += ")";
	return s;
}

unsigned int CArc::ARCLireSommetDep() {
	return SMTSommetDep->SOMgetNumero(); // renovyer le numéro du sommet de départ
}

unsigned int CArc::ARCLireSommetArr() {
	return SMTSommetArr->SOMgetNumero(); // renovyer le numéro du sommet de d'arrivé
}
