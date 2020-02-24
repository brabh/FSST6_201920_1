/* 
** Aufgabe 19:
** Wie kann ich über alle diese values sortieren und ausdrucken?
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
#include <functional>

int  f1(int x, std::function<int(int)> fct) {
	
	return fct(x);
}

int main() {
	int loc = 100, loc2 = 200;

	auto fx = [&loc, &loc2](int x) {return 7 + x + loc; };

	std::cout << f1(loc, fx) << std::endl;
	std::cout << f1(loc, [=](int x) {return 7 + x + loc; }) << std::endl;

	auto f = std::bind(f1, std::placeholders::_1, fx);
	std::cout << f(25) << std::endl;

	return 0;
}
