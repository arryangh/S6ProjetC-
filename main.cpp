#include <iostream>
#include "CArc.h"
#include "CSommet.h"


using namespace std;

void afficherMot(string s) {
	cout << s << endl;
}


void testCSommet() {
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

void testArc() {
	
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

void testArc2() {
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


void testArc3() {
	// s1
	CSommet s1(1);

	// s2
	CSommet s2(2);

	// s3
	CSommet s3(3);

	CArc a1(&s1, &s2);
	cout << a1.toString() << endl;

	CArc a2(&s2, &s1);
	cout << a2.toString() << endl;

	CArc a3(&s2, &s3);
	cout << a3.toString() << endl;

	CArc a4(&s3, &s2);
	cout << a4.toString() << endl;

	CArc a5(&s3, &s1);
	cout << a5.toString() << endl;

	CArc a6(&s1, &s3);
	cout << a6.toString() << endl;

	// affichage de tout les sommets
	cout << s1.toString() << endl;
	cout << s2.toString() << endl;
	cout << s3.toString() << endl;

	 
}

int main() {
	
	//afficherMot("Aryan");
	//testArc();
	// testArc2();
	afficherMot("Aryan");
	testArc2();

	return 0;
}

// آناعل
// آرین
// تیبو
// لویی
// کلمان
