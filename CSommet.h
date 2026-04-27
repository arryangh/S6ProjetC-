#ifndef CSommet_H
#define CSommet_H

/*********************************************************************************
* CLASSE : CSommet
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
#include "CArc.h"
#include <string>

using namespace std;

class CSommet {
// ATTRIBUTS :
protected:
	unsigned int uiSOMNumero;
	vector<CArc*>vSOMArcDep; //vecteur contenant les pointeur de type CArc* (les arcs sortant)
	vector<CArc*>vSOMArcArr; //vecteur contenant les pointeur de type CArc* (les arcs entrant)

public:
// CONSTRUCTEURS ET DESTRUCTEURS
	CSommet(unsigned int numero) {
		uiSOMNumero = numero;
	}

	~CSommet();

// METHODES
	/*********************************************************************************
	* SOMretirerArcD
	* ********************************************************************************
	* Entrée : pArc, pointeur de CArc, le pointeur de l'arc à retirer du vector des arcs de départ
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : toutes les occurances de l'arc sont supprimés du vector des arcs de départ
	*			 si le pointeur n'est pas dans le vector, le vector n'est pas modifié
	*********************************************************************************/
	void SOMretirerArcD(CArc* pArc) {
		vSOMArcDep.erase(remove(vSOMArcDep.begin(), vSOMArcDep.end(), pArc),vSOMArcDep.end());
	}

	/*********************************************************************************
	* SOMretirerArcA
	* ********************************************************************************
	* Entrée : pArc, pointeur de CArc, le pointeur de l'arc à retirer du vector des arcs d'arrivé
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : toutes les occurances de l'arc sont supprimés du vector des arcs d'arrivé
	*			 si le pointeur n'est pas dans le vector, le vector n'est pas modifié
	*********************************************************************************/
	void SOMretirerArcA(CArc* pArc) {
		vSOMArcArr.erase(remove(vSOMArcArr.begin(), vSOMArcArr.end(), pArc), vSOMArcArr.end());
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

	const vector<CArc*>& SOMgetvArcDep() const {
		return vSOMArcDep;
	}

	const vector<CArc*>& SOMgetvArcArr() const {
		return vSOMArcArr;
	}
	
	void SOMsetvArcDep(CArc* a) {
		vSOMArcDep.push_back(a);

	}

	void SOMsetvArcArr(CArc* a) {
		vSOMArcArr.push_back(a);
	}
};

#endif // !CSommet_H



