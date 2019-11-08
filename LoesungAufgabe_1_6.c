#pragma warning(disable:4996)

#include <stdio.h>

struct s {
	int i1;
	int i2;
	int i3;
};

typedef struct s ss;
typedef ss* ps;       // pointer auf ss

//
// Aufgabe 1.6
//

int multStructS(ss d) {

	return d.i1 * d.i2 * d.i3;
}


int main() {

	printf("Hello from Aufgabe 1.6.\n");

	struct s myS1;

	myS1.i1 = 5;
	myS1.i2 = 6;
	myS1.i3 = 7;

	int sum;


	// Aufgabe 1.6.1


  sum = myS1.i1 + myS1.i2 + myS1.i3;

	printf("Sum = %d\n", sum);


	// Aufgabe 1.6.2
  
  
	int mult;
	mult = multStructS(myS1);


	// Aufgabe 1.6.3


	ss myS2;
	printf("Bitte geben sie drei Integer ein:\n");

	scanf("%d %d %d", &myS2.i1, &myS2.i2, &myS2.i3);

	printf("Es wurde eingegeben %d %d %d\n", myS2.i1, myS2.i2, myS2.i3);


	// Aufgabe 1.6.4


	char ch;
	FILE* fp;

	fp = fopen("my3IntFile.txt", "a");

	ch = ';';
	fprintf(fp, "%d%c%d%c%d\n", myS2.i1, ch, myS2.i2, ch, myS2.i3);

	fclose(fp);

	printf("%d %d %d in File geschrieben.\n", myS2.i1, myS2.i2, myS2.i3);


	// Aufgabe 1.6.5


	//FILE* fp;

	fp = fopen("my3IntFile.txt", "r");

	while (fscanf(fp, "%d%c%d%c%d", &myS2.i1, &ch, &myS2.i2, &ch, &myS2.i3) == 5)
		printf("Aus File gelesen: %d %d %d\n", myS2.i1, myS2.i2, myS2.i3);

	fclose(fp);

	getchar();
	return 0;
}
