#ifndef CGestionnaireFichier_H
#define CGestionnaireFichier_H

#include <string>
#include "CGrapheOriente.h"
#include <fstream>

using namespace std;

class CGestionnaireFichier {
private:
    int nbSommetsAttendu; // le nombre de sommet déclaré au début du fichier 
    int nbArcsAttendu; // le nombre d'arc déclaré au début du fichier
    vector<int> sommets; // les numéros de sommets trouvé dans le fichier (dans la section Sommets=[...])
    vector<pair<int, int>> arcs; // les pairs de numéros (Debut, Fin) trouvé dans la section Arcs=[...]
    CGrapheOriente<CSommet, CArc>* G;

public:
	// const & dest
    CGestionnaireFichier();

    ~CGestionnaireFichier() {};

    // méthodes 


    // juste pour afficher le contenu du fichier text brut (pour visualiser)
    void AfficherContenuFichier(const string& chemin);


	/*
	* Prend une chaine de caractère contenant la représentation d'une graphe, analyse 
	* ce contenu et crée le graphe équivalent sous forme d'objet CGrapheOriente.
	*/


    // 1)
    void CollectionDonneesFichierTXT(string sPath);


    // 2)
    bool VerificationCoheranceDesDonnees();


    // 3)
    CGrapheOriente<CSommet, CArc>* InstancierLeGraphe();

    // apelle des méthodes 1,2,3
    CGrapheOriente<CSommet, CArc>* GenererGrapheDepuisFichier(string sPath);

	// accesseurs 

};




#endif // !1



