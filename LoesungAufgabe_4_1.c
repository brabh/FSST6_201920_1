
/* 
**
** Lösung 4.1 
** lege 10 int als array im stack an
** lege 1000 int als array im heap an in C
** 
*/

#include <stdio.h>

int L4_1main() {

	printf("Hello from Aufgabe 4.1\n");

	//
	// am Stack
	//
	const int Ni = 5;
	int vi[5]; // am Stack. Anm.: vi[Ni] did not work in MSFT C compiler 

	for (int ni = 0; ni < Ni; ++ni)
		vi[ni] = ni;

	//
	// am  Heap
	//
	int N = 1000;
	int* pi = (int *) malloc(sizeof(int)*N); // am heap

	for (int n = 0; n < N; ++n)
		pi[n] = n; // *(pi + n) = n; is old stype but works as well of course

  //
	// for read and write to and from file as text and binary see the other samples
  //




	free(pi);

	getchar();
	return 0;
}




