#ifndef PGestionnaireFichier_H
#define PGestionnaireFichier_H

/*********************************************************************************
* PATRON DE CLASSE : PGestionnaireFichier
* ********************************************************************************
* ROLE: Ce patron de classe gère la lecture et l'interprétation de fichiers texte
*       décrivant un graphe orienté. Il collecte les données du fichier, vérifie
*       leur cohérence, puis instancie le graphe correspondant sous forme d'objet
*       PGrapheOriente.
* ********************************************************************************
* VERSION: 1.0
* AUTEUR: Anaëlle BENOIST & Aryan GHALEHNOEE
* DATE:
* ********************************************************************************
* INCLUSIONS EXTERNES:
*/
#include <string>
#include "PGrapheOriente.h"
#include <fstream>

using namespace std;

template <class S, class A>
class PGestionnaireFichier {
// ATTRIBUTS :
private:
    int iGSFnbSommetsAttendu;  
    int iGSFnbArcsAttendu; 
    vector<int> vGSFsommets;
    vector<pair<int, int>> vGSFarcs; 
    PGrapheOriente<S, A>* pGORGSFGraphe;

// CONSTRUCTEURS ET DESTRUCTEURS
public:
    PGestionnaireFichier();
    ~PGestionnaireFichier() {};

// METHODES
    /*********************************************************************************
    * GSFAfficherContenuFichier
    * ********************************************************************************
    * Entrée : path, string, le chemin vers le fichier texte à afficher
    * Nécessite : que le fichier existe et soit accessible en lecture
    * Sortie : Rien
    * Entraîne : ouvre le fichier et affiche son contenu brut ligne par ligne en console.
    *            Si le fichier est introuvable, un message d'erreur est affiché et la
    *            méthode s'arrête sans planter.
    *********************************************************************************/
    void GSFAfficherContenuFichier(const string& sPath);

    /*********************************************************************************
    * GSFCollectionDonneesFichierTXT
    * ********************************************************************************
    * Entrée : sPath, string, le chemin vers le fichier texte à analyser
    * Nécessite : que le fichier respecte le format attendu du projet
    *             (NBSommets=, NBArcs=, Numero=, Debut=...Fin=...)
    * Sortie : Rien
    * Entraîne : lit le fichier ligne par ligne et remplit les attributs
    *            iGSFnbSommetsAttendu, iGSFnbArcsAttendu, vGSFsommets et vGSFarcs
    *            à partir des données trouvées.
    *            Si le fichier est introuvable, un message d'erreur est affiché en console.
    *********************************************************************************/
    void GSFCollectionDonneesFichierTXT(string sPath);
    
    /*********************************************************************************
    * GSFVerificationCoheranceDesDonnees
    * ********************************************************************************
    * Entrée : Rien
    * Nécessite : que GSFCollectionDonneesFichierTXT ait été appelée au préalable
    * Sortie : bool, true si les données sont cohérentes, false sinon
    * Entraîne : vérifie que le nombre de sommets trouvés dans vGSFsommets correspond
    *            à iGSFnbSommetsAttendu, et que le nombre d'arcs trouvés dans vGSFarcs
    *            correspond à iGSFnbArcsAttendu.
    *            Affiche un message d'erreur en console pour chaque incohérence détectée.
    *********************************************************************************/
    bool GSFVerificationCoheranceDesDonnees();
    
    /*********************************************************************************
    * GSFInstancierLeGraphe
    * ********************************************************************************
    * Entrée : Rien
    * Nécessite : que GSFCollectionDonneesFichierTXT et GSFVerificationCoheranceDesDonnees
    *             aient été appelées avec succès au préalable
    * Sortie : pointeur vers un nouveau PGrapheOriente<S, A>
    * Entraîne : crée un nouveau graphe orienté, y ajoute tous les sommets de vGSFsommets
    *            puis tous les arcs de vGSFarcs. Stocke également le pointeur du graphe
    *            dans l'attribut pGORGSFGraphe.
    *********************************************************************************/
    PGrapheOriente<S, A>* GSFInstancierLeGraphe();

    /*********************************************************************************
    * GSFGenererGrapheDepuisFichier
    * ********************************************************************************
    * Entrée : sPath, string, le chemin vers le fichier texte décrivant le graphe
    * Nécessite : que le fichier existe et respecte le format attendu du projet
    * Sortie : pointeur vers un nouveau PGrapheOriente<S, A>, ou nullptr en cas d'échec
    * Entraîne : gère l'appel des trois étapes dans l'ordre :
    *            1) GSFCollectionDonneesFichierTXT : lecture et collecte des données
    *            2) GSFVerificationCoheranceDesDonnees : vérification de la cohérence
    *            3) GSFInstancierLeGraphe : création et retour du graphe
    *            Si la vérification échoue, retourne nullptr.
    *********************************************************************************/
    PGrapheOriente<S, A>* GSFGenererGrapheDepuisFichier(string sPath);
};

template <class S, class A>
PGestionnaireFichier<S,A>::PGestionnaireFichier() {
    iGSFnbSommetsAttendu = 0; 
    iGSFnbArcsAttendu = 0;
    pGORGSFGraphe = nullptr;
}

template <class S, class A>
void PGestionnaireFichier<S,A>::GSFAfficherContenuFichier(const string& sPath) {
    ifstream fichier(sPath);

    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier." << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }
}

template <class S, class A>
void PGestionnaireFichier<S,A>::GSFCollectionDonneesFichierTXT(string sPath) {
    ifstream fichier(sPath);

    if (!fichier) {
        cerr << "CGestionnaireFichier->CollectionDonneesFichierTXT(): Erreur : impossible d'ouvrir le fichier." << endl;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        if (!ligne.empty() && ligne.back() == ' ')
            ligne.pop_back();

        if (ligne.find("NBSommets=") != string::npos) {
            iGSFnbSommetsAttendu = stoi(ligne.substr(ligne.find("=") + 1));
        }
        else if (ligne.find("NBArcs=") != string::npos) {
            iGSFnbArcsAttendu = stoi(ligne.substr(ligne.find("=") + 1));
        }
        else if (ligne.find("Numero=") != string::npos) {
            int numero = stoi(ligne.substr(ligne.find("=") + 1));
            vGSFsommets.push_back(numero);
        }
        else if (ligne.find("Debut=") != string::npos) {
            int numDeb = stoi(ligne.substr(ligne.find("Debut=") + 6));
            int numFin = stoi(ligne.substr(ligne.find("Fin=") + 4));
            vGSFarcs.push_back(make_pair(numDeb, numFin));
        }
    }
    cout << "1) les donnees du fichier on ete collecte avec succes" << endl;
}

template <class S, class A>
bool PGestionnaireFichier<S,A>::GSFVerificationCoheranceDesDonnees() {
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

    PGestionnaireFichier<S,A>::pGORGSFGraphe = graphe; 

    return graphe;
}

template <class S, class A>
PGrapheOriente<S, A>* PGestionnaireFichier<S,A>::GSFGenererGrapheDepuisFichier(string sPath) {
    cout << "lecture de fichier et generation de graphe..." << endl;
    GSFCollectionDonneesFichierTXT(sPath); 
    if (GSFVerificationCoheranceDesDonnees()) { 
        return GSFInstancierLeGraphe(); 
    }
    return nullptr;
}

#endif // !PGestionnaireFichier_H