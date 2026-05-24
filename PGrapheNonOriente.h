#ifndef PGrapheNonOriente_H
#define PGrapheNonOriente_H

/*********************************************************************************
* PATRON DE CLASSE : PGrapheNonOriente
* ********************************************************************************
* ROLE: Ce patron de classe hérite de PGrapheOriente et représente un graphe non
*       orienté. Chaque opération sur un arc (ajout, modification, suppression)
*       est automatiquement appliquée dans les deux sens afin de maintenir la
*       symétrie propre aux graphes non orientés.
* ********************************************************************************
* VERSION: 1.0
* AUTEUR: Anaëlle BENOIST & Aryan GHALEHNOEE
* DATE:
* ********************************************************************************
* INCLUSIONS EXTERNES:
*/
#include <vector>
#include "PSommet.h"
#include "PArc.h"
#include "PGrapheOriente.h"

template <class S, class A>
class PGrapheNonOriente : public PGrapheOriente<S, A> {
public:
//METHODES
    /*********************************************************************************
    * GORAjouterArc
    * ********************************************************************************
    * Entrée : uiNumeroDepart, unsigned int, le numéro du sommet de départ de l'arrête
    *          uiNumeroArrive, unsigned int, le numéro du sommet d'arrivée de l'arrête
    * Nécessite : les deux sommets doivent exister dans le graphe
    * Sortie : Rien
    * Entraîne : crée deux arcs symétriques (uiNumeroDepart, uiNumeroArrive) et
    *            (uiNumeroArrive, uiNumeroDepart) afin de simuler une arrête non
    *            orientée. Laisse la responsabilité de chaque création à GORAjouterArc
    *            de PGrapheOriente.
    *********************************************************************************/
    void GORAjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);
    
    /*********************************************************************************
    * GORModifierArc
    * ********************************************************************************
    * Entrée : oldND, unsigned int, le numéro du sommet de départ de l'arrête à modifier
    *          oldNA, unsigned int, le numéro du sommet d'arrivée de l'arrête à modifier
    *          newND, unsigned int, le numéro du nouveau sommet de départ
    *          newNA, unsigned int, le numéro du nouveau sommet d'arrivée
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : modifie les deux arcs symétriques représentant l'arrête
    *            (oldND, oldNA) devient (newND, newNA) et
    *            (oldNA, oldND) devient (newNA, newND).
    *            Laisse la responsabilité de chaque modification à GORModifierArc de 
    *            PGrapheOriente.
    *********************************************************************************/
    void GORModifierArc(unsigned int oldND, unsigned int oldNA, unsigned int newND, unsigned int newNA);
    
    /*********************************************************************************
    * GORSupprimerArc
    * ********************************************************************************
    * Entrée : uiNumeroDepart, unsigned int, le numéro du sommet de départ de l'arrête
    *          uiNumeroArrive, unsigned int, le numéro du sommet d'arrivée de l'arrête
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : supprime les deux arcs symétriques représentant l'arrête
    *            (uiNumeroDepart, uiNumeroArrive) et (uiNumeroArrive, uiNumeroDepart).
    *            Laisse la responsabilité de chaque suppression à GORSupprimerArc de 
    *            PGrapheOriente.
    *********************************************************************************/
    void GORSupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);

    /*********************************************************************************
    * GNOestCouplage
    * ********************************************************************************
    * Entrée : C, vector<A*>, un ensemble d'arcs à tester
    * Nécessite : Rien
    * Sortie : bool, true si C est un couplage valide, false sinon
    * Entraîne : vérifie que pour toute paire d'arcs (a1, a2) de C, les deux arcs
    *            ne partagent aucun sommet en commun (ni en départ ni en arrivée).
    *            Si deux arcs partagent un sommet, retourne false immédiatement.
    *            Si aucune paire d'arcs ne partage de sommet, retourne true.
    *********************************************************************************/
    bool GNOestCouplage(vector<A*> C);

    /*********************************************************************************
    * GNOTestCouplage
    * ********************************************************************************
    * Entrée : C, vector<A*>, un ensemble d'arcs à tester
    * Nécessite : Rien
    * Sortie : bool, true si C est un couplage de taille maximale (heuristique),
    *          false sinon
    * Entraîne : effectue les vérifications en trois étapes :
    *            1) vérifie que C est un couplage valide via GNOestCouplage(C).
    *               Si ce n'est pas le cas, affiche un message et retourne false.
    *            2) construit l'ensemble A\C, c'est-à-dire les arcs du graphe
    *               absents de C. (A privé de C)
    *            3) tente d'agrandir C en ajoutant chaque arc de A\C un par un.
    *               Si un arc peut être ajouté à C tout en maintenant un couplage
    *               valide (C' = C + {arc} est un couplage), alors C n'est pas
    *               maximal : affiche le couplage de cardinalité supérieure trouvé
    *               et retourne false.
    *            Si aucun arc de A\C ne peut agrandir C, retourne true.
    * Remarque : il s'agit d'une heuristique. Si la fonction retourne false, on est
    *            certain que C n'est pas maximal. Si elle retourne true, on ne peut
    *            pas conclure avec certitude que C est maximal.
    *********************************************************************************/
    bool GNOTestCouplage(vector<A*> C);
};

template <class S, class A>
void PGrapheNonOriente<S, A>::GORAjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
    PGrapheOriente<S, A>::GORAjouterArc(uiNumeroDepart, uiNumeroArrive);
    PGrapheOriente<S, A>::GORAjouterArc(uiNumeroArrive, uiNumeroDepart);
}

template <class S, class A>
void PGrapheNonOriente<S, A>::GORModifierArc(unsigned int oldND, unsigned int oldNA, unsigned int newND, unsigned int newNA) {
    PGrapheOriente<S, A>::GORModifierArc(oldND, oldNA, newND, newNA);
    PGrapheOriente<S, A>::GORModifierArc(oldNA, oldND, newNA, newND);
}

template <class S, class A>
void PGrapheNonOriente<S, A>::GORSupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
    PGrapheOriente<S, A>::GORSupprimerArc(uiNumeroDepart, uiNumeroArrive);
    PGrapheOriente<S, A>::GORSupprimerArc(uiNumeroArrive, uiNumeroDepart);
}

template <class S, class A>
bool PGrapheNonOriente<S, A>::GNOestCouplage(vector<A*> C) {
    for (int iArc = 0; iArc < C.size(); iArc++) {
        for (int iC = iArc + 1; iC < C.size(); iC++) {
            A* a1 = C[iArc];
            A* a2 = C[iC];
            if (a1->ARCLireSommetDep() == a2->ARCLireSommetDep()
                || a1->ARCLireSommetDep() == a2->ARCLireSommetArr()
                || a1->ARCLireSommetArr() == a2->ARCLireSommetDep()
                || a1->ARCLireSommetArr() == a2->ARCLireSommetArr()) {
                return false;
            }
        }
    }
    return true;
}


template <class S, class A>
bool PGrapheNonOriente<S, A>::GNOTestCouplage(vector<A*> C) {
    if (!GNOestCouplage(C)) {
        cout << "C n'est pas un couplage." << endl;
        return false;
    }
    else {
        for (int iArc = 0; iArc < this->vGORArcs.size(); iArc++) {
            A* arc = this->vGORArcs[iArc];
            
            if (arc->ARCLireSommetDep() >= arc->ARCLireSommetArr()) {
                continue;
            }

            bool estDansC = false;
            for (int iC = 0; iC < C.size(); iC++) {
                if (arc == C[iC]) {
                    estDansC = true;
                    break;
                }
            }
            if (!estDansC) {
                vector<A*> C_prime = C;
                C_prime.push_back(arc);
                if (GNOestCouplage(C_prime)) {
                    cout << "Il y a un couplage de cardinalité supérieure : \nC_prime = {";
                    for (int i = 0; i < (int)C_prime.size(); i++) {
                        cout << " (" << C_prime[i]->ARCLireSommetDep() << "," << C_prime[i]->ARCLireSommetArr() << ")";
                    }
                    cout << " }" << endl;
                    return false;
                }
            }
        }
        return true;
    }
}

#endif // !PGrapheNonOriente_H