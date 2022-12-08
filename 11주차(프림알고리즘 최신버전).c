#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define INF 1e9+10 // 무한대
// Dijkstra
// : 하나의 시작점으로부터 다른 모든 정점까지의 최단 거리를 구하는 알고리즘

typedef struct {
	int v;
	int w;
}graph;

graph adj[1000][1000];
graph pq[1000];
int outDegree[10000];
int chk[1000];
int pqNum;
int ans;

void push(int x, int y) {
	pq[pqNum].v = x; pq[pqNum].w = y;
	pqNum++;
}

void pop() {
	pqNum--;
}

int isEmpty() {
	if (pqNum == 0) return 1;
	else return 0;
}

void sort() {
	for (int i = 0; i < pqNum; i++) {
		for (int j = pqNum - 1; j > 0; j--) {
			if (pq[j].w > pq[j - 1].w) {
				graph tmp = pq[j];
				pq[j] = pq[j - 1];
				pq[j - 1] = tmp;
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a; int b; int c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a][outDegree[a]].v = b; adj[a][outDegree[a]].w = c;
		adj[b][outDegree[b]].v = a; adj[b][outDegree[b]].w = c;
		outDegree[a]++; outDegree[b]++;
	}
	chk[1] = 1;
	for (int i = 0; i < outDegree[1]; i++) {
		push(adj[1][i].v, adj[1][i].w);
	}
	sort();
	int cnt = 0;
	printf(" 1");
	while (cnt < n - 1) {
		graph cur = pq[pqNum - 1]; pop();
		if (chk[cur.v]) continue;
		printf(" %d", cur.v);
		chk[cur.v] = 1;
		ans += cur.w;
		cnt++;
		for (int i = 0; i < outDegree[cur.v]; i++) {
			if (!chk[adj[cur.v][i].v])
				push(adj[cur.v][i].v, adj[cur.v][i].w);
		}
		sort();
	}
	printf("\n%d", ans);
} // 간선 넣고 제일 작은거 뽑고 다시 푸시하고 -> 반복 chk배열을씀 (why? 싸이클방지)