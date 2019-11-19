
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

	
	
	//
	// or Measure the file first
	//
	std::ifstream fix("MyInts.bin", std::ios::ate | std::ios::binary); // set filepointer to end of file

	int fileLength = fix.tellg(); //  get filesize
	int N_ints = fileLength / sizeof(int); // calc amount of int in file

	cout << "fileLength " << fileLength << endl;
	cout << "N_ints " << N_ints << endl;

	int* pi = new int[N_ints]; // request memory space for int's

	for (int i = 0; i < N_ints; ++i)
		pi[i] = -1;

	fix.seekg(0, std::ios::beg); // reset filepointer to beginning of file

	fix.read(reinterpret_cast<char*>(pi), sizeof(int)* N_ints); // read ints into heap memory

	fix.close();

	for (int i = 0; i < N_ints; ++i)
		cout << "cout pi[] = " << pi[i] << endl;

	getchar();
	return 0;
}
