/*
	file : p3-1.cpp
	author : Kimjeonghwan
	datetime : 2021-02-15
	description : 
		Scheduling mean minimization total time in System.
		Read '03_Scheduling.txt'that has vertex Num, vertex info.
			info - job number, deadline (Does not work after deadline), profit
		then by Using fun CollapsingFind and SimpleUnion, make Data Struct. and then output all Job number that we used in order
		
		Make a Array(S) that mean job schedule, each index store job number. (1 index mean Should be done in first order)
		Then bring Info and store each S's index that match Info's deadline, in descending order of Profit.
		If Index is already filled, move one left index. When it reaches 0 index, move to rightmost index.
		parent store Each S's index's parent index. By collapsingFind, We can find leftmost bit.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void SimpleUnion(int i, int j);
int CollapsingFind(int i);

int* parent;
int* S;

int main()
{
	int num = 0;
	int job, deadline, profit;
	FILE* fp;

	fopen_s(&fp, "03_Scheduling.txt", "r");
	
	if (fp == NULL)
	{
		printf("파일 열람 실패 \n");
		return 0;
	}

	fscanf_s(fp,"%d", &num);

	parent = (int*)malloc(sizeof(int) * (num + 1));
	S = (int*)malloc(sizeof(int) * (num+1));

	for (int x = 1; x <= num; x++)		parent[x] = -1;

	parent[0] = num;

	for (int x = 0; x < num; x++)
	{
			fscanf_s(fp, "%d %d %d", &job, &deadline, &profit);
			int temp = CollapsingFind(deadline);
			S[temp] = job;
			SimpleUnion(temp, CollapsingFind(temp-1));
	}

	for (int i = 1; i <= num; i++)
	{
		printf("%d ", S[i]);
	}
	
	fclose(fp);
	return 0;
}

// Fun 'SimpleUnion' union root j to root i.
void SimpleUnion(int i, int j)
{
	if (i != j)
	{
		parent[i] = j;
	}
}

// Fun 'CollapsingFind' return root and make all node's parent value to root.
int CollapsingFind(int i)
{
	int r = i;
	for (r; parent[r] >= 0; r = parent[r]);
	while (i != r)
	{
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}

















