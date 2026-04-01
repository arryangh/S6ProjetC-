#include "CArc.h"
#include "CSommet.h"   // ici c'est ok, pas de circularité

string CArc::toString() {
	string s = "";
	s += "Arc(dep:";
	s += SMTSommetDep->toString();
	s += ", arr:";
	s += SMTSommetArr->toString();
	s += ")";
	return s;
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