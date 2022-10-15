#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
// 4주차 퀵정렬

int heap[100000];
int sz = 0;

void push(int x) {
	heap[++sz] = x; // 힙 배열에 데이터 삽입
	int idx = sz;
	while (idx != 1) {
		int parent = idx / 2; // 부모노드 // 제발 IDX를 SZ로 쓰지말자..
		if (heap[parent] < heap[idx]) break; // 힙을 만족시키면 종료
		int tmp = heap[parent];
		heap[parent] = heap[idx];
		heap[idx] = tmp; // 변경
		idx = parent; // 반복
	}
}

void pop() {
	heap[1] = heap[sz--]; // 변경
	int idx = 1;
	// idx * 2가 sz보다 크다는 것은 해당 노드가 단말노드라는 것
	while (2 * idx <= sz) {
		int lc = 2 * idx; int rc = 2 * idx + 1;
		int min_c = lc;
		if (rc <= sz && heap[lc] > heap[rc]) min_c = rc;
		if (heap[idx] <= heap[min_c]) break;
		int tmp = heap[idx];
		heap[idx] = heap[min_c];
		heap[min_c] = tmp; // 내려가면서 값 변경
		idx = min_c;
	}
}

int top() {
	return heap[1];
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		push(x);
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", top());
		pop();
	}
}