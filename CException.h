#ifndef CException_H
#define CException_H

/*********************************************************************************
* CLASSE : CException
* ********************************************************************************
* ROLE: Permet de créer des objets qui sont remontés lors de la levée d'exception 
*       dans notre programme.
*       Contient un identifiant sur le type d'erreur et un message qui décrit la 
*       cause.
* ********************************************************************************
* VERSION: 1.0
* AUTEUR: Anaëlle BENOIST & Aryan GHALEHNOEE
* ********************************************************************************
* INCLUSIONS EXTERNES :
*/
#include <string>
using namespace std;

//Définition des valeurs initiale des exceptions
#define EXC_SOMMET_DEJA_EXISTANT     1  
#define EXC_SOMMET_INTROUVABLE       2  
#define EXC_ARC_INTROUVABLE          3  
#define EXC_ARC_DEJA_EXISTANT        4  
#define EXC_FICHIER_INTROUVABLE      5  
#define EXC_DONNEES_INCOHERENTES     6  

class CException {
// ATTRIBUTS
private:
    unsigned int uiEXCvaleur;
    string       sEXCmessage;

// CONSTRUCTEURS
public:
    CException(unsigned int uiValeur, const string& sMessage)
        : uiEXCvaleur(uiValeur), sEXCmessage(sMessage) {}

// ACCESSEURS
    unsigned int EXClireValeur() const {
        return uiEXCvaleur;
    }

    const string& EXClireMessage() const {
        return sEXCmessage;
    }
};

#endif // !CException_H
