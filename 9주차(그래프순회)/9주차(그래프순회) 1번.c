#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
// DFS

int edge[1000][2];
int deg[1000]; // 정점 별 차수 
int* adj[1000]; // adj[i]에서 새로운 정점을 추가할 때의 위치
int idx[1000];

int stack[1000];
int vis[1000];
int sz = 0;

void sort(int x) {
	for (int i = 0; i < deg[x]; i++) {
		for (int j = deg[x] - 1; j > 0; j--) {
			if (adj[x][j] < adj[x][j - 1]) {
				int tmp = adj[x][j];
				adj[x][j] = adj[x][j - 1];
				adj[x][j - 1] = tmp;
			}
		}
	}
}

void dfs(int s) {
	vis[s] = 1;
	printf("%d\n", s);
	for (int i = 0; i < deg[s]; i++) {
		if (vis[adj[s][i]] == 1) continue;
		dfs(adj[s][i]);
	}
}

int main() {
	int v, e, s; // vertex, edge
	scanf("%d %d %d", &v, &e, &s);

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &edge[i][0], &edge[i][1]);
		deg[edge[i][0]]++; deg[edge[i][1]]++;
	} // 간선의 개수 만큼
	for (int i = 1; i <= v; i++)
		adj[i] = malloc(deg[i] * sizeof(int));
	for (int i = 0; i < e; i++) {
		int u = edge[i][0]; int v = edge[i][1];
		adj[u][idx[u]] = v;
		idx[u]++;
		adj[v][idx[v]] = u;
		idx[v]++;
	} // 인접리스트에 저장

	for (int i = 1; i <= v; i++)
		sort(i);

	dfs(s);
}
