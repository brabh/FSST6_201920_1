
#pragma warning(disable:4996)

#include <stdio.h>

int main(){
char ch;
int a = 5, b = 7, c = 9;

FILE* fp;

fp = fopen("myFile.txt", "a");

fprintf(fp, "%d;%d;%d\n", a, b, c);

fclose(fp);

printf("%d %d %d in File geschrieben.\n", a, b, c);


getchar();
return 0;
}
