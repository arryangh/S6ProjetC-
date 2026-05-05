#ifndef PSommet_H
#define PSommet_H

/*********************************************************************************
* PATRON DE CLASSE : PSommet
* ********************************************************************************
* ROLE: Chaque instance de cette classe représante un sommet dans un graphe. Chaque 
*	    Sommet dispose au moins un vector de pointeur d'arc de départ et un vector 
		de pointeur d'arc d'arrivé.
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

template <class S> class PArc; 
template <class A>
class PSommet {
// ATTRIBUTS :
protected:
	unsigned int uiSOMNumero;
	vector<A*>vSOMArcDep; 
	vector<A*>vSOMArcArr; 

// CONSTRUCTEURS ET DESTRUCTEURS
public:
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

	/*********************************************************************************
	* SOMgetvArcDep
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : référence constante vers le vector des arcs de départ
	* Entraîne : permet d'accéder aux arcs sortants du sommet sans les modifier
	*********************************************************************************/
	const vector<A*>& SOMgetvArcDep() const {
		return vSOMArcDep;
	}

	/*********************************************************************************
	* SOMgetvArcArr
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : référence constante vers le vector des arcs d'arrivée
	* Entraîne : permet d'accéder aux arcs entrants du sommet sans les modifier
	*********************************************************************************/
	const vector<A*>& SOMgetvArcArr() const {
		return vSOMArcArr;
	}
	
	/*********************************************************************************
	* SOMsetvArcDep
	* ********************************************************************************
	* Entrée : a, pointeur de type A représentant un arc à ajouter
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : ajoute un arc au vector des arcs de départ du sommet
	*            effectue un cast de T* vers A*
	*********************************************************************************/
	template <class T>
	void SOMsetvArcDep(T* a) {
		vSOMArcDep.push_back((A*)a);
	}

	/*********************************************************************************
	* SOMsetvArcArr
	* ********************************************************************************
	* Entrée : a, pointeur de type A représentant un arc à ajouter
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : ajoute un arc au vector des arcs d'arrivée du sommet
	*            effectue un cast de T* vers A*
	*********************************************************************************/
	template <class T>
	void SOMsetvArcArr(T* a) {
		vSOMArcArr.push_back((A*)a);
	}
};

template <class A>
PSommet<A>::~PSommet() {
	vector<A*> copieD = vSOMArcDep;
	for (A* arc : copieD) {
		delete arc;
	}
	vector<A*> copieA = vSOMArcArr;
	for (A* arc : copieA) {
		delete arc;
	}
}

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