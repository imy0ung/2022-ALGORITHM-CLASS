#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define INF 1e9+10 // ���Ѵ�

typedef struct {
	int v, cost;
}graph;

// �׸��� �˰���
// d���̺� �����ϰ�, pq �����ϰ�, �������� �ִܰŸ��� ���
// �ð����⵵�� O(n+m)

graph adj[1000][1000];
graph pq[1000]; // ���� �������� �ִܰŸ��� ����ؼ� ����
int deg[1000];
int d[1000]; // distance �迭
int pqNum;
int n, m, s;

void push(int v, int cost) {
	pq[pqNum].v = v; pq[pqNum].cost = cost;
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
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a][deg[a]].v = b; adj[a][deg[a]].cost = cost;
		adj[b][deg[b]].v = a; adj[b][deg[b]].cost = cost;
		deg[a]++; deg[b]++;
	}
	d[s] = 0; push(s, d[s]);
	while (!isEmpty()) {
		// cur�� Ȯ���� ���
		// adj ���� ������ // d�� ����ؼ� �����ϴ³�
		graph cur = pq[pqNum - 1]; pop();
		if (d[cur.v] != cur.cost) continue; // Ȯ���� ��忡�Ը�
		for (int i = 0; i < deg[cur.v]; i++) {
			if (d[adj[cur.v][i].v] <= d[cur.v] + adj[cur.v][i].cost) continue;
			d[adj[cur.v][i].v] = d[cur.v] + adj[cur.v][i].cost;
			push(adj[cur.v][i].v, d[adj[cur.v][i].v]);
		}
		sort();
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == INF || i == s) continue;
		printf("%d %d\n", i, d[i]);
	}
}