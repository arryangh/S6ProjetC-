#include <iostream>
#include "PArc.h"
#include "PSommet.h"
#include "PGrapheOriente.h"
#include "PGrapheNonOriente.h"
#include "PGestionnaireFichier.h"
#include <filesystem>


using namespace std;

// forward declarations mutuelles
class MonSommet;
class MonArc;

// on définit des classes concrètes vides qui héritent des patrons
class MonArc : public PArc<MonSommet> {
public:
	using PArc<MonSommet>::PArc; // hérite du constructeur
};

class MonSommet : public PSommet<MonArc> {
public:
	using PSommet<MonArc>::PSommet; // hérite du constructeur
};


void afficherMot(string s) {
	cout << s << endl;
}


void test1PSommet() {
	// s1
	MonSommet s1(1);
	s1.SOMtoString();
	cout << s1.SOMtoString() << endl;

	// recopie de s1
	MonSommet s1_v2(s1);
	s1_v2.SOMtoString();
	cout << s1_v2.SOMtoString() << endl;

	// s2
	MonSommet s2(2);
	s2.SOMtoString();
	cout << s2.SOMtoString() << endl;
}

void test2Arc() {
	
	// s1
	MonSommet s1(1);
	// s2
	MonSommet s2(2);

	MonArc a1(&s1, &s2);
	MonArc a2(&s2, &s1);
	

	cout << s1.SOMtoString() << endl;
	cout << s2.SOMtoString() << endl;
	cout << a1.ARCtoString() << endl;
	cout << a2.ARCtoString() << endl;

}

void test3Arc() {
	// s1
	MonSommet s1(1);
	
	// s2
	MonSommet s2(2);

	MonArc a1(&s1, &s2);
	cout << a1.ARCtoString() << endl;

	MonArc a2(&s2, &s1);
	cout << a2.ARCtoString() << endl;

	cout << s1.SOMtoString() << endl;
	cout << s2.SOMtoString() << endl;
}


void test4Arc() {
	afficherMot("----------1ere etape-----------");
	// s1
	MonSommet* s1 = new MonSommet(1);

	// s2
	MonSommet* s2 = new MonSommet(2);

	// s3
	MonSommet* s3 = new MonSommet(3);

	MonArc* a1 = new MonArc(s1, s2);
	cout << a1->ARCtoString() << endl;

	MonArc* a2 = new MonArc(s2, s1);
	cout << a2->ARCtoString() << endl;

	MonArc* a3 = new MonArc(s2, s3);
	cout << a3->ARCtoString() << endl;

	MonArc* a4 = new MonArc(s3, s2);
	cout << a4->ARCtoString() << endl;

	MonArc* a5 = new MonArc(s3, s1);
	cout << a5->ARCtoString() << endl;

	MonArc* a6 = new MonArc(s1, s3);
	cout << a6->ARCtoString() << endl;

	// affichage de tout les sommets
	cout << s1->SOMtoString() << endl;
	cout << s2->SOMtoString() << endl;
	cout << s3->SOMtoString() << endl;

	afficherMot("----------2eme etape-----------");

	//Suppression des Arcs
	delete a2;
	delete a4;

	// affichage de tout les sommets
	cout << s1->SOMtoString() << endl;
	cout << s2->SOMtoString() << endl;
	cout << s3->SOMtoString() << endl;

	afficherMot("----------3eme etape-----------");

	delete s3;

	// affichage de tout les sommets
	cout << s1->SOMtoString() << endl;
	cout << s2->SOMtoString() << endl;
	// cout << s3->toString() << endl; // ça affiche Sommet(3722304989) après le "delete s3;"

	 
}

void test5Graphe() {
	afficherMot("----------  creation du graphe vide -----------");
	PGrapheOriente<MonSommet, MonArc>* G1 = new PGrapheOriente<MonSommet, MonArc>();
	cout << G1->GORtoString() << endl; // afficher graphe

	afficherMot("----------  creation des sommets -----------"); // avec numéro seulement
	G1->GORAjouterSommet(1);
	G1->GORAjouterSommet(2);
	G1->GORAjouterSommet(3);
	cout << G1->GORtoString() << endl; // afficher graphe

	afficherMot("----------  creation des arcs -----------"); // avec numéros seulement
	// même schemin que le teste précédant (diapo disponible)
	G1->GORAjouterArc(1, 2); // a1
	G1->GORAjouterArc(2, 1); // a2
	G1->GORAjouterArc(2, 3); // a3
	G1->GORAjouterArc(3, 2); // a4
	G1->GORAjouterArc(3, 1); // a5
	G1->GORAjouterArc(1, 3); // a6
	cout << G1->GORtoString() << endl; // afficher graphe


	afficherMot("----------  suppression sommets -----------"); // avec numéros seulement
	G1->GORSupprimerSommet(3);
	cout << G1->GORtoString() << endl; // afficher graphe


	afficherMot("----------  suppression arcs -----------"); // avec numéros seulement
	G1->GORSupprimerArc(1, 2);
	cout << G1->GORtoString() << endl; // afficher graphe

	
	afficherMot("----------  modification d'arcs -----------"); // avec numéros seulement
	G1->GORModifierArc(2, 1, 1, 2); // Arc(2, 1) => Arc(1, 2)
	cout << G1->GORtoString() << endl; // afficher graphe

}

// inverser un graphe
void test6Graphe() {
	afficherMot("----------  creation du graphe vide -----------");
	PGrapheOriente<MonSommet, MonArc>* G1 = new PGrapheOriente<MonSommet, MonArc>();
	cout << G1->GORtoString() << endl; // afficher graphe

	afficherMot("----------  creation des sommets -----------"); // avec numéro seulement
	G1->GORAjouterSommet(1);
	G1->GORAjouterSommet(2);
	G1->GORAjouterSommet(3);
	cout << G1->GORtoString() << endl; // afficher graphe

	afficherMot("----------  creation des arcs -----------"); // avec numéros seulement
	// même schemin que le teste précédant (diapo disponible)
	G1->GORAjouterArc(1, 2); // a1
	G1->GORAjouterArc(2, 3); // a3
	G1->GORAjouterArc(3, 1); // a5
	G1->GORAjouterArc(1, 3); // a6
	cout << G1->GORtoString() << endl; // afficher graphe

	afficherMot("----------  inverser le graphe -----------"); 
	PGrapheOriente<MonSommet, MonArc>* G2 = G1->GORInverserGraphe();
	cout << G2->GORtoString() << endl; // afficher graphe
}


void test7Graphe() {
	afficherMot("----------  creation du graphe non oriente vide -----------");
	PGrapheNonOriente<MonSommet, MonArc>* GN1 = new PGrapheNonOriente<MonSommet, MonArc>();
	cout << GN1->GORtoString() << endl; // afficher graphe

	afficherMot("----------  creation des sommets -----------"); // avec numéro seulement
	GN1->GORAjouterSommet(1);
	GN1->GORAjouterSommet(2);
	GN1->GORAjouterSommet(3);
	cout << GN1->GORtoString() << endl; // afficher graphe

	afficherMot("----------  creation des arrets (double arcs) -----------"); // avec numéros seulement
	// même schemin que le teste précédant (diapo disponible)
	GN1->GORAjouterArc(1, 2); // arret1
	GN1->GORAjouterArc(2, 3); // arret2
	GN1->GORAjouterArc(3, 1); // arret3
	cout << GN1->GORtoString() << endl; // afficher graphe

	/*
	afficherMot("----------  inverser le graphe -----------");
	CGrapheOriente<MonSommet, MonArc>* G2 = G1->InverserGraphe();
	cout << G2->toString() << endl; // afficher graphe
	*/

}



// ATTENTINION: Le programme doit être exécuté depuis le répertoire racine 
// du projet afin que les chemins relatifs fonctionnent correctement.
/*
ProjetCppAnaelle/
│
├── data/
│   └── f1.txt <-- les fichier text se trouvent ici
│
├── MonArc.cpp
├── MonArc.h
├── MonSommet.cpp
├── MonSommet.h
├── CGrapheOriente.h
├── main.cpp
└── ...
*/
void test8ChargementFichier() {
	// #include <filesystem>
	// #include "CGestionnaireFichier.h"
	// cout << std::filesystem::current_path() << endl;

	PGestionnaireFichier<MonSommet, MonArc>* GF = new PGestionnaireFichier<MonSommet, MonArc>();
	GF->GSFAfficherContenuFichier("data/f1.txt");
}


void test9InterpreteurFichier() {
	// création du gestionnaire de fichier 
	PGestionnaireFichier<MonSommet, MonArc>* GF = new PGestionnaireFichier<MonSommet, MonArc>();

	// utilisation de la méthode "InterpreterContenuFichier" du gestionnaire de fichier pour génerer le graphe
	PGrapheOriente<MonSommet, MonArc>* G1 = GF->GSFGenererGrapheDepuisFichier("data/f1.txt");
	

	// afficher le graphe géneré
	cout << "\n" << endl;

	cout << G1->GORtoString() << endl; // afficher graphe
}

void NosTestes() {
	afficherMot("==================================  TEST 1 ===================================");
	test1PSommet();
	
	afficherMot("==================================  TEST 2 ===================================");
	test2Arc();
	
	afficherMot("==================================  TEST 3 ===================================");
	test3Arc();
	
	afficherMot("==================================  TEST 4 ===================================");
	test4Arc();
	
	afficherMot("==================================  TEST 5 ===================================");
	test5Graphe();
	
	afficherMot("==================================  TEST 6 ===================================");
	test6Graphe();
	
	afficherMot("==================================  TEST 7 ===================================");
	test7Graphe();
	
	afficherMot("==================================  TEST 8 ===================================");
	test8ChargementFichier();
	
	afficherMot("==================================  TEST 9 ===================================");
	test9InterpreteurFichier();
	
}

void fonctionPrincipaleSujet() {
	afficherMot("==================================  TEST DEMANDE DANS LE SUJET ===================================");
	// 1) Pour un nom de fichier passé en paramètre, lire le fichier et créer le graphe associé
	PGestionnaireFichier<MonSommet, MonArc>* GF = new PGestionnaireFichier<MonSommet, MonArc>();
	PGrapheOriente<MonSommet, MonArc>* G1 = GF->GSFGenererGrapheDepuisFichier("data/f1.txt");

	// 2) Afficher le graphe à l’écran
	afficherMot("\nle graphe du fichier:");
	cout << G1->GORtoString() << endl; 

	// 3) Inverser tous les arcs du graphe pour obtenir un nouveau graphe
	PGrapheOriente<MonSommet, MonArc>* G2 = G1->GORInverserGraphe();

	// 4) Afficher ce nouveau graphe à l’écran. 
	afficherMot("\nl'inverse: ");
	cout << G2->GORtoString() << endl;
}

int main() {
	//NosTestes();
	fonctionPrincipaleSujet();

	return 0;
}


