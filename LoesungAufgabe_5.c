#pragma once
#pragma warning(disable:4996)

#include <stdio.h>

int main() {
	int a = 12;
	FILE* fb;

	fb = fopen("Text.bin", "ab"); // append binary

	for(int i = 0; i < 5; ++i)
		fwrite(&a, sizeof(int), 1, fb);

	fclose(fb);

	printf("Done the write");

	fb = fopen("Text.bin", "rb"); // read binary

	fseek(fb, SEEK_SET, SEEK_END);

	int N_bytes = ftell(fb);

	printf("Anzahl int im File = %d\n", N_bytes/sizeof(int));

	int N_ints = N_bytes / sizeof(int); // calc amount of ints

	int* pi = malloc( sizeof(int)*N_ints);

	rewind(fb); // set filepointer to origin

	fread((void*)pi, sizeof(int), N_ints, fb); // read into memory

	fclose(fb); // close the file

	// print int's from memory
	for (int n = 0; n < N_ints; ++n)
		printf("%d\n", pi[n]);

	return 0;
}
