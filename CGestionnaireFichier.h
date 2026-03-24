#ifndef CGestionnaireFichier_H
#define CGestionnaireFichier_H

#include <string>
#include "CGrapheOriente.h"

using namespace std;



class CGestionnaireFichier {
protected:


public:
	// const & dest
	CGestionnaireFichier();
	~CGestionnaireFichier();

	/*
	* Charge un fichier texte à partir du chemin donné en paramètre et renvoie 
	* son contenu sous forme de chaine de caractère 
	*/
	string ChargerDepuisFichier(string sPath);


	/*
	* Prend une chaine de caractère contenant la représentation d'une graphe, analyse 
	* ce contenu et crée le graphe équivalent sous forme d'objet CGrapheOriente.
	*/
	CGrapheOriente<CSommet, CArc>* InterpreterContenuFichier(string sContenuFichier);






	// méthodes 


	// accesseurs 

};



#endif // !1



