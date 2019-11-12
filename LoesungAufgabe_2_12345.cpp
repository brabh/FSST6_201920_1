#include <iostream>
#include <fstream>
#include <string>

//
// Aufgaben 2.1, 2.2, 2.3, 2.4, 2.5
//

using std::cout;
using std::endl;
using std::cin;


int sum(int x, int y, int z) { // zu Aufgabe 2.2

	return x * y * z;
}


int myRead() {
	int a, b, c;

	a = 6;
	b = 7;
	c = 8;

	int d = a + b + c; // Aufgabe 2.1

	d = sum(a, b, c); // Aufgabe 2.2

	// Aufgabe 2.3
	if (0) {
		cout << "hello from Aufgabe 2.3, Please enter 3  integer:" << endl;
		cin >> a >> b >> c;
		cout << "a = " << a << " b = " << b << " c = " << c << endl;
	}

	// Aufgabe 2.4
	std::ofstream fo("MyInts.txt", std::ofstream::app); // ios::binary

	if (fo)
		for (int i = 0; i < 5; ++i)
			fo << a << ";" << b << ";" << c << endl;
	fo.close();

	// Aufgabe 2.5
	std::ifstream fi("MyInts.txt");
	char ch;

	if (!fi) cout << "Error finding that file" << endl;


	//works beautifully
	if (0)
		while (fi >> a >> ch >> b >> ch >> c)
			cout << "a = " << a << " b = " << b << " c = " << c << endl;


	// works beautifully but is only a line
	std::string line;
	if (0)
		while (std::getline(fi, line))
			cout << line << endl;

	fi.close();

	return 0;
}

int L2_12345_main() {

	myRead();

	return 0;
}


