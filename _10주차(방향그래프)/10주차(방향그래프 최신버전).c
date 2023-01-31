#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define INF 1e9+10 // 무한대

char adj[100][1000]; //인접 행렬
char vertexs[1000]; // 정점들
char queue[10005]; //큐배열
char ans[1000]; // 답배열
int front = 0;
int rear = 0;
int outDegree[10000]; // 아웃디그리
int inDegree[10000]; // 인디그리

void push(char x) {
	queue[rear++] = x;
}

void pop() {
	front++;
}

int isEmpty() {
	if (rear == front) return 1;
	else return 0;
}

int main() {
	int n, m; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &vertexs[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		getchar();
		char a; char b;
		scanf("%c %c", &a, &b);
		adj[a][outDegree[a]] = b; // 어차피 아스키코드 해봤자 100이니까
		outDegree[a]++; inDegree[b]++;
	}

	for (int i = vertexs[0]; i <= vertexs[n - 1]; i++) {
		if (inDegree[i] == 0) // 인드리기 0인놈들 푸쉬
			push(i);
	}

	int cnt = 0;

	while (!isEmpty()) {
		char cur = queue[front]; pop();
		ans[cnt++] = cur;
		for (int i = outDegree[cur] - 1; i >= 0; i--) {
			inDegree[adj[cur][i]]--; // inDegree 빼주기
			if (inDegree[adj[cur][i]] == 0)
				push(adj[cur][i]);
		}
	}

	if (cnt != n) printf("0"); // 싸이클임
	else
		for (int i = 0; i < cnt; i++)
			printf("%c ", ans[i]);
}
