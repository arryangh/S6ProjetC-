#ifndef CGrapheNonOriente_H
#define CGrapheNonOriente_H

#include <vector>
#include "CSommet.h"
#include "CArc.h"
#include "CGrapheOriente.h"


// patron de classe CGrapheOriente

class CGrapheNonOriente: public CGrapheOriente<CSommet, CArc>{
protected:



public:
	// const & dest


	// méthodes 
	void AjouterArc(unsigned int uiNumeroDepart, unsigned int uiNumeroArrive);




	// accesseurs 


};

#endif // !CGrapheNonOriente_H
