#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define INF 1e9+10 // 무한대
// Dijkstra
// : 하나의 시작점으로부터 다른 모든 정점까지의 최단 거리를 구하는 알고리즘

typedef struct {
	int v; int cost;
}graph;

int n, m, s; // vertex, edge, sp
graph adj[1000][1000];
graph pq[10000];
int pqNum = 0;
int d[10005]; // distance table
int outDegree[10005];

void push(int v, int cost) {
	pq[pqNum].v = v;
	pq[pqNum].cost = cost;
	pqNum++;
}

int pqEmpty() {
	if (pqNum == 0) return 1;
	else return 0;
}

void pop() {
	pqNum--;
}

void sort() {
	for (int i = 0; i < pqNum; i++) {
		for (int j = pqNum - 1; j > 0; j--) {
			if (pq[j].cost > pq[j - 1].cost) {
				graph tmp = pq[j];
				pq[j] = pq[j - 1];
				pq[j - 1] = tmp;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	for (int i = 0; i < m; i++) {
		int a; int b; int cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a][outDegree[a]].v = b; adj[a][outDegree[a]].cost = cost;
		adj[b][outDegree[b]].v = a; adj[b][outDegree[b]].cost = cost;
		outDegree[a]++; outDegree[b]++;
	}
	d[s] = 0; // 테이블 시작점은 가중치가 0이니까
	push(s, d[s]); // 우선 순위 큐에, 시작점과 가중치를 넣어줌
	while (!pqEmpty()) {
		graph cur = pq[pqNum - 1]; pop();
		if (d[cur.v] != cur.cost) continue; // 같지 않다면 쓰레기 값
		for (int i = 0; i < outDegree[cur.v]; i++) {
			if (d[adj[cur.v][i].v] <= d[cur.v] + adj[cur.v][i].cost) continue;
			d[adj[cur.v][i].v] = d[cur.v] + adj[cur.v][i].cost;
			push(adj[cur.v][i].v, d[adj[cur.v][i].v]);
		}
		sort(); // 우선순위 큐 정렬
	}
	for (int i = 1; i <= n; i++) {	
		if (d[i] == INF || i == s) continue;
		else printf("%d %d\n", i, d[i]);
	}
}