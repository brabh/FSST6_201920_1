// to omit the scanf warning from msft compiler do one of  the following:
//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
// or add /wd4996 in Projekt-> Eigenschaften -> C/C++ -> Befehlszeile -> zusätzliche Optionen

#include <stdio.h>

int f_v1() {
	int a, b, c;

	printf("Bitte geben sie drei Integer ein:\n");
	scanf("%d %d %d", &a, &b, &c);

	printf("Es wurde eingegeben %d %d %d\n", a, b, c);
  
	return 0;
}



int f_endlos() {
	int a, b, c;

	printf("Bitte geben sie drei Integer ein:\n");
  
	// führt bei falschen Eingaben zu Endlosschleifen
	while (scanf("%d %d %d", &a, &b, &c) != 3)
		printf("Bitte geben sie doch drei Integer ein:\n");

	return 0;
}


int f_v2() {
	int a, b, c;
	char virtLine[100];
  
	do {
		printf("Bitte geben sie drei Integer ein:\n");
		fgets(virtLine, 99, stdin);
	} while (sscanf(virtLine, "%d %d %d", &a, &b, &c) != 3);

	printf("Es wurde eingegeben %d %d %d\n", a, b, c);
  
	return 0;
}





int main() {

	//f_v1();
	//f_endlos();
	f_v2();


	getchar();
	return 0;
}
