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

public:
	// const & dest
	CGestionnaireFichier() {
        nbSommetsAttendu = 0; // le nombre de sommet déclaré au début du fichier, fixé à 0 au début
        nbArcsAttendu = 0; // le nombre d'arc déclaré au début du fichier, fixé à 0 au début
	}
	~CGestionnaireFichier() {

	}


    // juste pour afficher le contenu du fichier text brut (pour visualiser)
    void AfficherContenuFichier(const string& chemin) {
        ifstream fichier(chemin);

		if (!fichier) {
			cerr << "Erreur : impossible d'ouvrir le fichier." << endl;
			return;
		}

		string ligne;
		while (getline(fichier, ligne)) {
			cout << ligne << endl;
		}
	}


	/*
	* Prend une chaine de caractère contenant la représentation d'une graphe, analyse 
	* ce contenu et crée le graphe équivalent sous forme d'objet CGrapheOriente.
	*/


    // 1)
    void CollectionDonneesFichierTXT(string sPath) {
        ifstream fichier(sPath);

        if (!fichier) {
            cerr << "CGestionnaireFichier->CollectionDonneesFichierTXT(): Erreur : impossible d'ouvrir le fichier." << endl;
        }

        string ligne;
        while (getline(fichier, ligne)) {
            // supprimer les espaces en fin de ligne (problème fréquent avec les fichiers texte)
            if (!ligne.empty() && ligne.back() == ' ')
                ligne.pop_back();

            if (ligne.find("NBSommets=") != string::npos) {
                nbSommetsAttendu = stoi(ligne.substr(ligne.find("=") + 1));
            }
            else if (ligne.find("NBArcs=") != string::npos) {
                nbArcsAttendu = stoi(ligne.substr(ligne.find("=") + 1));
            }
            else if (ligne.find("Numero=") != string::npos) {
                // lignes de type: Numero=1 => stoi("1)
                int numero = stoi(ligne.substr(ligne.find("=") + 1));
                sommets.push_back(numero);
            }
            else if (ligne.find("Debut=") != string::npos) {
                // lignes de type: "Debut=1, Fin=2" => stoi("1, Fin=2) = stoi("1") car stoi s'arrête dès qu'il y a pas un numéro
                int numDeb = stoi(ligne.substr(ligne.find("Debut=") + 6));
                int numFin = stoi(ligne.substr(ligne.find("Fin=") + 4));
                arcs.push_back(make_pair(numDeb, numFin));
            }
        }
        cout << "1) les donnees du fichier on ete collecte avec succes" << endl;
    }


    // 2)
    bool VerificationCoheranceDesDonnees() {
        // vérifications
        if ((int)sommets.size() != nbSommetsAttendu) {
            cerr << "Erreur : nombre de sommets détectés (" << sommets.size()
                << ") ne correspond pas à celui déclaré (" << nbSommetsAttendu << ")." << endl;
            return false;
        }
        if ((int)arcs.size() != nbArcsAttendu) {
            cerr << "Erreur : nombre d'arcs détectés (" << arcs.size()
                << ") ne correspond pas à celui déclaré (" << nbArcsAttendu << ")." << endl;
            return false;
        }

        cout << "la coherance des donnees verifie avec succes" << endl;

        return true;
    }


    // 3)
    CGrapheOriente<CSommet, CArc>* InstancierLeGraphe() {
        CGrapheOriente<CSommet, CArc>* graphe = new CGrapheOriente<CSommet, CArc>();

        for (int numero : sommets) {
            graphe->AjouterSommet(numero);
        }
        for (pair<int, int> arc : arcs) {
            graphe->AjouterArc(arc.first, arc.second);
        }

        return graphe;
    }


    // apelle des méthodes 1,2,3
    CGrapheOriente<CSommet, CArc>* GenererGrapheDepuisFichier(string sPath) {
        CollectionDonneesFichierTXT(sPath); // 1)
        if (VerificationCoheranceDesDonnees()) { // 2)
            return InstancierLeGraphe(); //3)
        }
        return nullptr; // si 2 renvoie false
    }



	// 1, 2, 3 (le tout dans la même fonction)
    CGrapheOriente<CSommet, CArc>* InterpreterContenuFichier(string sPath) {
        ifstream fichier(sPath);

        if (!fichier) {
            cerr << "Erreur : impossible d'ouvrir le fichier." << endl;
            return nullptr;
        }

        int nbSommetsAttendu = 0;
        int nbArcsAttendu = 0;
        vector<int> sommets;
        vector<pair<int, int>> arcs;

        string ligne;
        while (getline(fichier, ligne)) {
            // supprimer les espaces en fin de ligne (problème fréquent avec les fichiers texte)
            if (!ligne.empty() && ligne.back() == ' ')
                ligne.pop_back();

            if (ligne.find("NBSommets=") != string::npos) {
                nbSommetsAttendu = stoi(ligne.substr(ligne.find("=") + 1));
            }
            else if (ligne.find("NBArcs=") != string::npos) {
                nbArcsAttendu = stoi(ligne.substr(ligne.find("=") + 1));
            }
            else if (ligne.find("Numero=") != string::npos) {
                // lignes de type: Numero=1 => stoi("1)
                int numero = stoi(ligne.substr(ligne.find("=") + 1));
                sommets.push_back(numero);
            }
            else if (ligne.find("Debut=") != string::npos) {
                // lignes de type: "Debut=1, Fin=2" => stoi("1, Fin=2) = stoi("1") car stoi s'arrête dès qu'il y a pas un numéro
                int numDeb = stoi(ligne.substr(ligne.find("Debut=") + 6));
                int numFin = stoi(ligne.substr(ligne.find("Fin=") + 4));
                arcs.push_back(make_pair(numDeb, numFin));
            }
        }

        // vérifications
        if ((int)sommets.size() != nbSommetsAttendu) {
            cerr << "Erreur : nombre de sommets détectés (" << sommets.size()
                << ") ne correspond pas à celui déclaré (" << nbSommetsAttendu << ")." << endl;
            return nullptr;
        }
        if ((int)arcs.size() != nbArcsAttendu) {
            cerr << "Erreur : nombre d'arcs détectés (" << arcs.size()
                << ") ne correspond pas à celui déclaré (" << nbArcsAttendu << ")." << endl;
            return nullptr;
        }

        // créer le graphe
        CGrapheOriente<CSommet, CArc>* graphe = new CGrapheOriente<CSommet, CArc>();

        for (int numero : sommets) {
            graphe->AjouterSommet(numero);
        }
        for (pair<int, int> arc : arcs) {
            graphe->AjouterArc(arc.first, arc.second);
        }

        return graphe;
    }


    


	// méthodes 


	// accesseurs 

};


/*
* Charge un fichier texte à partir du chemin donné en paramètre et renvoie
* son contenu sous forme de chaine de caractère
string ChargerDepuisFichier(string sPath) {

}
*/


#endif // !1



