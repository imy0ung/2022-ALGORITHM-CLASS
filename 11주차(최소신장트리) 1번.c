#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)

// MST (minimum spanning tree)
// Prim algorithm
// 매번 작은 간선을 찾아서 연결해주기. 시작점이 필요할 듯? Priority Queue를 사용해서 최소값을 찾기

typedef struct {
	int v1; int v2; int cost;
}Pgraph;

typedef struct {
	int v; int cost;
}adj;

int n, m, pqNum, ans; // 정점의 수, 간선의 수, pq의 수, 최소비용
int chk[10000]; // 정점이 최소신장트리에 포함되어있는가?
Pgraph pq[10005]; // pq의배열
adj vertex[1000][1000]; // 정점들
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
	chk[1] = 1;// 1번부터 시작하므로
	for (int i = 0; i < outDegree[1]; i++) {
		pq[i].v1 = 1; pq[i].v2 = vertex[1][i].v; pq[i].cost = vertex[1][i].cost;
		pqNum++;
	} // 1과 간선을 pq에 저장

	sort(); // priority queue
	
	int cnt = 0;
	printf(" 1");
	while (cnt < n - 1) {
		int a, b, cost;
		a = pq[pqNum - 1].v1; b = pq[pqNum - 1].v2; cost = pq[pqNum - 1].cost; pqNum--; // pq의 pop과정 
		if (chk[b]) continue; // 만약 방문한 정점이면 넘기기(cycle이 발생하므로)
		printf(" %d", b);
		ans += cost; 
		chk[b] = 1; // check 해주고 
		cnt++; // 돌린 개수 증가
		for (int i = 0; i < outDegree[b]; i++) {
			if (!chk[vertex[b][i].v]) { // 만약 방문한 정점이 아니라면 pq에 넣어주기
				pq[pqNum].v1 = b;
				pq[pqNum].v2 = vertex[b][i].v;
				pq[pqNum].cost = vertex[b][i].cost;
				pqNum++;
			}
		}
		sort(); // pq를 정렬된 상태로 유지
	}
	printf("\n%d", ans);
}