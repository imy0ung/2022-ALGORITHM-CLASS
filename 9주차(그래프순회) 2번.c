#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)
// BFS

int map[101][101]; // 101이 아니라서? 
int queue[10000];
int vis[10000];
int front = 0; int rear = 0;

void push(int x) {
	queue[rear++] = x;
}

void pop() {
	front++;
}

int isEmpty() {
	if (rear == front) return -1;
	else return 0;
}

void bfs(int s, int v) {
	push(s);
	vis[s] = 1; // 방문처리
	while (isEmpty() != -1) {
		int cur = queue[front]; pop();
		printf("%d\n", cur);
		for (int i = 1; i <= v; i++) {
			if (map[cur][i] == 1) {
				if (vis[i] == 1) continue;
				push(i);
				vis[i] = 1;
			}
		}
	}
}

int main() {
	int v, e, s; // vertex, edge
	scanf("%d %d %d", &v, &e, &s);

	for (int i = 0; i < e; i++) {
		int a; int b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1; map[b][a] = 1;
	}
	bfs(s, v);
}