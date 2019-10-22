#include <stdio.h>

int f1(int x, int y, int z);

int main() {

	printf("Hello von Aufgabe 1.2\n");

	int a = 1, b = 2, c = 3;
	int sum;

	sum = f1(a, b, c);

	printf("Sum = %d\n", sum);

	getchar();
	return 0;
}


int f1(int d, int e, int f) {
	int sum;

	sum = d + e + f;

	return sum;
}

