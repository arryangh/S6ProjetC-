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
    /*********************************************************************************
    * CException
    * ********************************************************************************
    * Entrée : uiValeur, unsigned int, identifiant du type d'erreur
    *          sMessage, string, le message qui décrit la cause de l'exception
    * Nécessite : Rien
    * Sortie : Rien
    * Entraîne : initialise les attributs uiEXCvaleur et sEXCmessage
    *********************************************************************************/
    CException(unsigned int uiValeur, const string& sMessage)
        : uiEXCvaleur(uiValeur), sEXCmessage(sMessage) {}

// ACCESSEURS
    /*********************************************************************************
    * EXClireValeur
    * ********************************************************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : unsigned int, l'identifiant de l'exception
    * Entraîne : retourne la valeur qui identifie le type d'erreur
    *********************************************************************************/
    unsigned int EXClireValeur() const {
        return uiEXCvaleur;
    }

    /*********************************************************************************
    * EXClireMessage
    * ********************************************************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : référence constante vers un string, le message d'erreur
    * Entraîne : retourne le message qui décrit la cause de l'exception
    *********************************************************************************/
    const string& EXClireMessage() const {
        return sEXCmessage;
    }
};

#endif // !CException_H
