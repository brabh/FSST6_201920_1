/*
** Aufgabe 20
** Übergeben Sie ein Lambda an eine funktion
** indem sie das Lambda definieren und per name übergeben
** indem sie  das Lambda in den funktionsaufruf schreiben
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

