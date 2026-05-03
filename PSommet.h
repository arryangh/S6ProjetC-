#ifndef PSommet_H
#define PSommet_H

/*********************************************************************************
* CLASSE : PSommet
* ********************************************************************************
* ROLE: Chaque instance de cette classe représante un sommet dans un graphe. Chaque 
*	    Sommet dispose au moins un vector de arc de départ et un vector d'arc d'arrivé.
*       Cette classe est conçue pour être surchargée par d'autres classes filles.
* ********************************************************************************
* VERSION: 1.0
* AUTEUR: Anaëlle BENOIST & Aryan GHALEHNOEE
* DATE: 
* ********************************************************************************
* INCLUSIONS EXTERNES:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <class S> class PArc; //Déclaration de PArc pour gérer pour la dépendance circulaire

template <class A>
class PSommet {
// ATTRIBUTS :
protected:
	unsigned int uiSOMNumero;
	vector<A*>vSOMArcDep; //vecteur contenant les pointeur de type A* (les arcs sortant)
	vector<A*>vSOMArcArr; //vecteur contenant les pointeur de type A* (les arcs entrant)

public:
// CONSTRUCTEURS ET DESTRUCTEURS
	PSommet(unsigned int numero) {
		uiSOMNumero = numero;
	}

	~PSommet();

// METHODES
	/*********************************************************************************
	* SOMretirerArcD
	* ********************************************************************************
	* Entrée : pArc, pointeur de A, le pointeur de l'arc à retirer du vector des arcs de départ
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : toutes les occurances de l'arc sont supprimés du vector des arcs de départ
	*			 si le pointeur n'est pas dans le vector, le vector n'est pas modifié
	*********************************************************************************/
	template <class T>
	void SOMretirerArcD(T* pArc) {
		vSOMArcDep.erase(remove(vSOMArcDep.begin(), vSOMArcDep.end(), (A*)pArc),vSOMArcDep.end());//cast acr il ne peut pas comparer T* et A*
	}

	/*********************************************************************************
	* SOMretirerArcA
	* ********************************************************************************
	* Entrée : pArc, pointeur de A, le pointeur de l'arc à retirer du vector des arcs d'arrivé
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : toutes les occurances de l'arc sont supprimés du vector des arcs d'arrivé
	*			 si le pointeur n'est pas dans le vector, le vector n'est pas modifié
	*********************************************************************************/
	template <class T>
	void SOMretirerArcA(T* pArc) {
		vSOMArcArr.erase(remove(vSOMArcArr.begin(), vSOMArcArr.end(), (A*)pArc), vSOMArcArr.end());
	}

	/*********************************************************************************
	* SOMtoString
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Affiche l'instance appelant en console dans sont état à l'instant de
	*            l'appel de la méthode. l'affichage inclue le numéro du sommet et les 
	*            élèments des vectors d'arcs de départs et d'arrivés
	*********************************************************************************/
	string SOMtoString();

// ACCESSEURS
	unsigned int SOMgetNumero() {
		return uiSOMNumero;
	}

	const vector<A*>& SOMgetvArcDep() const {
		return vSOMArcDep;
	}

	const vector<A*>& SOMgetvArcArr() const {
		return vSOMArcArr;
	}
	
	template <class T>
	void SOMsetvArcDep(T* a) {
		vSOMArcDep.push_back((A*)a);

	}

	template <class T>
	void SOMsetvArcArr(T* a) {
		vSOMArcArr.push_back((A*)a);
	}
};

/*
* PSommet::~PSommet() {
	for (A* CArcDep : vArcDep) {
		delete CArcDep;
	}
	for (A* CArcArr : vArcArr) {
		delete CArcArr;
	}
}
ATTENTION: dans la version qui se trouve juste en haut, le déstructeur du sommet supprime les arcs partants et
arrivants.
	- le problème c'est que chaque arc se trouve dans 2 sommets.
	- quand on arrive au 2ième sommets, on essayera de resupprimer cet arc, mais il n'existe plus
	- de plus, quand le premier sommet supprime l'arc, le deuxième pointe vers le vide

SOLUTION:
	- dans le déstructeur de PSommet, on supprime que les arcs de départ
	- c'est le déstructeur de CArc qui retire l'arc du sommet d'arrivé (méthode

*/

template <class A>
PSommet<A>::~PSommet() {
	// supprimer les arcs partants (on les possède)
	vector<A*> copieD = vSOMArcDep;
	for (A* arc : copieD) {
		delete arc;
	}

	// supprimer les arcs arrivants (possédés par d'autres sommets, 
	// mais ils pointent vers nous donc il faut les supprimer aussi)
	vector<A*> copieA = vSOMArcArr;
	for (A* arc : copieA) {
		delete arc;
	}
}

// toString
template <class A>
string PSommet<A>::SOMtoString() {
	string s = "";
	s += "    Sommet(" + to_string(uiSOMNumero) + ")\n";

	s += "        Arcs partants: ";
	for (A* arc : vSOMArcDep) {
		s += arc->ARCtoString() + " ";
	}
	s += "\n";

	s += "        Arcs arrivants: ";
	for (A* arc : vSOMArcArr) {
		s += arc->ARCtoString() + " ";
	}
	s += "\n";

	return s;
}




#endif // !PSommet_H



