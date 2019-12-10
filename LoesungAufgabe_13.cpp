#include <iostream>

namespace NamespaceLogic {

	bool XOR(bool a, bool b) {

		if (a == false && b == true)
			return 1;
		else if (a == true && b == false)
			return 1;
		else return 0;
	}

} // Ende Namespace NamespaceLogic


class Logic {
public:
static int XOR (int a, int b) {

		if (a == 0 && b == 1)
			return 1;
		else if (a == 1 && b == 0)
			return 1;
		else return 0;
	}

}; // Ende class Logic



int main() {

	std::cout << NamespaceLogic::XOR(1, 1) << std::endl;

	std::cout << Logic::XOR(0, 1) << std::endl;  // static class member function will be accessed by :: and not by . !

	return 0;
}

