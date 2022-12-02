#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)

// MST (minimum spanning tree)
// Prim algorithm
// �Ź� ���� ������ ã�Ƽ� �������ֱ�. �������� �ʿ��� ��? Priority Queue�� ����ؼ� �ּҰ��� ã��

typedef struct {
	int v1; int v2; int cost;
}Pgraph;

typedef struct {
	int v; int cost;
}adj;

int n, m, pqNum, ans; // ������ ��, ������ ��, pq�� ��, �ּҺ��
int chk[10000]; // ������ �ּҽ���Ʈ���� ���ԵǾ��ִ°�?
Pgraph pq[10005]; // pq�ǹ迭
adj vertex[1000][1000]; // ������
int outDegree[10005];

void sort() {
	for (int i = 0; i < pqNum; i++) {
		for (int j = pqNum - 1; j > 0; j--) {
			if (pq[j].cost > pq[j - 1].cost) {
				Pgraph tmp = pq[j - 1];
				pq[j - 1] = pq[j];
				pq[j] = tmp;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		vertex[a][outDegree[a]].v = b; vertex[a][outDegree[a]].cost = cost;
		vertex[b][outDegree[b]].v = a; vertex[b][outDegree[b]].cost = cost;
		outDegree[a]++; outDegree[b]++;
	}
	chk[1] = 1;// 1������ �����ϹǷ�
	for (int i = 0; i < outDegree[1]; i++) {
		pq[i].v1 = 1; pq[i].v2 = vertex[1][i].v; pq[i].cost = vertex[1][i].cost;
		pqNum++;
	} // 1�� ������ pq�� ����

	sort(); // priority queue
	
	int cnt = 0;
	printf(" 1");
	while (cnt < n - 1) {
		int a, b, cost;
		a = pq[pqNum - 1].v1; b = pq[pqNum - 1].v2; cost = pq[pqNum - 1].cost; pqNum--; // pq�� pop���� 
		if (chk[b]) continue; // ���� �湮�� �����̸� �ѱ��(cycle�� �߻��ϹǷ�)
		printf(" %d", b);
		ans += cost; 
		chk[b] = 1; // check ���ְ� 
		cnt++; // ���� ���� ����
		for (int i = 0; i < outDegree[b]; i++) {
			if (!chk[vertex[b][i].v]) { // ���� �湮�� ������ �ƴ϶�� pq�� �־��ֱ�
				pq[pqNum].v1 = b;
				pq[pqNum].v2 = vertex[b][i].v;
				pq[pqNum].cost = vertex[b][i].cost;
				pqNum++;
			}
		}
		sort(); // pq�� ���ĵ� ���·� ����
	}
	printf("\n%d", ans);
}