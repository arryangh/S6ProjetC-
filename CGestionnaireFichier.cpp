#include "CGestionnaireFichier.h"

CGestionnaireFichier::CGestionnaireFichier() {
    nbSommetsAttendu = 0; // le nombre de sommet déclaré au début du fichier, fixé à 0 au début
    nbArcsAttendu = 0; // le nombre d'arc déclaré au début du fichier, fixé à 0 au début
    G = nullptr; //penser à initialiser les pointeur
}

void CGestionnaireFichier::GSFAfficherContenuFichier(const string& chemin) {
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
void CGestionnaireFichier::GSFCollectionDonneesFichierTXT(string sPath) {
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

//2
bool CGestionnaireFichier::GSFVerificationCoheranceDesDonnees() {
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

    cout << "2) la coherance des donnees verifie avec succes" << endl;

    return true;
}

//3
PGrapheOriente<CSommet, CArc>* CGestionnaireFichier::GSFInstancierLeGraphe() {
    PGrapheOriente<CSommet, CArc>* graphe = new PGrapheOriente<CSommet, CArc>();

    for (int numero : sommets) {
        graphe->GORAjouterSommet(numero);
    }
    for (pair<int, int> arc : arcs) {
        graphe->GORAjouterArc(arc.first, arc.second);
    }

    cout << "3) graphe genere avec succes" << endl;

    CGestionnaireFichier::G = graphe; // est ce que c'est vraiment utile de l'avoir en attribut? 
    // bien faire attention au fait que c'est un pointeur vers le même graphe en mémoire, peut être qu'il fallait 
    // gérer ça avec "const" avec une histoire de copie etc, à voir

    return graphe;
}


// apelle des méthodes 1,2,3
PGrapheOriente<CSommet, CArc>* CGestionnaireFichier::GSFGenererGrapheDepuisFichier(string sPath) {
    cout << "lecture de fichier et generation de graphe..." << endl;
    GSFCollectionDonneesFichierTXT(sPath); // 1)
    if (GSFVerificationCoheranceDesDonnees()) { // 2)
        return GSFInstancierLeGraphe(); //3)
    }
    return nullptr; // si 2 renvoie false
}