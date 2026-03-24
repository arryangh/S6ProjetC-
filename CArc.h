#ifndef CArc_H
#define CArc_H

class CArc {
protected:
	unsigned int uiSommetDep;
	unsigned int uiSommetArr;

public:
	// const & dest
	CArc();
	CArc(unsigned int SommetDep, unsigned int SommetArr);
	~CArc();

	// méthodes 


	// accesseurs 
	unsigned int LireSommetDep();
	unsigned int LireSommetArr();
	void ModifierSommetDep(unsigned int uiNumero);
	void ModifierSommetArr(unsigned int uiNumero);
};

#endif // !CArc_H



