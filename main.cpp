#include <iostream>
#include "CArc.h"
#include "CSommet.h"
#include "CGrapheOriente.h"


using namespace std;

void afficherMot(string s) {
	cout << s << endl;
}


void test1CSommet() {
	// s1
	CSommet s1(1);
	s1.toString();


	// recopie de s1
	CSommet s1_v2(s1);
	s1_v2.toString();

	// s2
	CSommet s2(2);
	s2.toString();


}

void test2Arc() {
	
	// s1
	CSommet s1(1);
	cout << s1.toString() << endl;

	// s2
	CSommet s2(2);
	cout << s2.toString() << endl;


	CArc a1(&s1, &s2);
	cout << a1.toString() << endl;
	
	CArc a2(&s2, &s1);
	cout << a2.toString() << endl;

}

void test3Arc() {
	// s1
	CSommet s1(1);
	
	// s2
	CSommet s2(2);

	CArc a1(&s1, &s2);
	cout << a1.toString() << endl;

	CArc a2(&s2, &s1);
	cout << a2.toString() << endl;

	cout << s1.toString() << endl;
	cout << s2.toString() << endl;
}


void test4Arc() {
	afficherMot("----------1ere etape-----------");
	// s1
	CSommet* s1 = new CSommet(1);

	// s2
	CSommet* s2 = new CSommet(2);

	// s3
	CSommet* s3 = new CSommet(3);

	CArc* a1 = new CArc(s1, s2);
	cout << a1->toString() << endl;

	CArc* a2 = new CArc(s2, s1);
	cout << a2->toString() << endl;

	CArc* a3 = new CArc(s2, s3);
	cout << a3->toString() << endl;

	CArc* a4 = new CArc(s3, s2);
	cout << a4->toString() << endl;

	CArc* a5 = new CArc(s3, s1);
	cout << a5->toString() << endl;

	CArc* a6 = new CArc(s1, s3);
	cout << a6->toString() << endl;

	// affichage de tout les sommets
	cout << s1->toString() << endl;
	cout << s2->toString() << endl;
	cout << s3->toString() << endl;

	afficherMot("----------2eme etape-----------");

	//Suppression des Arcs
	delete a2;
	delete a4;

	// affichage de tout les sommets
	cout << s1->toString() << endl;
	cout << s2->toString() << endl;
	cout << s3->toString() << endl;

	afficherMot("----------3eme etape-----------");

	delete s3;

	// affichage de tout les sommets
	cout << s1->toString() << endl;
	cout << s2->toString() << endl;
	// cout << s3->toString() << endl; // ça affiche Sommet(3722304989) après le "delete s3;"

	 
}

void test5Graphe() {
	afficherMot("----------  creation du graphe vide -----------");
	CGrapheOriente<CSommet, CArc>* G1 = new CGrapheOriente<CSommet, CArc>();
	cout << G1->toString() << endl; // afficher graphe

	afficherMot("----------  creation des sommets -----------"); // avec numéro seulement
	G1->AjouterSommet(1);
	G1->AjouterSommet(2);
	G1->AjouterSommet(3);
	cout << G1->toString() << endl; // afficher graphe

	afficherMot("----------  creation des arcs -----------"); // avec numéros seulement
	// même schemin que le teste précédant (diapo disponible)
	G1->AjouterArc(1, 2); // a1
	G1->AjouterArc(2, 1); // a2
	G1->AjouterArc(2, 3); // a3
	G1->AjouterArc(3, 2); // a4
	G1->AjouterArc(3, 1); // a5
	G1->AjouterArc(1, 3); // a6
	cout << G1->toString() << endl; // afficher graphe


	afficherMot("----------  suppression sommets -----------"); // avec numéros seulement
	G1->SupprimerSommet(3);
	cout << G1->toString() << endl; // afficher graphe


	afficherMot("----------  suppression arcs -----------"); // avec numéros seulement
	G1->SupprimerArc(1, 2);
	cout << G1->toString() << endl; // afficher graphe


}

int main() {
	
	// afficherMot("Aryan");
	// test3Arc();
	// testArc2();
	// test4Arc();
	test5Graphe();

	return 0;
}


