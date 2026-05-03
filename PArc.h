#ifndef CArc_H
#define CArc_H

/*********************************************************************************
* CLASSE : CArc
* ********************************************************************************
* ROLE: Chaque instance de cette classe représante un arc dans un graphe. Chaque
*	    arc dispose au moins pointeur vers un sommet de départ et pointeur vers un
*       sommet d'arrivé.
*       Cette classe est conçue pour être surchargée par d'autres classes filles
*       pour l'ajout d'attributs supplémentaires (distance, temps, poid, etc)
* ********************************************************************************
* VERSION: 1.0
* AUTEUR: Anaëlle BENOIST & Aryan GHALEHNOEE
* DATE:
* ********************************************************************************
* INCLUSIONS EXTERNES:
*/
#include <iostream>
#include <string>

using namespace std;

template <class A> class PSommet; //Déclaration de PArc pour gérer pour la dépendance circulaire

template <class S>
class PArc {
// attributs
protected:
	S* pSOMSommetDep;
	S* pSOMSommetArr;

public:
	// CONSTRUCTEURS ET DESTRUCTEURS
	PArc(S* s1, S* s2);		
	~PArc();

	// METHODES 



	/*********************************************************************************
	* SOMtoString
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Affiche l'instance appelant en console dans sont état à l'instant de
	*            l'appel de la méthode. l'affichage inclue le numéro du sommet de départ 
	*			 et le numéro du sommet d'arrivé.
	*********************************************************************************/
	string ARCtoString();

	// accesseurs 
	unsigned int ARCLireSommetDep();
	unsigned int ARCLireSommetArr();

}; 

template <class S>
PArc<S>::PArc(S* s1, S* s2) {
	pSOMSommetDep = s1;
	pSOMSommetArr = s2;

	pSOMSommetDep->SOMsetvArcDep(this);
	pSOMSommetArr->SOMsetvArcArr(this);
}

template <class S>
PArc<S>::~PArc() {
	pSOMSommetArr->SOMretirerArcA(this);
	pSOMSommetDep->SOMretirerArcD(this);
}

template <class S>
string PArc<S>::ARCtoString() {
	string s = "";
	s += "Arc(dep:";
	s += to_string(pSOMSommetDep->SOMgetNumero());
	s += ", arr:";
	s += to_string(pSOMSommetArr->SOMgetNumero());
	s += ")";
	return s;
}

template <class S>
unsigned int PArc<S>::ARCLireSommetDep() {
	return pSOMSommetDep->SOMgetNumero(); // renovyer le numéro du sommet de départ
}

template <class S>
unsigned int PArc<S>::ARCLireSommetArr() {
	return pSOMSommetArr->SOMgetNumero(); // renovyer le numéro du sommet de d'arrivé
}


#endif // !CArc_H



