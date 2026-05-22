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

    bool GNOestCouplage(vector<A*> C);


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
    for (int index_1 = 0; index_1 < C.size(); index_1++) {
        for (int index_2 = index_1 + 1; index_2 < C.size(); index_2++) {
            A* a1 = C[index_1];
            A* a2 = C[index_2];
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
    vector<A*> vArc_prive_C;
    if (!GNOestCouplage(C)) {
        cout << "C n'est pas un couplage." << endl;
        return false;
    }
    else {
        for (int index_1 = 0; index_1 < this->vGORArcs.size(); index_1++) {
            bool estDansC = false;
            for (int index_2 = 0; index_2 < C.size(); index_2++) {
                if (this->vGORArcs[index_1] == C[index_2]) {
                    estDansC = true;
                }
            }
            if (!estDansC) {
                vector<A*> C_prime = C;
                vArc_prive_C.push_back(this->vGORArcs[index_1]);
                C_prime.push_back(this->vGORArcs[index_1]);
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