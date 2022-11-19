#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)

//type of char
char init[10000]; // 어떤 문자가 와도 기준이 될 수 있게
int sz = 0;

//graph
char* adj[100];
char edge[1000][2]; // 간선 간 정보
int idx[1000]; // 인덱스 개수
int inputDeg[10000]; // indegree의 수
int outputDeg[10000]; // outputdegree의 수

// queue
char queue[10005];
int front = 0; int rear = 0;

//result
int cnt = 0;
char result[10000];

void push(char x) {
	queue[rear++] = x;
}

void pop() {
	front++;
}

int isEmpty() {
	if (rear == front) return -1;
	return 0;
}

int main() {
	int v, e;
	scanf("%d", &v); // vertex의 개수 입력받기
	for (int i = 0; i < v; i++) {
		getchar();
		scanf("%c", &init[sz++]); // 기준이 되는 문자 init[0]
	}
	scanf("%d", &e); // edge개수 받기
	for (int i = 1; i <= e; i++) {
		getchar();
		scanf("%c %c", &edge[i][0], &edge[i][1]);
		outputDeg[edge[i][0] - init[0] + 1]++; // inputDegree
		inputDeg[edge[i][1] - init[0] + 1]++; // outputDegree
	}
	for (int i = 1; i <= v; i++)
		adj[i] = malloc(outputDeg[i] * sizeof(char)); //graph는 outputdegree 만큼 할당
	for (int i = 1; i <= e; i++) {
		int u = edge[i][0] - init[0] + 1; char v = edge[i][1];
		adj[u][idx[u]++] = v;
	}
	// deg = input degree의 개수, adj[u] = 방향graph의 정보

	for (int i = 1; i <= v; i++) {
		if (inputDeg[i] == 0) push(i + init[0] - 1); // inputDegree가 없으면 push
	}

	while (isEmpty() != -1) {
		char cur = queue[front]; pop();
		result[cnt++] = cur;
		for (int i = outputDeg[cur - init[0] + 1] - 1; i >=0 ; i--) {
			inputDeg[adj[cur - init[0] + 1][i] - init[0] + 1]--;
			if (inputDeg[adj[cur - init[0] + 1][i] - init[0] + 1] == 0)
				push(adj[cur - init[0] + 1][i]);
		}
	}

	if (cnt != v) printf("0"); // cycle이 있다면 정점을 다 돌지못함

	else {
		for (int i = 0; i < cnt; i++)
			printf("%c ", result[i]);
	}
}
