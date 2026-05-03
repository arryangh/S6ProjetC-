#ifndef PGestionnaireFichier_H
#define PGestionnaireFichier_H

#include <string>
#include "PGrapheOriente.h"
#include <fstream>

using namespace std;

template <class S, class A>
class PGestionnaireFichier {
// ATTRIBUTS :
private:
    int iGSFnbSommetsAttendu; // le nombre de sommet déclaré au début du fichier 
    int iGSFnbArcsAttendu; // le nombre d'arc déclaré au début du fichier
    vector<int> vGSFsommets; // les numéros de sommets trouvé dans le fichier (dans la section Sommets=[...])
    vector<pair<int, int>> vGSFarcs; // les pairs de numéros (Debut, Fin) trouvé dans la section Arcs=[...]
    PGrapheOriente<S, A>* pGORGSFGraphe;

public:
// CONSTRUCTEURS ET DESTRUCTEURS
    PGestionnaireFichier();
    ~PGestionnaireFichier() {};

// METHODES
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
    PGrapheOriente<S, A>* GSFInstancierLeGraphe();

    // apelle des méthodes 1,2,3
    PGrapheOriente<S, A>* GSFGenererGrapheDepuisFichier(string sPath);
};

template <class S, class A>
PGestionnaireFichier<S,A>::PGestionnaireFichier() {
    iGSFnbSommetsAttendu = 0; // le nombre de sommet déclaré au début du fichier, fixé à 0 au début
    iGSFnbArcsAttendu = 0; // le nombre d'arc déclaré au début du fichier, fixé à 0 au début
    pGORGSFGraphe = nullptr; //penser à initialiser les pointeur
}

template <class S, class A>
void PGestionnaireFichier<S,A>::GSFAfficherContenuFichier(const string& chemin) {
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

//1
template <class S, class A>
void PGestionnaireFichier<S,A>::GSFCollectionDonneesFichierTXT(string sPath) {
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
            iGSFnbSommetsAttendu = stoi(ligne.substr(ligne.find("=") + 1));
        }
        else if (ligne.find("NBArcs=") != string::npos) {
            iGSFnbArcsAttendu = stoi(ligne.substr(ligne.find("=") + 1));
        }
        else if (ligne.find("Numero=") != string::npos) {
            // lignes de type: Numero=1 => stoi("1)
            int numero = stoi(ligne.substr(ligne.find("=") + 1));
            vGSFsommets.push_back(numero);
        }
        else if (ligne.find("Debut=") != string::npos) {
            // lignes de type: "Debut=1, Fin=2" => stoi("1, Fin=2) = stoi("1") car stoi s'arrête dès qu'il y a pas un numéro
            int numDeb = stoi(ligne.substr(ligne.find("Debut=") + 6));
            int numFin = stoi(ligne.substr(ligne.find("Fin=") + 4));
            vGSFarcs.push_back(make_pair(numDeb, numFin));
        }
    }
    cout << "1) les donnees du fichier on ete collecte avec succes" << endl;
}

//2
template <class S, class A>
bool PGestionnaireFichier<S,A>::GSFVerificationCoheranceDesDonnees() {
    // vérifications
    if ((int)vGSFsommets.size() != iGSFnbSommetsAttendu) {
        cerr << "Erreur : nombre de sommets détectés (" << vGSFsommets.size()
            << ") ne correspond pas à celui déclaré (" << iGSFnbSommetsAttendu << ")." << endl;
        return false;
    }
    if ((int)vGSFarcs.size() != iGSFnbArcsAttendu) {
        cerr << "Erreur : nombre d'arcs détectés (" << vGSFarcs.size()
            << ") ne correspond pas à celui déclaré (" << iGSFnbArcsAttendu << ")." << endl;
        return false;
    }

    cout << "2) la coherance des donnees verifie avec succes" << endl;

    return true;
}

//3
template <class S, class A>
PGrapheOriente<S, A>* PGestionnaireFichier<S,A>::GSFInstancierLeGraphe() {
    PGrapheOriente<S, A>* graphe = new PGrapheOriente<S, A>();

    for (int numero : vGSFsommets) {
        graphe->GORAjouterSommet(numero);
    }
    for (pair<int, int> arc : vGSFarcs) {
        graphe->GORAjouterArc(arc.first, arc.second);
    }

    cout << "3) graphe genere avec succes" << endl;

    PGestionnaireFichier<S,A>::pGORGSFGraphe = graphe; // est ce que c'est vraiment utile de l'avoir en attribut? 
    // bien faire attention au fait que c'est un pointeur vers le même graphe en mémoire, peut être qu'il fallait 
    // gérer ça avec "const" avec une histoire de copie etc, à voir

    return graphe;
}

// apelle des méthodes 1,2,3
template <class S, class A>
PGrapheOriente<S, A>* PGestionnaireFichier<S,A>::GSFGenererGrapheDepuisFichier(string sPath) {
    cout << "lecture de fichier et generation de graphe..." << endl;
    GSFCollectionDonneesFichierTXT(sPath); // 1)
    if (GSFVerificationCoheranceDesDonnees()) { // 2)
        return GSFInstancierLeGraphe(); //3)
    }
    return nullptr; // si 2 renvoie false
}

#endif // !1