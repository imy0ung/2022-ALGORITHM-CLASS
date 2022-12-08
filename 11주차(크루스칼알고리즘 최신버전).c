#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define INF 1e9+10 // 무한대
// Dijkstra
// : 하나의 시작점으로부터 다른 모든 정점까지의 최단 거리를 구하는 알고리즘

typedef struct {
	int v1;
	int v2;
	int w;
}graph;

graph adj[1000];
int outDegree[10000];
int p[1000];
int n, m;
int ans;

void sort() {
	for (int i = 0; i < m; i++) {
		for (int j = m - 1; j > 0; j--) {
			if (adj[j].w < adj[j - 1].w) {
				graph tmp = adj[j];
				adj[j] = adj[j - 1];
				adj[j - 1] = tmp;
			}
		}
	}
}

int find(int x) {
	if (p[x] < 0) return x; // 음수면 이어져있지않음
	return p[x] = find(p[x]);
}

int isDiff(int u, int v) {
	u = find(u); v = find(v);
    if (u == v) return 0; // 부모가 같은 상황
	else if (u < v) p[v] = u;
	else p[u] = v;
	return 1; 
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &adj[i].v1, &adj[i].v2, &adj[i].w);
	}
	sort();
	for (int i = 1; i <= n; i++)
		p[i] = -1;
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		graph cur = adj[i];
		if (!isDiff(cur.v1, cur.v2)) continue;
		printf("cost : %d\n", cur.w);
		/*printf(" %d", cur.w);*/
		ans += cur.w; cnt++;
		if (cnt == n - 1) break;
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", p[i]);

	printf("\n%d", ans);
}