
#include <iostream>
#include <fstream>
#include <string>

//
// Aufgabe 6
//

using std::cout;
using std::endl;
using std::cin;

int L6main() {
	int a = 6;

	// Binary write
	std::ofstream fob("MyInts.bin", std::ios::binary | std::ios::out);
	if (fob)
		for (int i = 0; i < 5; ++i)
			fob.write(reinterpret_cast<const char*>(&a), sizeof(int)); // << b << c;
	fob.close();

	// Binary read
	std::ifstream fib("MyInts.bin", std::ios::binary);
	//while(fib.read((char*)(&a), sizeof(int)).good()) // works, old type cast
	while (fib.read(reinterpret_cast<char*>(&a), sizeof(int)).good())
		cout << "My binary a is " << a << endl;
	fib.close();

	getchar();
	return 0;
}
