/* 
** Aufgabe 19_1:
** Wie kann ich über alle diese drei values in drei unterschiedlichen Klassen
** sortieren und ausdrucken?
** Hier wird Vererbung als Lösung gewählt.
class kredit{
public:
double value;
};

class wertpapier {
public:
double value;
};

class foreignexchange {
public:
double value;
};
*/

#include <iostream>
#include <vector>
#include <algorithm>

class base {
public:
	virtual double getSaldo() = 0;
};

class kredit : public base {
public:
double value;
kredit(double parValue) : value{parValue} {}
double getSaldo() { return value; }
};

class wertpapier : public base {
public:
double value;
wertpapier(double parValue) : value{ parValue } {}
double getSaldo() { return value; }
};

class foreignexchange : public base {
public:
double value;
foreignexchange(double parValue) : value{ parValue } {}
double getSaldo() { return value; }
};


int main() {

	kredit k1{ 100.5 };
	kredit k2{ 50.5 };
	kredit k3{ 150.5 };

	wertpapier w1{ 200.25 };
	wertpapier w2{ 180.25 };
	wertpapier w3{ 220.25 };

	foreignexchange f1{ 50.75 };
	foreignexchange f2{ 75.75 };
	foreignexchange f3{ 125.75 };

	std::vector<base*> vb { &k1, & k2, & k3, & w1, &w2, &w3, &f1, &f2, &f3 };

	std::sort(vb.begin(), vb.end(), [](auto& p1, auto& p2) {

		//std::cout << typeid(p1).name() << std::endl; // it is a ref to base*

		return p1->getSaldo() < p2->getSaldo();

		});

	for (const auto& e : vb)
		std::cout << e->getSaldo()  << std::endl; // getSaldo()

	return 0;
}
