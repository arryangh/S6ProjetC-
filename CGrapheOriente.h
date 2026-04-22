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
		// 1) trouver le sommet S* qu'on veut supprimer 
		S* sommet = TrouverSommet(uiNumero);

		
		// si le sommet a été trouvé 
		if (sommet != nullptr) { 
			// 2) retirer les arcs A* du sommets qu'on veut supprimer de la liste "vArcs" du graphe
			for (A* arc : sommet->getvArcDep()) { // retirer "les arcs de départ du sommet" des arcs du graphe
				vArcs.erase(remove(vArcs.begin(), vArcs.end(), arc), vArcs.end());
			}
			for (A* arc : sommet->getvArcArr()) { // retirer "les arcs d'arrivé du sommet" des arcs du graphe
				vArcs.erase(remove(vArcs.begin(), vArcs.end(), arc), vArcs.end());
			}

			// 3) retirer le sommet S* qu'on veut supprimer de la liste "vSommets" du graphe
			vSommets.erase(remove(vSommets.begin(), vSommets.end(), sommet), vSommets.end());

			// 4) le "delete"
			delete sommet; // appelle le déstructeur de CSommet (supprime le sommet proprement en supprimant les arcs liées etc)
		}
		else {
			cout << "CGrapheOriente.h->SupprimerSommet(): sommet " + to_string(uiNumero) + " non trouvé." << endl;
		}

	}

	void SupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
		// 1) trouver l'arc A* qu'on veut supprimer 
		A* arc = TrouverArc(uiNumeroDepart, uiNumeroArrive);

		// si l'arc a été trouvé 
		if (arc != nullptr) {
			// 2) retirer l'arc A* de de la liste "vArcs" du graphe
			vArcs.erase(remove(vArcs.begin(), vArcs.end(), arc), vArcs.end());

			// 3) supprimer l'arc 
			delete arc; // appèle le déstructeur qui enlève l'arc des sommets en question 
		}
		else {
			cout << "CGrapheOriente.h->SupprimerArc(): l'arc (" + to_string(uiNumeroDepart) +", " + to_string(uiNumeroArrive) +") non trouvé." << endl;
		}

	}

	// ==> changer le numéro d'un sommet (ou d'autres attributs avancé ajouté par la classe fille de l'utilisateur)

	void ModifierSommet(unsigned int uiNumero); // modifier par quoi? comment modifier un S*? 
		// trouver le sommet (il faut le pointeur)
		// appeler des méthode sur du S générique (des attribut en plus modifiables, numero modifiable etc)



	/*
	* remarque: si un utilisateur veut vraiment modifier un arc avec des données en plus, il peut appeler directement des setters sur l'arc en question.
	*/
	void ModifierArc(unsigned int oldND, unsigned int oldNA, unsigned int newND, unsigned int newNA) {
		// 1) vérifier que l'arc à modifier existe
		A* arc = TrouverArc(oldND, oldNA);
		if (arc == nullptr) {
			cout << "GrapheOriente.h->ModifierArc(): l'arc a modifier: (" + to_string(oldND) + ", " + to_string(oldNA) + ") n'existe pas." << endl;
			return;
		}

		// 2) vérifier que le nouvel arc n'existe pas déjà
		A* arcExistant = TrouverArc(newND, newNA);
		if (arcExistant != nullptr) {
			cout << "GrapheOriente.h->ModifierArc(): l'arc a créer: (" + to_string(newND) + ", " + to_string(newNA) + ") existe déjà." << endl;
			return;
		}

		// 3) vérifier que les nouveaux sommets existent
		if (TrouverSommet(newND) == nullptr || TrouverSommet(newNA) == nullptr) {
			cout << "GrapheOriente.h->ModifierArc(): un des sommets de destination n'existe pas." << endl;
			return;
		}

		// 4) tout est ok, on modifie
		SupprimerArc(oldND, oldNA);
		AjouterArc(newND, newNA);
	}

	// que pour les graphes orientés
	CGrapheOriente<S, A>* InverserGraphe() {
		/*
		utiliser "ModifierArc" pour inverser tout les arcs 
		comment faire si il y a: s1 <=> s2 (y aura l'erreur: l'arc à créer existe déjà)

		SOLUTION: ne pas utiliser la méthode "ModifierArc". au lieu de ça, on peut juste faire une copie du graphe 
		avec tout les sommets à l'identique, on va juste inverser les graphes qui les lient entre eux:
		*/

		// 1) création du copy de graphe (vide au début) 
		CGrapheOriente<S, A>* grapheInverse = new CGrapheOriente<S, A>();

		// 2) copie à l'identique de tout les sommets générique S* 
		for (S* sommet : vSommets) {
			unsigned int numSommet = sommet->getNumero(); // le numéro du sommet à recopier (créer l'équivalent)
			grapheInverse->AjouterSommet(numSommet); // création de l'équivalent dans "grapheInverse"
		}

		// 3) copier l'inverse des arcs (inverser les numDep et numArr)
		for (A* arc : vArcs) {
			unsigned int numDep = arc->LireSommetDep(); 
			unsigned int numArr = arc->LireSommetArr();
			grapheInverse->AjouterArc(numArr, numDep);
		}

		return grapheInverse;
	}


	void AfficherGraphe(); // liée à la classe CAffichage
	

	// graphe => string (pour faire par la suite => fichier.txt)
	// faire un string respectant les conventions de fichier txt 
	string GenererContenuTXT() {

	}


	// accesseurs 
	/*
	unsigned int LireNumero();
	*/
	


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
		return nullptr;
	}



}; // fin de la classe

#endif // !CGrapheOriente_H
