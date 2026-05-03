#ifndef PGrapheNonOriente_H
#define PGrapheNonOriente_H


#include <vector>
#include "PSommet.h"
#include "PArc.h"
#include "PGrapheOriente.h"


// patron de classe PGrapheNonOriente
template <class S, class A>
class PGrapheNonOriente : public PGrapheOriente<S, A> {
public:
//METHODES
    // ajouter 2 fois l'arc (dans les 2 sens)
    void GORAjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);
    // modifier les 2 arcs 
    void GORModifierArc(unsigned int oldND, unsigned int oldNA, unsigned int newND, unsigned int newNA);
    // supprimer les 2 arcs (les 2 sens)
    void GORSupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);
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

#endif // !PGrapheNonOriente_H