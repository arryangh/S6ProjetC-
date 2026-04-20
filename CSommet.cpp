#include "CSommet.h"

CSommet::~CSommet() {
	for (CArc* CArcDep : vArcDep) {
		delete CArcDep;
	}
	for (CArc* CArcArr : vArcArr) {
		delete CArcArr;
	}
}

// toString
string CSommet::toString() {
	string s = "";
	s += "    Sommet(" + to_string(uiNumero) + ")\n";

	s += "        Arcs partants: ";
	for (CArc* arc : vArcDep) {
		s += arc->toString() + " ";
	}
	s += "\n";

	s += "        Arcs arrivants: ";
	for (CArc* arc : vArcArr) {
		s += arc->toString() + " ";
	}
	s += "\n";

	return s;
}
