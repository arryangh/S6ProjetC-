#include <iostream>
#include <string>

using namespace std;

class Mere {
private:
	string prenom;
	string nom;

public:
	virtual void afficher() {
		cout << "Je suis la mère" << endl;
	}
};

class Fille : private Mere {
private:
	int age = 18;

public:
	void afficher() {
		cout << "Je suis la fille" << endl;
	}

	int LireAge() {
		return age;
	}

};

/*
int main() {
	Mere mere1;
	Fille fille1;
	mere1.afficher();
	fille1.afficher();
	cout << fille1.LireAge() << endl;
	
}
*/
