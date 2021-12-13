/*
	file : p2.cpp
	author : Kimjeonghwan
	datetime : 2021-12-11
	description : Read '02주차 - Kruskal.txt'. 
		then by Using fun CollapsingFind and WeightedUnion, make Data Struct. and then output all node that we used.
		Fun 'CollapsingFind' return root and make all node's parent value to root.
		If roots of vertices a and b are the same, they form a cycle.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void WeightedUnion(int i, int j);
int CollapsingFind(int i);


typedef struct Edge {
	int i, j;
	int weight;
}Edge;

int* parent;

int main()
{

	FILE* fp;
	Edge* E;


	fopen_s(&fp,"02주차 - Kruskal.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열람 실패 \n");
		return 0;
	}

	int edge;
	int vertex;
	int F=0;
	fscanf_s(fp,"%d %d", &vertex, &edge);

	E = (Edge*)malloc(sizeof(Edge) * (edge));

	for (int x = 0; x < edge; x++)
	{
		fscanf_s(fp, "%d %d %d", &E[x].i, &E[x].j, &E[x].weight);
	}

	parent = (int*)malloc(sizeof(int) * (vertex+1));

	for (int x = 1; x <= vertex; x++)
	{
		parent[x] = -1;
	}

	for (int x = 1; x < edge && F < vertex - 1; x++)
	{
		int p, q;

		p = CollapsingFind(E[x].i);
		q = CollapsingFind(E[x].j);

		if (p != q)
		{
			WeightedUnion(p, q);
			F++;
			printf("%d %d %d\n", E[x].i, E[x].j, E[x].weight);
		}
	}

	fclose(fp);

	
	return 0;
}



void WeightedUnion(int i, int j)
{
	int temp = parent[i] + parent[j];

	if (parent[i] > parent[j])
	{
		parent[i] = j;
		parent[j] = temp;
	}
	else
	{
		parent[j] = i;
		parent[i] = temp;
	}
}

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