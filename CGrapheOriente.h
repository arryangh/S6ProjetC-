#ifndef CGrapheOriente_H
#define CGrapheOriente_H

#include <vector>
#include "CSommet.h"
#include "CArc.h"


// patron de classe CGrapheOriente
template <class S, class A>
class CGrapheOriente {
protected:
	vector<S*>vSommets; // le vecteur contenant les pointeurs de type générique S (sommet)
	vector<A*>vArcs; // le vecteur contenant les pointeurs de type générique A (Arc)



public:
	// const & dest
	CGrapheOriente();
	~CGrapheOriente();



	// méthodes 
	void AjouterSommet(unsigned int uiNumero);
	void AjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);
	void SupprimerSommet(unsigned int uiNumero);
	void SupprimerArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);
	void ModifierSommet(unsigned int uiNumero); // modifier par quoi? comment modifier un S*?

	void ModifierArc(unsigned int oldND, unsigned int OldNA, 
		unsigned int newND, unsigned int newNA);

	void AfficherGraphe(); // liée à la classe CAffichage
	void InverserGraphe();


	// accesseurs 
	unsigned int LireNumero();
	


	//--------------------------------------------------------------------------------
	// méthodes utile en interne (mettre en private?)
private:
	S* TrouverSommet(unsigned int uiNumero);
	A* TrouverArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);

};

#endif // !CGrapheOriente_H
