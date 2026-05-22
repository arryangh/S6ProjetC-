#ifndef PGrapheOriente_H
#define PGrapheOriente_H


// à modifier: 
/*********************************************************************************
* PATRON DE CLASSE : PGrapheOriente
* ********************************************************************************
* ROLE: Ce patron de classe permet d'instancier des graphes en prenant en paramètre
		des pointeurs de Sommet (S) et des pointeurs d'Arcs (A) génériques. Ainsi, 
		l'utilisateur pourra faire un graphe en utilisant ses propres classes 
*		héritées des classes PSommet et PArc.
* ********************************************************************************
* VERSION: 1.0
* AUTEUR: Anaëlle BENOIST & Aryan GHALEHNOEE
* DATE:
* ********************************************************************************
* INCLUSIONS EXTERNES:
*/
#include <vector>
#include "PSommet.h"
#include "PArc.h"
#include "CException.h"

template <class S, class A>
class PGrapheOriente {
// ATTRIBUTS :
protected:
	vector<S*>vGORSommets; 
	vector<A*>vGORArcs;

// CONSTRUCTEURS ET DESTRUCTEURS
public:
	PGrapheOriente() {};
	~PGrapheOriente();

// METHODES
	/*********************************************************************************
	* GORAjouterSommet
	* ********************************************************************************
	* Entrée : uiNumero, unsigned int, le numéro identifiant du sommet à créer
	* Nécessite : qu'aucun sommet avec ce numéro n'existe déjà dans le graphe
	* Sortie : Rien
	* Entraîne : crée un nouveau sommet générique S avec le numéro donné et l'ajoute
	*            au vecteur des sommets du graphe (vGORSommets).
	*            Lève une exception runtime_error si un sommet avec ce numéro
	*            existe déjà dans le graphe.
	*********************************************************************************/
	void GORAjouterSommet(unsigned int uiNumero);

	/*********************************************************************************
	* GORAjouterArc
	* ********************************************************************************
	* Entrée : uiNumeroDepart, unsigned int, le numéro du sommet de départ de l'arc
	*          uiNumeroArrive, unsigned int, le numéro du sommet d'arrivée de l'arc
	* Nécessite : les deux sommets doivent exister dans le graphe
	* Sortie : Rien
	* Entraîne : crée un nouvel arc générique A reliant les deux sommets trouvés et
	*            l'ajoute au vecteur des arcs du graphe (vGORArcs).
	*            Si l'un ou les deux sommets sont introuvables, un message d'erreur
	*            est affiché en console et aucun arc n'est créé.
	*********************************************************************************/
	virtual void GORAjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);

	/*********************************************************************************
	* GORSupprimerSommet
	* ********************************************************************************
	* Entrée : uiNumero, unsigned int, le numéro du sommet à supprimer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : retire tous les arcs liés au sommet (partants et arrivants) de
	*            vGORArcs, retire le sommet de vGORSommets, puis appelle delete sur
	*            le sommet (ce qui déclenche son destructeur et libère la mémoire).
	*            Si le sommet est introuvable, un message d'erreur est affiché en
	*            console et le graphe n'est pas modifié.
	*********************************************************************************/
	void GORSupprimerSommet(unsigned int uiNumero);

	/*********************************************************************************
	* GORSupprimerArc
	* ********************************************************************************
	* Entrée : uiNumeroDepart, unsigned int, le numéro du sommet de départ de l'arc
	*          uiNumeroArrive, unsigned int, le numéro du sommet d'arrivée de l'arc
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : retire l'arc identifié par (uiNumeroDepart, uiNumeroArrive) de
	*            vGORArcs, puis appelle delete sur l'arc (ce qui déclenche son
	*            destructeur et le retire des vecteurs des sommets concernés).
	*            Si l'arc est introuvable, un message d'erreur est affiché en console
	*            et le graphe n'est pas modifié.
	*********************************************************************************/
	virtual void GORSupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);

	/*********************************************************************************
	* GORModifierArc
	* ********************************************************************************
	* Entrée : oldND, unsigned int, le numéro du sommet de départ de l'arc à modifier
	*          oldNA, unsigned int, le numéro du sommet d'arrivée de l'arc à modifier
	*          newND, unsigned int, le numéro du nouveau sommet de départ
	*          newNA, unsigned int, le numéro du nouveau sommet d'arrivée
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : supprime l'arc (oldND, oldNA) et crée un nouvel arc (newND, newNA).
	*            Si l'arc à modifier n'existe pas, si l'arc cible existe déjà, ou si
	*            l'un des nouveaux sommets est introuvable, un message d'erreur est
	*            affiché en console et aucune modification n'est effectuée.
	* Remarque : pour modifier des attributs supplémentaires d'un arc (ajoutés par
	*            une classe fille), utiliser directement les setters de cet classe fille.
	*********************************************************************************/
	virtual void GORModifierArc(unsigned int oldND, unsigned int oldNA, unsigned int newND, unsigned int newNA);

	/*********************************************************************************
	* GORInverserGraphe
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : pointeur vers un nouveau PGrapheOriente<S, A>
	* Entraîne : crée un nouveau graphe contenant les mêmes sommets que le graphe
	*            appelant, mais dont tous les arcs ont leur sens inversé
	*            (le sommet de départ devient l'arrivée et vice-versa).
	*            Le graphe original n'est pas modifié.
	* Remarque : cette méthode n'utilise pas GORModifierArc afin d'éviter les
	*            conflits dans le cas où deux sommets sont reliés dans les deux sens.
	*********************************************************************************/
	PGrapheOriente<S, A>* GORInverserGraphe();
	
	/*********************************************************************************
	* GORtoString
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : chaine de caractère qui contient la représentation textuelle du graphe
	* Entraîne : génère et retourne une chaîne de caractères listant tous les sommets
	*            (avec leurs arcs) et tous les arcs du graphe dans leur état actuel
	*********************************************************************************/
	string GORtoString();

	/*********************************************************************************
	* GORAfficher
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : appel la méthode tostring et affiche son résultat dans la console
	*********************************************************************************/
	void GORAfficher() {
		cout << this->GORtoString() << endl;
	}

//ACCESSEURS

	/*********************************************************************************
	* GORsetvSommet
	* ********************************************************************************
	* Entrée : s, pointeur de type S (sommet générique), le sommet à ajouter au vector
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : ajoute le pointeur s au vecteur vGORSommets sans créer de nouvel objet
	*********************************************************************************/
	void GORsetvSommet(S* s) {
		vGORSommets.push_back(s);
	}

	/*********************************************************************************
	* GORsetvArc
	* ********************************************************************************
	* Entrée : a, pointeur de type A (arc générique), l'arc à ajouter au vector
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : ajoute le pointeur a au vecteur vGORArcs sans créer de nouvel objet
	*********************************************************************************/
	void GORsetvArc(A* a) {
		vGORArcs.push_back(a);
	}

	/*********************************************************************************
	* GORgetArcs
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : référence vers le vector des arcs du graphe
	* Entraîne : permet d'accéder directement au vecteur vGORArcs du graphe
	*********************************************************************************/
	vector<A*> GORgetArcs() {
		return vGORArcs;
	}

private:
	/*********************************************************************************
	* GORTrouverSommet
	* ********************************************************************************
	* Entrée : uiNumero, unsigned int, le numéro du sommet recherché
	* Nécessite : Rien
	* Sortie : pointeur S* vers le sommet trouvé, ou nullptr si introuvable
	* Entraîne : parcourt vGORSommets et retourne le pointeur du premier sommet dont
	*            le numéro correspond à uiNumero
	*********************************************************************************/
	S* GORTrouverSommet(unsigned int uiNumero);

	/*********************************************************************************
	* GORTrouverArc
	* ********************************************************************************
	* Entrée : uiNumeroDepart, unsigned int, le numéro du sommet de départ de l'arc
	*          uiNumeroArrive, unsigned int, le numéro du sommet d'arrivée de l'arc
	* Nécessite : Rien
	* Sortie : pointeur A* vers l'arc trouvé, ou nullptr si introuvable
	* Entraîne : parcourt vGORArcs et retourne le pointeur du premier arc dont les
	*            sommets de départ et d'arrivée correspondent aux numéros donnés
	*********************************************************************************/
	A* GORTrouverArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);
};

template <class S, class A>
PGrapheOriente<S, A>::~PGrapheOriente() {
	for (S* sommet : vGORSommets) {
		delete sommet;
	}
	vGORSommets.clear();
	vGORArcs.clear();
}

template <class S, class A>
void PGrapheOriente<S, A>::GORAjouterSommet(unsigned int uiNumero) {
	for (S* sommet : vGORSommets) {
		if (sommet->SOMgetNumero() == uiNumero) {
			throw CException(EXC_SOMMET_DEJA_EXISTANT,
				"GORAjouterSommet() : un sommet avec le numero " + to_string(uiNumero) + " existe deja.");
		}
	}
	S* s = new S(uiNumero);
	vGORSommets.push_back(s);
}

template <class S, class A>
void PGrapheOriente<S, A>::GORAjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
	S* sommetDep = GORTrouverSommet(uiNumeroDepart);
	S* sommetArr = GORTrouverSommet(uiNumeroArrive);

	if (sommetDep != nullptr && sommetArr != nullptr) { 
		A* nouvelArc = new A(sommetDep, sommetArr);
		vGORArcs.push_back(nouvelArc);
	}
	else {
		if (sommetDep == nullptr && sommetArr == nullptr) {
			throw CException(EXC_SOMMET_INTROUVABLE,
				"GORAjouterArc() : les deux sommets (" + to_string(uiNumeroDepart) + ", " + to_string(uiNumeroArrive) + ") sont inexistants.");
		}
		else if (sommetDep == nullptr) {
			throw CException(EXC_SOMMET_INTROUVABLE,
				"GORAjouterArc() : le sommet de DEPART (" + to_string(uiNumeroDepart) + ") est inexistant.");
		}
		else {
			throw CException(EXC_SOMMET_INTROUVABLE,
				"GORAjouterArc() : le sommet d'ARRIVEE (" + to_string(uiNumeroArrive) + ") est inexistant.");
		}
	}
}

template <class S, class A>
void PGrapheOriente<S, A>::GORSupprimerSommet(unsigned int uiNumero) {
	S* sommet = GORTrouverSommet(uiNumero); 
	if (sommet != nullptr) {
		for (A* arc : sommet->SOMgetvArcDep()) {
			vGORArcs.erase(remove(vGORArcs.begin(), vGORArcs.end(), arc), vGORArcs.end());
		}
		for (A* arc : sommet->SOMgetvArcArr()) { 
			vGORArcs.erase(remove(vGORArcs.begin(), vGORArcs.end(), arc), vGORArcs.end());
		}
		vGORSommets.erase(remove(vGORSommets.begin(), vGORSommets.end(), sommet), vGORSommets.end());

		delete sommet; 
	}
	else {
		throw CException(EXC_SOMMET_INTROUVABLE,
			"GORSupprimerSommet() : le sommet " + to_string(uiNumero) + " est introuvable.");
	}
}

template <class S, class A>
void PGrapheOriente<S, A>::GORSupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
	A* arc = GORTrouverArc(uiNumeroDepart, uiNumeroArrive);

	if (arc != nullptr) {
		vGORArcs.erase(remove(vGORArcs.begin(), vGORArcs.end(), arc), vGORArcs.end());
		delete arc;
	}
	else {
		throw CException(EXC_ARC_INTROUVABLE,
			"GORSupprimerArc() : l'arc (" + to_string(uiNumeroDepart) + ", " + to_string(uiNumeroArrive) + ") est introuvable.");
	}
}

template <class S, class A>
void PGrapheOriente<S, A>::GORModifierArc(unsigned int oldND, unsigned int oldNA, unsigned int newND, unsigned int newNA) {
	A* arc = GORTrouverArc(oldND, oldNA);

	if (arc == nullptr) {
		throw CException(EXC_ARC_INTROUVABLE,
			"GORModifierArc() : l'arc a modifier (" + to_string(oldND) + ", " + to_string(oldNA) + ") n'existe pas.");
	}

	A* arcExistant = GORTrouverArc(newND, newNA);
	if (arcExistant != nullptr) {
		throw CException(EXC_ARC_DEJA_EXISTANT,
			"GORModifierArc() : l'arc cible (" + to_string(newND) + ", " + to_string(newNA) + ") existe deja.");
	}

	if (GORTrouverSommet(newND) == nullptr || GORTrouverSommet(newNA) == nullptr) {
		throw CException(EXC_SOMMET_INTROUVABLE,
			"GORModifierArc() : un des sommets de destination n'existe pas.");
	}

	GORSupprimerArc(oldND, oldNA);
	GORAjouterArc(newND, newNA);
}

template <class S, class A>
PGrapheOriente<S, A>* PGrapheOriente<S, A>::GORInverserGraphe() {
	
	PGrapheOriente<S, A>* grapheInverse = new PGrapheOriente<S, A>();

	for (S* sommet : vGORSommets) {
		unsigned int numSommet = sommet->SOMgetNumero();
		grapheInverse->GORAjouterSommet(numSommet);
	}
	for (A* arc : vGORArcs) {
		unsigned int numDep = arc->ARCLireSommetDep();
		unsigned int numArr = arc->ARCLireSommetArr();
		grapheInverse->GORAjouterArc(numArr, numDep);
	}

	return grapheInverse;
}

template <class S, class A>
string PGrapheOriente<S, A>::GORtoString() {
	string s = "";
	s += "Graphe(\n";
	s += "-- Sommets --\n";
	for (S* sommet : vGORSommets) {
		s += sommet->SOMtoString();
	}
	s += "-- arcs --\n";
	for (A* arc : vGORArcs) {
		s += "    " + arc->ARCtoString() + "\n";
	}
	s += "\n)";
	return s;
}

template <class S, class A>
S* PGrapheOriente<S, A>::GORTrouverSommet(unsigned int uiNumero) {
	for (S* sommet : vGORSommets) { 
		if (sommet->SOMgetNumero() == uiNumero) { 
			return sommet;
		}
	}
	return nullptr;
}

template <class S, class A>
A* PGrapheOriente<S, A>::GORTrouverArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
	for (A* arc : vGORArcs) {
		if (arc->ARCLireSommetDep() == uiNumeroDepart && arc->ARCLireSommetArr() == uiNumeroArrive) {
			return arc;
		}
	}
	return nullptr;
}

#endif // !PGrapheOriente_H