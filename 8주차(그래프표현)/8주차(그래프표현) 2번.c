#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
// Undirected Graph
// 정점 v, 간선 e
// 1.인접행렬 2.인접리스트
// 정점이 많고 간선이 적을 때 인접리스트이 공간절약에 유리

int map[7][7];
int edge[7];

void maping() {
	map[1][2] = 1;
	map[1][3] = 1;
	map[1][4] = 1;
	map[1][6] = 2;

	map[2][1] = 1;
	map[2][3] = 1;

	map[3][2] = 1;
	map[3][5] = 4;
	map[3][1] = 1;

	map[4][1] = 1;

	map[5][3] = 4;
	map[5][6] = 3;
	map[5][5] = 4;

	map[6][5] = 3;
	map[6][1] = 2;
}

void edgeNum() {
	edge[1] = 4; edge[2] = 2; edge[3] = 3; 
	edge[4] = 1; edge[5] = 3; edge[6] = 2;
}

int main() {
	maping(); edgeNum();
	char command; int a, b, w;
	while (1) {
		scanf("%c", &command);
		if (command == 'a') {
			scanf("%d", &a);
			if (a >= 7) {
				printf("-1\n"); continue;
			}
			for (int i = 0; i < 7; i++) {
				if (map[a][i] != 0) // 가중치가 0이면 없는 간선
					printf(" %d %d", i, map[a][i]);
			}
			printf("\n");
		}

		if (command == 'm') {
			scanf("%d %d %d", &a, &b, &w);
			if (a >= 7 || b >= 7) {
				printf("-1\n"); continue;
			}
			if (w == 0) {
				map[a][b] = 0; map[b][a] = 0;
			}
			else if (map[a][b] != 0 && map[b][a] != 0) {
				// 간선이 존재하면, 가중치 변경
				map[a][b] = w; map[b][a] = w;
			}
			else {
				// 간선이 존재하지 않으면,
				map[a][b] = w; map[b][a] = w;
			}
		}
		
		if (command == 'q')
			break;
	}
}
