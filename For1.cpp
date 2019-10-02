#include <iostream>

int f(int N) {

	int x[5]; // im stack
	int* pi = new int[N]; // im heap

	for (int n = 0; n < N; ++n)
		*(pi + n) = n; // the famous c/c++ pointerarithmetic


	return 0;
}




int main() {

	f(1000);

	return 0;
}


