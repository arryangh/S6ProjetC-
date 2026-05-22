#include <iostream>
#include <vector>
#include "PArc.h"
#include "PSommet.h"
#include "PGrapheOriente.h"
#include "PGrapheNonOriente.h"
#include "PGestionnaireFichier.h"
#include "CException.h"
#include <filesystem>


using namespace std;

class MonSommet;
class MonArc;

class MonArc : public PArc<MonSommet> {
public:
	using PArc<MonSommet>::PArc; 
};

class MonSommet : public PSommet<MonArc> {
public:
	using PSommet<MonArc>::PSommet; 
};

void afficherText(string s) {
	cout << s << endl;
}


void test1PSommet() {
	MonSommet s1(1);
	s1.SOMAfficher();

	MonSommet s1_v2(s1);
	s1_v2.SOMAfficher();

	MonSommet s2(2);
	s2.SOMAfficher();
}

void test2Arc() {
	MonSommet s1(1);
	MonSommet s2(2);

	MonArc a1(&s1, &s2);
	MonArc a2(&s2, &s1);

	s1.SOMAfficher();
	s2.SOMAfficher();
	a1.ARCAfficher();
	a2.ARCAfficher();
}

void test3Arc() {

	MonSommet s1(1);
	MonSommet s2(2);

	MonArc a1(&s1, &s2);
	a1.ARCAfficher();

	MonArc a2(&s2, &s1);
	a2.ARCAfficher();

	s1.SOMAfficher();
	s2.SOMAfficher();
}

void test4Arc() {
	afficherText("----------1ere etape-----------");

	MonSommet* s1 = new MonSommet(1);
	MonSommet* s2 = new MonSommet(2);
	MonSommet* s3 = new MonSommet(3);

	MonArc* a1 = new MonArc(s1, s2);
	a1->ARCAfficher();

	MonArc* a2 = new MonArc(s2, s1);
	a2->ARCAfficher();

	MonArc* a3 = new MonArc(s2, s3);
	a3->ARCAfficher();

	MonArc* a4 = new MonArc(s3, s2);
	a4->ARCAfficher();

	MonArc* a5 = new MonArc(s3, s1);
	a5->ARCAfficher();

	MonArc* a6 = new MonArc(s1, s3);
	a6->ARCAfficher();

	s1->SOMAfficher();
	s2->SOMAfficher();
	s3->SOMAfficher();
	
	afficherText("----------2eme etape-----------");

	delete a2;
	delete a4;

	s1->SOMAfficher();
	s2->SOMAfficher();
	s3->SOMAfficher();

	afficherText("----------3eme etape-----------");

	delete s3;

	s1->SOMAfficher();
	s2->SOMAfficher();
	//s3->SOMAfficher(); // ça fait planter le programme car il n'existe plus après le "delete s3;"	 
}

void test5Graphe() {
	afficherText("----------  creation du graphe vide -----------");
	PGrapheOriente<MonSommet, MonArc>* G1 = new PGrapheOriente<MonSommet, MonArc>();
	G1->GORAfficher();

	afficherText("----------  creation des sommets -----------"); 
	G1->GORAjouterSommet(1);
	G1->GORAjouterSommet(2);
	G1->GORAjouterSommet(3);
	G1->GORAfficher();

	afficherText("----------  creation des arcs -----------"); 
	G1->GORAjouterArc(1, 2); 
	G1->GORAjouterArc(2, 1); 
	G1->GORAjouterArc(2, 3); 
	G1->GORAjouterArc(3, 2); 
	G1->GORAjouterArc(3, 1); 
	G1->GORAjouterArc(1, 3); 
	G1->GORAfficher();


	afficherText("----------  suppression sommets -----------"); 
	G1->GORSupprimerSommet(3);
	G1->GORAfficher();


	afficherText("----------  suppression arcs -----------"); 
	G1->GORSupprimerArc(1, 2);
	G1->GORAfficher();

	
	afficherText("----------  modification d'arcs -----------"); 
	G1->GORModifierArc(2, 1, 1, 2); 
	G1->GORAfficher();

}

void test6Graphe() {
	afficherText("----------  creation du graphe vide -----------");
	PGrapheOriente<MonSommet, MonArc>* G1 = new PGrapheOriente<MonSommet, MonArc>();
	G1->GORAfficher();

	afficherText("----------  creation des sommets -----------"); 
	G1->GORAjouterSommet(1);
	G1->GORAjouterSommet(2);
	G1->GORAjouterSommet(3);
	G1->GORAfficher();

	afficherText("----------  creation des arcs -----------"); 
	G1->GORAjouterArc(1, 2); 
	G1->GORAjouterArc(2, 3); 
	G1->GORAjouterArc(3, 1); 
	G1->GORAjouterArc(1, 3); 
	G1->GORAfficher();

	afficherText("----------  inverser le graphe -----------"); 
	PGrapheOriente<MonSommet, MonArc>* G2 = G1->GORInverserGraphe();
	G2->GORAfficher();
}

void test7Graphe() {
	afficherText("----------  creation du graphe non oriente vide -----------");
	PGrapheNonOriente<MonSommet, MonArc>* GN1 = new PGrapheNonOriente<MonSommet, MonArc>();
	GN1->GORAfficher();

	afficherText("----------  creation des sommets -----------"); 
	GN1->GORAjouterSommet(1);
	GN1->GORAjouterSommet(2);
	GN1->GORAjouterSommet(3);
	GN1->GORAfficher();

	afficherText("----------  creation des arrets (double arcs) -----------"); 
	GN1->GORAjouterArc(1, 2);
	GN1->GORAjouterArc(2, 3);
	GN1->GORAjouterArc(3, 1);
	GN1->GORAfficher();
}

void test8ChargementFichier() {
	PGestionnaireFichier<MonSommet, MonArc>* GF = new PGestionnaireFichier<MonSommet, MonArc>();
	GF->GSFAfficherContenuFichier("data/f1.txt");
}

void test9InterpreteurFichier() {
	PGestionnaireFichier<MonSommet, MonArc>* GF = new PGestionnaireFichier<MonSommet, MonArc>();
	PGrapheOriente<MonSommet, MonArc>* G1 = GF->GSFGenererGrapheDepuisFichier("data/f1.txt");
	
	cout << "\n" << endl;
	G1->GORAfficher();
}

void testClasses() {
	afficherText("==================================  TEST 1 ===================================");
	test1PSommet();
	
	afficherText("==================================  TEST 2 ===================================");
	test2Arc();
	
	afficherText("==================================  TEST 3 ===================================");
	test3Arc();
	
	afficherText("==================================  TEST 4 ===================================");
	test4Arc();
	
	afficherText("==================================  TEST 5 ===================================");
	test5Graphe();
	
	afficherText("==================================  TEST 6 ===================================");
	test6Graphe();
	
	afficherText("==================================  TEST 7 ===================================");
	test7Graphe();
	
	afficherText("==================================  TEST 8 ===================================");
	test8ChargementFichier();
	
	afficherText("==================================  TEST 9 ===================================");
	test9InterpreteurFichier();
}

void testEXC1_SommetDejaExistant() {
	afficherText("--- EXC 1 : Sommet déjà existant ---");
	try {
		PGrapheOriente<MonSommet, MonArc>* G = new PGrapheOriente<MonSommet, MonArc>();
		G->GORAjouterSommet(1);
		G->GORAjouterSommet(1);
		afficherText("[ECHEC] Aucune exception levee !");
	}
	catch (CException& e) {
		cout << "[OK] EXC " << e.EXClireValeur() << " : " << e.EXClireMessage() << endl;
	}
}

void testEXC2_SommetIntrouvable() {
	afficherText("--- EXC 2 : Sommet introuvable ---");
	try {
		PGrapheOriente<MonSommet, MonArc>* G = new PGrapheOriente<MonSommet, MonArc>();
		G->GORAjouterSommet(1);
		G->GORAjouterArc(1, 99);
		afficherText("[ECHEC] Aucune exception levee !");
	}
	catch (CException& e) {
		cout << "[OK] EXC " << e.EXClireValeur() << " : " << e.EXClireMessage() << endl;
	}
}

void testEXC3_ArcIntrouvable() {
	afficherText("--- EXC 3 : Arc introuvable ---");
	try {
		PGrapheOriente<MonSommet, MonArc>* G = new PGrapheOriente<MonSommet, MonArc>();
		G->GORAjouterSommet(1);
		G->GORAjouterSommet(2);
		G->GORSupprimerArc(1, 2);
		afficherText("[ECHEC] Aucune exception levee !");
	}
	catch (CException& e) {
		cout << "[OK] EXC " << e.EXClireValeur() << " : " << e.EXClireMessage() << endl;
	}
}

void testEXC4_ArcDejaExistant() {
	afficherText("--- EXC 4 : Arc cible déjà existant (GORModifierArc) ---");
	try {
		PGrapheOriente<MonSommet, MonArc>* G = new PGrapheOriente<MonSommet, MonArc>();
		G->GORAjouterSommet(1);
		G->GORAjouterSommet(2);
		G->GORAjouterSommet(3);
		G->GORAjouterArc(1, 2);
		G->GORAjouterArc(2, 3);
		G->GORModifierArc(1, 2, 2, 3); 
		afficherText("[ECHEC] Aucune exception levee !");
	}
	catch (CException& e) {
		cout << "[OK] EXC " << e.EXClireValeur() << " : " << e.EXClireMessage() << endl;
	}
}

void testEXC5_FichierIntrouvable() {
	afficherText("--- EXC 5 : Fichier introuvable ---");
	try {
		PGestionnaireFichier<MonSommet, MonArc>* GF = new PGestionnaireFichier<MonSommet, MonArc>();
		GF->GSFGenererGrapheDepuisFichier("data/fichier_inexistant.txt"); 
		afficherText("[ECHEC] Aucune exception levee !");
	}
	catch (CException& e) {
		cout << "[OK] EXC " << e.EXClireValeur() << " : " << e.EXClireMessage() << endl;
	}
}

void testEXC6_DonneesIncoherentes() {
	afficherText("--- EXC 6 : Données incohérentes (fichier mal formé) ---");
	try {
		PGestionnaireFichier<MonSommet, MonArc>* GF = new PGestionnaireFichier<MonSommet, MonArc>();
		GF->GSFGenererGrapheDepuisFichier("data/f_incoherent.txt");
		afficherText("[ECHEC] Aucune exception levee !");
	}
	catch (CException& e) {
		cout << "[OK] EXC " << e.EXClireValeur() << " : " << e.EXClireMessage() << endl;
	}
}

void testExceptions() {
	afficherText("==================================  TESTS EXCEPTIONS ===================================");
	testEXC1_SommetDejaExistant();
	testEXC2_SommetIntrouvable();
	testEXC3_ArcIntrouvable();
	testEXC4_ArcDejaExistant();
	testEXC5_FichierIntrouvable();
	testEXC6_DonneesIncoherentes();
}

void testGNOCouplage() {
	afficherText("==================================  TEST COUPLAGE ===================================");

	PGrapheNonOriente<MonSommet, MonArc>* GN = new PGrapheNonOriente<MonSommet, MonArc>();

	GN->GORAjouterSommet(1);
	GN->GORAjouterSommet(2);
	GN->GORAjouterSommet(3);
	GN->GORAjouterSommet(4);
	GN->GORAjouterSommet(5);
	GN->GORAjouterSommet(6);
	GN->GORAjouterSommet(7);
	GN->GORAjouterSommet(8);

	GN->GORAjouterArc(1, 2);
	GN->GORAjouterArc(1, 3);
	GN->GORAjouterArc(1, 4);
	GN->GORAjouterArc(2, 5);
	GN->GORAjouterArc(3, 6);
	GN->GORAjouterArc(4, 7);
	GN->GORAjouterArc(5, 6);
	GN->GORAjouterArc(5, 8);
	GN->GORAjouterArc(6, 8);
	GN->GORAjouterArc(7, 8);

	GN->GORAfficher();

	afficherText("================================== TEST COUPLAGE MAXIMAL 1 ==================================");
	vector<MonArc*> C1;
	C1.push_back(GN->GORgetArcs()[0]);
	C1.push_back(GN->GORgetArcs()[8]);
	C1.push_back(GN->GORgetArcs()[10]);
	C1.push_back(GN->GORgetArcs()[14]);
	bool resultat1 = GN->GNOTestCouplage(C1);
	cout << resultat1 << endl;
}

void fonctionPrincipaleSujet(string sPath) {
	afficherText("==================================  TEST DEMANDE DANS LE SUJET ===================================");
	try {
		PGestionnaireFichier<MonSommet, MonArc>* GF = new PGestionnaireFichier<MonSommet, MonArc>();
		PGrapheOriente<MonSommet, MonArc>* G1 = GF->GSFGenererGrapheDepuisFichier(sPath);

		afficherText("\nle graphe du fichier:");
		G1->GORAfficher();

		PGrapheOriente<MonSommet, MonArc>* G2 = G1->GORInverserGraphe();

		afficherText("\nl'inverse: ");
		G2->GORAfficher();
	}
	catch (CException& e) {
		cerr << "[EXC " << e.EXClireValeur() << "] " << e.EXClireMessage() << endl;
	}
}

int main() {
	string sPath;

	cout << "Entrez le chemin du fichier : ";
	getline(cin, sPath);

	fonctionPrincipaleSujet(sPath);

	//testClasses();
	//testExceptions();
	testGNOCouplage();
	
	cin.get();
	return 0;
}