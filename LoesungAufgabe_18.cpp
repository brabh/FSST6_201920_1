
/* 
** Aufgabe 18:
** Erstelle eine Klasse N mittels unique Pointer und übergib diesen Pointer an eine funktion.
** Schreibe in den Destruktor dieser Klasse std::cout << "Good bye"; und zeige damit wann dieser aufgerufen wird.
**
*/


#include <iostream>
#include <memory>   // for unique_pointer
#include <utility> // for std::move of unique pointer


class N {

public:

	~N() {
		std::cout << "Good bye" << std::endl;
	}
};


using up = std::unique_ptr<N>;


up f1(up p) {

	return std::move(p);
}


int main() {

	std::unique_ptr<N> p = std::make_unique<N>();

	p = f1(std::move(p));


	std::cout << "End of main" << std::endl;
	return 0;
}
