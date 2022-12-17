#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define INF 0x3f3f3f3f

typedef struct {
	int v, cost;
}graph;

int n, m, s; // n은 정점의 개수, m은 간선의 개수
graph adj[105][105]; // adjacency matrix 선언
int outdeg[1000];
int d[1000];

int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from][outdeg[from]].v = to; adj[from][outdeg[from]].cost = cost;
		outdeg[from]++;
	}
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	d[s] = 0;

	for (int i = 1; i <= n; i++) {
		// 한 정점에 대해,
		for (int j = 1; j <= n; j++) {
			// 그 정점을 거쳐서 가는 경로를 다 계산한다.
			for (int k = 0; k < outdeg[j]; k++) {
				// 정점에 대한 간선에 정보
				int next = adj[j][k].v;
				int cost = adj[j][k].cost;
				// j까지 가는 간선이랑 드는 비용을 비교
				if (d[j] != INF && d[next] > d[j] + cost)
					d[next] = d[j] + cost;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF || i == s) continue;
		else printf("%d %d\n", i, d[i]);
	}
}
