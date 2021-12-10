/*
	file : p1
	author : Kimjeonghwan
	datetime : 2021-12-10
	description : this code is quicksort with random pivot.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int S[8] = { 15,22,13,27,12,10,20,25 };

void quicksort(int low, int high);
int partition(int low, int high);

int main()
{
	srand(time(NULL));
	printf("정렬 전 : ");
	for (int i = 0; i <= (sizeof(S) / (sizeof(int)) - 1); i++)
	{
		printf("%d ", S[i]);
	}
	printf("\n\n정렬 후 : ");

	quicksort(0, (sizeof(S) / (sizeof(int)) - 1));


	for (int i = 0; i <= (sizeof(S) / (sizeof(int)) - 1); i++)
	{
		printf("%d ", S[i]);
	}
	return 0;
}



void quicksort(int low, int high) {

	int pivotpoint;

	if (low < high)
	{
		pivotpoint = partition(low, high);
		quicksort(low, pivotpoint - 1);
		quicksort(pivotpoint + 1, high);
	}
}

int partition(int low, int high) {
	int i, j;
	int pivotitem;
	int temp;
	int pivotpoint = 0;

	int randnum = (rand() % (high - low)) + low;
	pivotitem = S[randnum]; j = low;
	pivotpoint = j;
	{temp = S[randnum]; S[randnum] = S[low]; S[low] = temp; }
	for (i = low + 1; i <= high; i++) {
		if (S[i] < pivotitem) {
			j++;
			temp = S[i]; S[i] = S[j]; S[j] = temp;
			pivotpoint = j;
		}
	}
	temp = S[low];S[low] = S[pivotpoint];S[pivotpoint] = temp;

	return pivotpoint;
}