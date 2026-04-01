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

int main() {
	
	//afficherMot("Aryan");
	//testArc();
	afficherMot("Anaëlle");
	testArc2();

	return 0;
}

// آناعل
// آرین
// تیبو
// لویی
// کلمان
