#ifndef CArc_H
#define CArc_H

/*********************************************************************************
* PATRON DE CLASSE : PArc
* ********************************************************************************
* ROLE: Chaque instance de cette classe représente un arc dans un graphe. Chaque
*	    arc dispose au moins pointeur vers un sommet de départ et pointeur vers un
*       sommet d'arrivé.
*       Cette classe est conçue pour être surchargée par d'autres classes filles
*       pour l'ajout d'attributs supplémentaires (distance, temps, poid, etc...)
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

template <class A> class PSommet;

template <class S>
class PArc {
// ATTRIBUTS :
protected:
	S* pSOMSommetDep;
	S* pSOMSommetArr;

// CONSTRUCTEURS ET DESTRUCTEURS
public:
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

	/*********************************************************************************
	* ARCAfficher
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : appel la méthode tostring et affiche son résultat dans la console
	*********************************************************************************/
	void ARCAfficher() {
		cout << this->ARCtoString() << endl;
	}

// ACCESSEURS
	/*********************************************************************************
	* ARCLireSommetDep
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le numéro du sommet de départ
	* Entraîne : permet d'accéder au numéro du sommet de départ via l'accesseur de 
	*			 cet instance de PSommet.
	*********************************************************************************/
	unsigned int ARCLireSommetDep() {
		return pSOMSommetDep->SOMgetNumero(); 
	}

	/*********************************************************************************
	* ARCLireSommetArr
	* ********************************************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le numéro du sommet de arrivée
	* Entraîne : permet d'accéder au numéro du sommet de arrivée via l'accesseur de
	*			 cet instance de PSommet.
	*********************************************************************************/
	unsigned int ARCLireSommetArr() {
		return pSOMSommetArr->SOMgetNumero(); 
	}
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

#endif // !CArc_H



