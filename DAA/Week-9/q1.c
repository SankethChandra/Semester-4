#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * string;

string T, P;
int n, m;

int i, j;

void input () {
	T = (string)malloc(1024 * sizeof(char));
	P = (string)malloc(256 * sizeof(char));
	printf("\n ***Case sensitive***\n Enter the text: ");
	scanf(" %s", T);
	n = strlen(T);
	printf("Enter the pattern: ");
	scanf(" %s", P);
	m = strlen(P);
}

int horspool (int *opcount) {

	int shift[128];
	for (i = 0; i < 128; ++i) {
		shift[i] = m;
	}

	for (i = 0; i < m - 1; ++i) {
		shift[P[i]] = m - 1 - i;
	}

	
	j = 0;
	while (j + m <= n) {
		*opcount += 1;
		if (P[m-1] == T[j+m-1]) {
			i = m - 2;
			while (i >= 0 && P[i] == T[j+i]) {
				*opcount += 1;
				i -= 1;
			}
			if (i == -1)
				return j;
		}
		j += shift[T[j+m-1]];
	}
	return -1;

}

int main ()
{
	input();
	int opcount = 0;//comparisions
	int hs = horspool(&opcount);
	printf("    Text: %s \n", T);
	printf(" Pattern: %s \n", P);
	printf("Horspool\n Index if found: %d, Comparions: %d\n", hs, opcount);
	return 0;
}