
#include <iostream>

int L4_2main() {

	std::cout << "Hello from Aufgabe 4.2." << std::endl;

	//
	// am Stack
	//
	const int Ni = 5;
	int vi[Ni]; // am Stack. 

	for (int ni = 0; ni < Ni; ++ni)
		vi[ni] = ni;

	//
	// am  Heap
	//
	int N = 1000;
	int* pi = new int[N]; // am heap

	for (int n = 0; n < N; ++n)
		pi[n] = n; // *(pi + n) = n; is old stype but works as well of course

	// for read and write to and from file as text and binary see the other samples




	delete[] pi;

	getchar();
	return 0;
}
