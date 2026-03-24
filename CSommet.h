#ifndef CSommet_H
#define CSommet_H

class CSommet {
protected:
	unsigned int uiSommetDep;
	unsigned int uiSommetArr;

public:
	// const & dest
	CSommet();
	CSommet(unsigned int SommetDep, unsigned int SommetArr);
	CSommet(unsigned int numero);

	~CSommet();

	// méthodes 


	// accesseurs 
	unsigned int LireNumero();
};

#endif // !CSommet_H



