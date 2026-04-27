#include "CSommet.h"


/*
* CSommet::~CSommet() {
	for (CArc* CArcDep : vArcDep) {
		delete CArcDep;
	}
	for (CArc* CArcArr : vArcArr) {
		delete CArcArr;
	}
}
ATTENTION: dans la version qui se trouve juste en haut, le déstructeur du sommet supprime les arcs partants et 
arrivants.
	- le problème c'est que chaque arc se trouve dans 2 sommets. 
	- quand on arrive au 2ième sommets, on essayera de resupprimer cet arc, mais il n'existe plus
	- de plus, quand le premier sommet supprime l'arc, le deuxième pointe vers le vide

SOLUTION: 
	- dans le déstructeur de CSommet, on supprime que les arcs de départ 
	- c'est le déstructeur de CArc qui retire l'arc du sommet d'arrivé (méthode 
 
*/

CSommet::~CSommet() {
	// supprimer les arcs partants (on les possède)
	vector<CArc*> copieD = vSOMArcDep;
	for (CArc* arc : copieD) {
		delete arc;
	}

	// supprimer les arcs arrivants (possédés par d'autres sommets, 
	// mais ils pointent vers nous donc il faut les supprimer aussi)
	vector<CArc*> copieA = vSOMArcArr;
	for (CArc* arc : copieA) {
		delete arc;
	}
}

// toString
string CSommet::SOMtoString() {
	string s = "";
	s += "    Sommet(" + to_string(uiSOMNumero) + ")\n";

	s += "        Arcs partants: ";
	for (CArc* arc : vSOMArcDep) {
		s += arc->ARCtoString() + " ";
	}
	s += "\n";

	s += "        Arcs arrivants: ";
	for (CArc* arc : vSOMArcArr) {
		s += arc->ARCtoString() + " ";
	}
	s += "\n";

	return s;
}
