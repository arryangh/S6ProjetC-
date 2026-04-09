#include "CArc.h"
#include "CSommet.h"   // ici c'est ok, pas de circularité

string CArc::toString() {
	string s = "";
	s += "Arc(dep:";
	s += to_string(SMTSommetDep->getNumero());
	s += ", arr:";
	s += to_string(SMTSommetArr->getNumero());
	s += ")";
	return s;
}
CArc::CArc(CSommet* s1, CSommet* s2) {
	SMTSommetDep = s1;
	SMTSommetArr = s2;

	SMTSommetDep->setvArcDep(this);
	SMTSommetArr->setvArcArr(this);
}

CArc::~CArc() {
	SMTSommetArr->retirerArcA(this);
	SMTSommetDep->retirerArcD(this);
}


/*

	string toString() {
		string s = "";
		s += "Sommet(";
		s += to_string(uiNumero);
		s += ")";
		// s = "CSommet(uiNumero=" << getNumero() << ")" << endl;
		return s;
	}

*/