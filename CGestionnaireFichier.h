#ifndef CGestionnaireFichier_H
#define CGestionnaireFichier_H

#include <string>
#include "PGrapheOriente.h"
#include <fstream>

using namespace std;

class CGestionnaireFichier {
private:
    int nbSommetsAttendu; // le nombre de sommet déclaré au début du fichier 
    int nbArcsAttendu; // le nombre d'arc déclaré au début du fichier
    vector<int> sommets; // les numéros de sommets trouvé dans le fichier (dans la section Sommets=[...])
    vector<pair<int, int>> arcs; // les pairs de numéros (Debut, Fin) trouvé dans la section Arcs=[...]
    PGrapheOriente<CSommet, CArc>* G;

public:
	// const & dest
    CGestionnaireFichier();

    ~CGestionnaireFichier() {};

    // méthodes 


    // juste pour afficher le contenu du fichier text brut (pour visualiser)
    void GSFAfficherContenuFichier(const string& chemin);


	/*
	* Prend une chaine de caractère contenant la représentation d'une graphe, analyse 
	* ce contenu et crée le graphe équivalent sous forme d'objet PGrapheOriente.
	*/


    // 1)
    void GSFCollectionDonneesFichierTXT(string sPath);


    // 2)
    bool GSFVerificationCoheranceDesDonnees();


    // 3)
    PGrapheOriente<CSommet, CArc>* GSFInstancierLeGraphe();

    // apelle des méthodes 1,2,3
    PGrapheOriente<CSommet, CArc>* GSFGenererGrapheDepuisFichier(string sPath);

	// accesseurs 

};




#endif // !1



