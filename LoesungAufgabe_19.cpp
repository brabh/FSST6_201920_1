/* 
** Aufgabe 19:
** Wie kann ich über alle diese drei KLassen c1, c2, c3 sortieren und den saldo ausdrucken?
** jedoch ohne Vererbung (bzw auch ohne Interface wie in Java)
*/

#include <iostream>
#include <vector>
#include <utility>
#include <variant>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::variant;
using std::visit;

//
// a wonderful sample, 
// sorts a vector of variants 
// und druckt den sortierten vector aus
// working beautifully, without inheritance (and without interface in Java)
//

class c1 {
	double saldo = 1.0;
public:
	double 	getSaldo() { return saldo; }
};


class c2 {
	double saldo = 2.0;
public:
	double 	getSaldo() { return saldo; }
};


class c3 {
	double saldo = 3.0;
public:
	double 	getSaldo() { return saldo; }
};


int main() {

  std::variant<c1, c2, c3> z, u, p, w;
  
	c1 thec1;
	c2 thec2;
	c3 thec3;

	z = thec1;
	u = thec2;
	p = thec3;
	w = thec1;

	std::vector<std::variant<c1, c2, c3>> vv{ z, u, p, w };
	vv.push_back(z);

	std::cout << "The unsorted array\n";

	for (auto& e : vv)
		std::visit([](auto&& arg) {
		using T = std::decay_t<decltype(arg)>;

		T t = static_cast<T> (arg);
		std::cout << t.getSaldo() << std::endl; // assumes all classes have this function

		if (0) // die Klasse eruieren
			if constexpr (std::is_same_v<T, c1 >)
				std::cout << "it is a c1 " << '\n';
			else if constexpr (std::is_same_v<T, c2 >)
				std::cout << "it is a c2 " << '\n';
			else if constexpr (std::is_same_v<T, c3 >)
				std::cout << "it is a c3 " << '\n';
			else std::cout << "datatype could not be compeared successfully \n";
			}, e);

	std::sort(vv.begin(), vv.end(), [](auto& p1, auto& p2) -> bool { // compiles &&, &,

		double p1Saldo =
			std::visit([](auto&& arg) -> double {
			using T = std::decay_t<decltype(arg)>;

			T t = static_cast<T> (arg);
			return t.getSaldo();

			if (0) // this version could call even different function names in different classes
				if constexpr (std::is_same_v<T, c1 >) {
					c1 cc1 = static_cast<c1> (arg);
					std::cout << cc1.getSaldo() << std::endl;

					std::cout << "p1 is a c1 " << '\n';
					return cc1.getSaldo();
				}
				else if constexpr (std::is_same_v<T, c2 >) {
					c2 cc2 = static_cast<c2> (arg);
					std::cout << cc2.getSaldo() << std::endl;

					std::cout << "p1 is a c2 " << '\n';
					return cc2.getSaldo();
				}
				else if constexpr (std::is_same_v<T, c3 >) {
					c3 cc3 = static_cast<c3> (arg);
					std::cout << cc3.getSaldo() << std::endl;

					std::cout << "p1 is a c3 " << '\n';
					return cc3.getSaldo();
				}
				else return -1.0; // std::cout << "datatype could not be compeared successfully \n";
				}, p1);


		double p2Saldo =
			std::visit([](auto&& arg) -> double {
			using T = std::decay_t<decltype(arg)>;

			T t = static_cast<T> (arg);
			return t.getSaldo(); 

			if(0)
				if constexpr (std::is_same_v<T, c1 >) {
					c1 cc1 = static_cast<c1> (arg);
					std::cout << cc1.getSaldo() << std::endl;

					std::cout << "p2 is a c1 " << '\n';
					return cc1.getSaldo();
				}
				else if constexpr (std::is_same_v<T, c2 >) {
					c2 cc2 = static_cast<c2> (arg);
					std::cout << cc2.getSaldo() << std::endl;

					std::cout << "p2 is a c2 " << '\n';
					return cc2.getSaldo();
				}
				else if constexpr (std::is_same_v<T, c3 >) {
					c3 cc3 = static_cast<c3> (arg);
					std::cout << cc3.getSaldo() << std::endl;

					std::cout << "p2 is a c3 " << '\n';
					return cc3.getSaldo();
				}
				else return -1.0; // std::cout << "datatype could not be compeared successfully \n";
				}, p2);

		return p1Saldo > p2Saldo; // > sorts descending
		});


	std::cout << "And now the descending sorted array\n";

	for (auto& e : vv)
		std::visit([](auto&& arg) {
			using T = std::decay_t<decltype(arg)>;

			T t = static_cast<T> (arg);
			std::cout << t.getSaldo() << std::endl;
			}, e);


	return 0;
}
