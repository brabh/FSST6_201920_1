
#pragma warning(disable:4996)

#include <stdio.h>

int zmain() {

	FILE* fp; // = NULL;

	fp = fopen("C:\\TGM201920\\horsesDNA\\input_tree.csv", "r");

	//if (fp == NULL) {
	//	printf("File konnte nicht geöffnet werden!\n");
	//	exit(0);
	//}

	char c; // for ';'
	char f[100];
	char child[100];
	char lineName[100];

	for (; fscanf(fp, "%s%c%s%c%s", f, &c, child, &c, lineName) == 5;) {
		printf("%s %s %s\n", f, child, lineName);
		//printf("\n");
	}

	fclose(fp);



	getchar();
	return 0;
}
