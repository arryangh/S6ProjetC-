#ifndef PGrapheOriente_H
#define PGrapheOriente_H


// à modifier: 
/*********************************************************************************
* PATRON : PGrapheOriente
* ********************************************************************************
* ROLE: Ce patron de classe permet d'instancier des graphes en prenant en paramètre des pointeurs de Sommet (S) et 
* des pointeurs d'Arcs (A) génériques. Ainsi, l'utilisateur pourra faire un graphe en utilisant ses propres classes 
* héritées des classes CSommet et CArc.
* ********************************************************************************
* VERSION: 1.0
* AUTEUR: Anaëlle BENOIST & Aryan GHALEHNOEE
* DATE:
* ********************************************************************************
* INCLUSIONS EXTERNES:
*/
#include <vector>
#include "CSommet.h"
#include "CArc.h"


// patron de classe PGrapheOriente
template <class S, class A>
class PGrapheOriente {
protected:
	vector<S*>vGORSommets; // le vecteur contenant les pointeurs de type générique S (sommet)
	vector<A*>vGORArcs; // le vecteur contenant les pointeurs de type générique A (Arc)



public:
	// const & dest
	PGrapheOriente() {
		// vide pour l'instant
	}

	~PGrapheOriente() {
		// vide pour l'instant
	}



	// méthodes 
	void GORAjouterSommet(unsigned int uiNumero) {
		// CSommet* s1 = new CSommet(1);

		// créer le sommet générique "S" (en utilisant un pointeur)
		S* s = new S(uiNumero);

		// ajouter le pointeur du sommet générique à "vector<S*>vSommets"
		vGORSommets.push_back(s);
	}

	virtual void GORAjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
		// 1) trouver sommetDepart (il faut le pointeur)
		S* sommetDep = GORTrouverSommet(uiNumeroDepart);

		// 2) trouver sommetArrive (il faut le pointeur) 
		S* sommetArr = GORTrouverSommet(uiNumeroArrive);


		// 3) créer l'arc avec ces sommets de départs arrivés
		if (sommetDep != nullptr && sommetArr != nullptr) { // si les sommets sont trouvé
			A* nouvelArc = new A(sommetDep, sommetArr);
			vGORArcs.push_back(nouvelArc);
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

	void GORSupprimerSommet(unsigned int uiNumero) {
		// 1) trouver le sommet S* qu'on veut supprimer 
		S* sommet = GORTrouverSommet(uiNumero);

		
		// si le sommet a été trouvé 
		if (sommet != nullptr) { 
			// 2) retirer les arcs A* du sommets qu'on veut supprimer de la liste "vArcs" du graphe
			for (A* arc : sommet->SOMgetvArcDep()) { // retirer "les arcs de départ du sommet" des arcs du graphe
				vGORArcs.erase(remove(vGORArcs.begin(), vGORArcs.end(), arc), vGORArcs.end());
			}
			for (A* arc : sommet->SOMgetvArcArr()) { // retirer "les arcs d'arrivé du sommet" des arcs du graphe
				vGORArcs.erase(remove(vGORArcs.begin(), vGORArcs.end(), arc), vGORArcs.end());
			}

			// 3) retirer le sommet S* qu'on veut supprimer de la liste "vSommets" du graphe
			vGORSommets.erase(remove(vGORSommets.begin(), vGORSommets.end(), sommet), vGORSommets.end());

			// 4) le "delete"
			delete sommet; // appelle le déstructeur de CSommet (supprime le sommet proprement en supprimant les arcs liées etc)
		}
		else {
			cout << "PGrapheOriente.h->SupprimerSommet(): sommet " + to_string(uiNumero) + " non trouvé." << endl;
		}

	}

	virtual void GORSupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
		// 1) trouver l'arc A* qu'on veut supprimer 
		A* arc = GORTrouverArc(uiNumeroDepart, uiNumeroArrive);

		// si l'arc a été trouvé 
		if (arc != nullptr) {
			// 2) retirer l'arc A* de de la liste "vArcs" du graphe
			vGORArcs.erase(remove(vGORArcs.begin(), vGORArcs.end(), arc), vGORArcs.end());

			// 3) supprimer l'arc 
			delete arc; // appèle le déstructeur qui enlève l'arc des sommets en question 
		}
		else {
			cout << "PGrapheOriente.h->SupprimerArc(): l'arc (" + to_string(uiNumeroDepart) +", " + to_string(uiNumeroArrive) +") non trouvé." << endl;
		}

	}

	// ==> changer le numéro d'un sommet (ou d'autres attributs avancé ajouté par la classe fille de l'utilisateur)

	void GORModifierSommet(unsigned int uiNumero); // modifier par quoi? comment modifier un S*? 
		// trouver le sommet (il faut le pointeur)
		// appeler des méthode sur du S générique (des attribut en plus modifiables, numero modifiable etc)



	/*
	* remarque: si un utilisateur veut vraiment modifier un arc avec des données en plus, il peut appeler directement des setters sur l'arc en question.
	*/
	virtual void GORModifierArc(unsigned int oldND, unsigned int oldNA, unsigned int newND, unsigned int newNA) {
		// 1) vérifier que l'arc à modifier existe
		A* arc = GORTrouverArc(oldND, oldNA);
		if (arc == nullptr) {
			cout << "GrapheOriente.h->ModifierArc(): l'arc a modifier: (" + to_string(oldND) + ", " + to_string(oldNA) + ") n'existe pas." << endl;
			return;
		}

		// 2) vérifier que le nouvel arc n'existe pas déjà
		A* arcExistant = GORTrouverArc(newND, newNA);
		if (arcExistant != nullptr) {
			cout << "GrapheOriente.h->ModifierArc(): l'arc a créer: (" + to_string(newND) + ", " + to_string(newNA) + ") existe déjà." << endl;
			return;
		}

		// 3) vérifier que les nouveaux sommets existent
		if (GORTrouverSommet(newND) == nullptr || GORTrouverSommet(newNA) == nullptr) {
			cout << "GrapheOriente.h->ModifierArc(): un des sommets de destination n'existe pas." << endl;
			return;
		}

		// 4) tout est ok, on modifie
		GORSupprimerArc(oldND, oldNA);
		GORAjouterArc(newND, newNA);
	}

	// que pour les graphes orientés
	PGrapheOriente<S, A>* GORInverserGraphe() {
		/*
		utiliser "ModifierArc" pour inverser tout les arcs 
		comment faire si il y a: s1 <=> s2 (y aura l'erreur: l'arc à créer existe déjà)

		SOLUTION: ne pas utiliser la méthode "ModifierArc". au lieu de ça, on peut juste faire une copie du graphe 
		avec tout les sommets à l'identique, on va juste inverser les graphes qui les lient entre eux:
		*/

		// 1) création du copy de graphe (vide au début) 
		PGrapheOriente<S, A>* grapheInverse = new PGrapheOriente<S, A>();

		// 2) copie à l'identique de tout les sommets générique S* 
		for (S* sommet : vGORSommets) {
			unsigned int numSommet = sommet->SOMgetNumero(); // le numéro du sommet à recopier (créer l'équivalent)
			grapheInverse->GORAjouterSommet(numSommet); // création de l'équivalent dans "grapheInverse"
		}

		// 3) copier l'inverse des arcs (inverser les numDep et numArr)
		for (A* arc : vGORArcs) {
			unsigned int numDep = arc->ARCLireSommetDep(); 
			unsigned int numArr = arc->ARCLireSommetArr();
			grapheInverse->GORAjouterArc(numArr, numDep);
		}

		return grapheInverse;
	}


	void GORAfficherGraphe(); // liée à la classe CAffichage
	

	// graphe => string (pour faire par la suite => fichier.txt)
	// faire un string respectant les conventions de fichier txt 
	string GORGenererContenuTXT() {

	}


	// accesseurs 
	/*
	unsigned int LireNumero();
	*/
	


	//	vector<S*>vSommets;
	// vector<A*>vArcs;

	// setters
	void GORsetvSommet(S* s) {
		vGORSommets.push_back(s);
	}

	void GORsetvArc(A* a) {
		vGORSommets.push_back(a);
	}
	

	//toString 
	string GORtoString() {
		string s = "";
		// s += "Je suis un graphe oriente!";
		s += "Graphe(\n";
		s += "-- Sommets --\n";
		for (S* sommet : vGORSommets) {
			s += sommet->SOMtoString();
		}

		s += "-- arcs --\n";
		for (A* arc : vGORArcs) {
			s += "    "+arc->ARCtoString() + "\n";
		}
		s += "\n)";
		return s;
	}


	
	
private:
	// méthodes utiles en interne (non accessible de l'exterieur)
	S* GORTrouverSommet(unsigned int uiNumero) {
		for (S* sommet : vGORSommets) { // parcourir tout les sommets de la liste "vSommets" du graphe
			if (sommet->SOMgetNumero() == uiNumero) { // si on trouve un sommet ayant ce numéro
				return sommet; // on renvoie le pointeur du sommet
			}
		}
		return nullptr; // sinon on renvoie "pointeur vide"
	}

	A* GORTrouverArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
		for (A* arc : vGORArcs) {
			// si on trouve l'arc avec les sommets de départ et arrivé corréspondents:
			if (arc->ARCLireSommetDep() == uiNumeroDepart && arc->ARCLireSommetArr() == uiNumeroArrive) {
				return arc; // on renvoie le pointeur de l'arc
			}
		}
		return nullptr;
	}



}; // fin de la classe

#endif // !PGrapheOriente_H
