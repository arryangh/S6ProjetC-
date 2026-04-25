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

class CSommet; // pas faire include "CSommet.h" parce que y aura dépendance mutuelle

using namespace std;

class CArc {
// attributs
protected:
	CSommet* SMTSommetDep;
	CSommet* SMTSommetArr;

public:
	// CONSTRUCTEURS ET DESTRUCTEURS
	CArc(CSommet* s1, CSommet* s2);		
	~CArc();

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

#endif // !CArc_H



