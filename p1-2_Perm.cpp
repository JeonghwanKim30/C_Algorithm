/*
	file : p1
	author : Kimjeonghwan
	datetime : 2021-12-11
	description : this code is about perming with Quicksort.. Perming mean finding all cases of char array.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void perm(char* a, int k, int n);
void quicksort(char* a, int low, int high);
int partition(char* a, int low, int high);

int main()
{
	char a[100];
	printf("Input : ");
	gets_s(a,100);
	int	n = strlen(a);
	perm(a, 0, n);
	return 0;
}



void perm(char *a, int k, int n) {
	
	char temp;

	if (k >= n) { printf("%s\n", a); return; }
	quicksort(a, k, n-1);
	perm(a, k + 1, n);
	quicksort(a, k + 1, n-1);
	
	for (int m = k + 1; m < n; m++ ) {
		if(a[m]>a[k])
		{
			temp = a[k], a[k] = a[m]; a[m] = temp;
			perm(a, k + 1, n); quicksort(a, k + 1, n-1);
		}
	}
}

void quicksort(char *a, int low, int high) {

	int pivotpoint;

	if (low < high)
	{
		pivotpoint = partition(a, low, high);
		quicksort(a, low, pivotpoint - 1);
		quicksort(a, pivotpoint + 1, high);
	}
}

int partition(char *a, int low, int high) {
	int i, j;
	char pivotitem;
	char temp;
	int pivotpoint = 0;

	int randnum = (rand() % (high - low)) + low;
	temp = a[randnum]; a[randnum] = a[low]; a[low] = temp;

	pivotitem = a[low]; j = low;

	for (i = low + 1; i <= high; i++) {
		if (a[i] < pivotitem) {
			j++;
			temp = a[i]; a[i] = a[j]; a[j] = temp;
		}
		pivotpoint = j;
	}
	temp = a[low]; a[low] = a[pivotpoint]; a[pivotpoint] = temp;

	return pivotpoint;
}