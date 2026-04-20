#ifndef CGrapheOriente_H
#define CGrapheOriente_H

#include <vector>
#include "CSommet.h"
#include "CArc.h"


// patron de classe CGrapheOriente
template <class S, class A>
class CGrapheOriente {
protected:
	vector<S*>vSommets; // le vecteur contenant les pointeurs de type générique S (sommet)
	vector<A*>vArcs; // le vecteur contenant les pointeurs de type générique A (Arc)



public:
	// const & dest
	CGrapheOriente() {
		// vide pour l'instant
	}

	~CGrapheOriente() {
		// vide pour l'instant
	}



	// méthodes 
	void AjouterSommet(unsigned int uiNumero) {
		// CSommet* s1 = new CSommet(1);

		// créer le sommet générique "S" (en utilisant un pointeur)
		S* s = new S(uiNumero);

		// ajouter le pointeur du sommet générique à "vector<S*>vSommets"
		vSommets.push_back(s);
	}



	void AjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
		// 1) trouver sommetDepart (il faut le pointeur)
		S* sommetDep = TrouverSommet(uiNumeroDepart);

		// 2) trouver sommetArrive (il faut le pointeur) 
		S* sommetArr = TrouverSommet(uiNumeroArrive);


		// 3) créer l'arc avec ces sommets de départs arrivés
		if (sommetDep != nullptr && sommetArr != nullptr) { // si les sommets sont trouvé
			A* nouvelArc = new A(sommetDep, sommetArr);
			vArcs.push_back(nouvelArc);
		}
		else {
			if (sommetDep == nullptr && sommetArr == nullptr) {
				cout << "GrapheOriente.h->AjouterArc(): erreur de création d'arc, >>>les 2 sommets inéxistants<<<" << endl;
			}
			else if (sommetDep == nullptr) {
				cout << "GrapheOriente.h->AjouterArc(): erreur de création d'arc, sommet de >>>DEPART<<< inéxistants" << endl;
			}
			else if (sommetArr == nullptr){
				cout << "GrapheOriente.h->AjouterArc(): erreur de création d'arc, sommets >>>d'ARRIVE<<< inéxistants" << endl;
			}


		}
		
		// 4) ajouter l'arc à "vArcs"
		// fait directement à l'étape 3 avec le push_back
	}

	void SupprimerSommet(unsigned int uiNumero) {
		// trouver le sommet (il faut le pointeur)
		// le "delete"
	}

	void SupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
		// trouver l'arc (il faut le pointeur)
		// le "delete"
	}

	void ModifierSommet(unsigned int uiNumero); // modifier par quoi? comment modifier un S*?
		// trouver le sommet (il faut le pointeur)
		// appeler des méthode sur du S générique (des attribut en plus modifiables, numero modifiable etc)

	void ModifierArc(unsigned int oldND, unsigned int OldNA, 
		unsigned int newND, unsigned int newNA);
		// trouver l'arc(oldND, OldNA) (il faut le pointeur) 
		// supprimer l'arc 
		// créer un autre arc(newND, newNA)

	void AfficherGraphe(); // liée à la classe CAffichage
	void InverserGraphe();


	// accesseurs 
	unsigned int LireNumero();



	//	vector<S*>vSommets;
	// vector<A*>vArcs;

	// setters
	void setvSommet(S* s) {
		vSommets.push_back(s);
	}

	void setvArc(A* a) {
		vSommets.push_back(a);
	}
	

	//toString 
	string toString() {
		string s = "";
		// s += "Je suis un graphe oriente!";
		s += "Graphe(\n";
		s += "-- Sommets --\n";
		for (S* sommet : vSommets) {
			s += sommet->toString();
		}

		s += "-- arcs --\n";
		for (A* arc : vArcs) {
			s += "    "+arc->toString() + "\n";
		}
		s += "\n)";
		return s;
	}


	
	
private:
	// méthodes utiles en interne (non accessible de l'exterieur)
	S* TrouverSommet(unsigned int uiNumero) {
		for (S* sommet : vSommets) { // parcourir tout les sommets de la liste "vSommets" du graphe
			if (sommet->getNumero() == uiNumero) { // si on trouve un sommet ayant ce numéro
				return sommet; // on renvoie le pointeur du sommet
			}
		}
		return nullptr; // sinon on renvoie "pointeur vide"
	}

	A* TrouverArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
		for (A* arc : vArcs) {
			// si on trouve l'arc avec les sommets de départ et arrivé corréspondents:
			if (arc->LireSommetDep() == uiNumeroDepart && arc->LireSommetArr() == uiNumeroArrive) {
				return arc; // on renvoie le pointeur de l'arc
			}
		}
	}



}; // fin de la classe

#endif // !CGrapheOriente_H
