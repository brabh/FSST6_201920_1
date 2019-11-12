
//#pragma warning(disable:4996) no need

#include <iostream>
#include <fstream>
#include <string>

//
// Aufgabe 2.6
//

using std::cout;
using std::endl;
using std::cin;

// struct in C++ is exactly a class with default access public
class s {	
public:
	int i1;
	int i2;
	int i3;
};
//typedef struct s ss; // no need, is provided in C++ for classes by default

int multStructS(s d){

	return d.i1 * d.i2 * d.i3;
}

int L2_6main() {

	printf("Hello from Aufgabe 2.6.\n");

	s myS1;

	myS1.i1 = 5;
	myS1.i2 = 6;
	myS1.i3 = 7;

	int sum;

	// Aufgabe 2.6.1
	sum = myS1.i1 + myS1.i2 + myS1.i3;

	printf("Sum = %d\n", sum);

	// Aufgabe 2.6.2
	int mult;
	mult = multStructS(myS1);

	// Aufgabe 2.6.3

	s myS2;

	if (1) {
		cout << "hello from Aufgabe 2.3, Please enter 3  integer:" << endl;
		cin >> myS2.i1 >> myS2.i2 >> myS2.i3;
		cout << "myS2.i1 = " << myS2.i1 << " myS2.i2 = " << myS2.i2 << " myS2.i3 = " << myS2.i3 << endl;
	}

	// Aufgabe 2.6.4

	printf("%d %d %d in File geschrieben.\n", myS2.i1, myS2.i2, myS2.i3);

	std::ofstream fo("myCppIntFile.txt", std::ofstream::app); // ios::binary

	if (fo)
		for (int i = 0; i < 5; ++i)
			fo << myS2.i1 << ";" << myS2.i2 << ";" << myS2.i3 << endl;

	fo.close();

	// Aufgabe 2.6.5

	std::ifstream fi("myCppIntFile.txt");
	char ch;

	if (!fi) cout << "Error finding that file" << endl;


	//works beautifully
	if (1)
		while (fi >> myS2.i1 >> ch >> myS2.i2 >> ch >> myS2.i3)
			cout << "myS2.i1 = " << myS2.i1 << " myS2.i2 = " << myS2.i2 << " myS2.i3 = " << myS2.i3 << endl;
	fi.close();

	getchar();
	return 0;
}

