
#pragma warning(disable:4996)

#include <stdio.h>

int main() {
	int a = 0, b = 0, c = 0;
	char ch;

	FILE* fp;

	fp = fopen("myFile.txt", "r");
	
	while (fscanf(fp, "%d%c%d%c%d", &a, &ch, &b, &ch, &c) == 5)
	printf("File: %d %d %d\n", a, b, c);
	
	fclose(fp);

	getchar();
	return 0;
}
