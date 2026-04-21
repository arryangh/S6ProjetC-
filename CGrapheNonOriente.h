#ifndef CGrapheNonOriente_H
#define CGrapheNonOriente_H


#include <vector>
#include "CSommet.h"
#include "CArc.h"
#include "CGrapheOriente.h"


// patron de classe CGrapheNonOriente
template <class S, class A>
class CGrapheNonOriente : public CGrapheOriente<S, A> {
public:
    // ajouter 2 fois l'arc (dans les 2 sens)
    void AjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
        CGrapheOriente<S, A>::AjouterArc(uiNumeroDepart, uiNumeroArrive);
        CGrapheOriente<S, A>::AjouterArc(uiNumeroArrive, uiNumeroDepart);
    }

    // modifier les 2 arcs 
    void ModifierArc(unsigned int oldND, unsigned int oldNA, unsigned int newND, unsigned int newNA) {
        CGrapheOriente<S, A>::ModifierArc(oldND, oldNA, newND, newNA);
        CGrapheOriente<S, A>::ModifierArc(oldNA, oldND, newNA, newND);
    }

    // supprimer les 2 arcs (les 2 sens)
    void SupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive) {
        CGrapheOriente<S, A>::SupprimerArc(uiNumeroDepart, uiNumeroArrive);
        CGrapheOriente<S, A>::SupprimerArc(uiNumeroArrive, uiNumeroDepart);
    }
};


#endif // !CGrapheNonOriente_H
