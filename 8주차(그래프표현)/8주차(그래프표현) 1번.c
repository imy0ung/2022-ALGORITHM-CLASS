#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
// Undirected Graph
// 정점 v, 간선 e
// 1.인접행렬 2.인접리스트
// 정점이 많고 간선이 적을 때 인접리스트이 공간절약에 유리


typedef struct {
	int data;
	int weight;
}pair;

pair* adj[10];
int edge[10];

void makeGraph() {
	adj[1] = (pair*)malloc(sizeof(pair) * 4);
	adj[2] = (pair*)malloc(sizeof(pair) * 2);
	adj[3] = (pair*)malloc(sizeof(pair) * 3);
	adj[4] = (pair*)malloc(sizeof(pair) * 1);
	adj[5] = (pair*)malloc(sizeof(pair) * 3);
	adj[6] = (pair*)malloc(sizeof(pair) * 2);
	// 동적할당으로 공간절약하면서, 인접리스트 만들기

	adj[1][0].data = 2;
	adj[1][0].weight = 1;
	adj[1][1].data = 3;
	adj[1][1].weight = 1;
	adj[1][2].data = 4;
	adj[1][2].weight = 1;
	adj[1][3].data = 6;
	adj[1][3].weight = 2;

	adj[2][0].data = 1;
	adj[2][0].weight = 1;
	adj[2][1].data = 3;
	adj[2][1].weight = 1;

	adj[3][0].data = 1;
	adj[3][0].weight = 1;
	adj[3][1].data = 2;
	adj[3][1].weight = 1;
	adj[3][2].data = 5;
	adj[3][2].weight = 4;

	adj[4][0].data = 1;
	adj[4][0].weight = 1;

	adj[5][0].data = 3;
	adj[5][0].weight = 4;
	adj[5][1].data = 5;
	adj[5][1].weight = 4;
	adj[5][2].data = 6;
	adj[5][2].weight = 3;

	adj[6][0].data = 1;
	adj[6][0].weight = 2;
	adj[6][1].data = 5;
	adj[6][1].weight = 3;
}

void edgeNum() {
	edge[1] = 4;
	edge[2] = 2;
	edge[3] = 3;
	edge[4] = 1;
	edge[5] = 3;
	edge[6] = 2;
}

void sort(int x) {
	for (int i = 0; i < edge[x]; i++) {
		for (int j = edge[x] - 1; j > 0; j--) {
			if (adj[x][j].data < adj[x][j - 1].data) {
				pair tmp = adj[x][j];
				adj[x][j] = adj[x][j - 1];
				adj[x][j - 1] = tmp;
			}
		}
	}
}

int main() {
	makeGraph();
	edgeNum();

	char command; int x, y, z;

	while (1) {
		int flag = 0;
		scanf("%c", &command);

		if (command == 'a') {
			scanf("%d", &x);
			if (adj[x] == NULL)
				printf("-1"); // 없으면 -1 출력
			else {
				for (int i = 0; i < edge[x]; i++)
					printf(" %d %d", adj[x][i].data, adj[x][i].weight);
			}
			printf("\n");
		}
		if (command == 'm') {
			scanf("%d %d %d", &x, &y, &z);

			if (z != 0) {
				for (int i = 0; i < edge[x]; i++) {
					if (adj[x][i].data == y) {
						adj[x][i].weight = z;// 있다면 가중치 변경
						flag = 1;
					}
				}
				for (int i = 0; i < edge[y]; i++) {
					if (adj[y][i].data == x) {
						adj[y][i].weight = z;// 있다면 가중치 변경
						flag = 1;
					}
				}
				// 못찾았을 때 추가해주기
				if (flag == 0) {
					if (adj[x] == NULL || adj[y] == NULL) {
						printf("-1\n");
						continue;
					}
					if (x != y) {
						pair* tmp1 = (pair*)malloc(sizeof(pair) * ++edge[x]);
						for (int i = 0; i < edge[x]; i++)
							tmp1[i] = adj[x][i];
						pair* tmp2 = (pair*)malloc(sizeof(pair) * ++edge[y]);
						for (int i = 0; i < edge[y]; i++)
							tmp2[i] = adj[y][i];
						adj[x] = tmp1;
						adj[y] = tmp2;
					}
					else {
						pair* tmp1 = (pair*)malloc(sizeof(pair) * ++edge[x]);
						for (int i = 0; i < edge[x]; i++)
							tmp1[i] = adj[x][i];
						adj[x] = tmp1;

					}
					adj[x][edge[x] - 1].data = y;
					adj[y][edge[y] - 1].data = x;
					adj[x][edge[x] - 1].weight = z;
					adj[y][edge[y] - 1].weight = z;

					sort(x); sort(y); // 정렬
				}
			}

			else {
				if (adj[x] == NULL || adj[y] == NULL) {
					printf("-1\n");
					continue;
				}

				if (x != y) {
					for (int i = 0; i < edge[x]; i++) {
						if (adj[x][i].data == y) {
							adj[x][i].data = 100;
						}
					}
					sort(x);
					pair* tmp1 = (pair*)malloc(sizeof(pair) * --edge[x]);
					for (int i = 0; i < edge[x]; i++)
						tmp1[i] = adj[x][i];
					adj[x] = tmp1;

					for (int i = 0; i < edge[y]; i++) {
						if (adj[y][i].data == x) {
							adj[y][i].data = 100;
						}
					}
					sort(y);
					pair* tmp2 = (pair*)malloc(sizeof(pair) * --edge[y]);
					for (int i = 0; i < edge[y]; i++)
						tmp2[i] = adj[y][i];
					adj[y] = tmp2;
				}
				else {
					for (int i = 0; i < edge[x]; i++) {
						if (adj[x][i].data == y) {
							adj[x][i].data = 100;
						}
					}
					sort(x);
					pair* tmp1 = (pair*)malloc(sizeof(pair) * --edge[x]);
					for (int i = 0; i < edge[x]; i++)
						tmp1[i] = adj[x][i];
					adj[x] = tmp1;
				}
			}
		}
		if (command == 'q')
			break;
	}
}
