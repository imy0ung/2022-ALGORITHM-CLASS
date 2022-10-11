#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)

// 3주차 상향식 힙

int heap[100000];
int sz = 0;

void push(int x) {
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1) {
		int parent = idx / 2;
		if (heap[parent] < heap[idx]) break;
		int tmp = heap[parent];
		heap[parent] = heap[idx];
		heap[idx] = tmp;
		idx = parent;
	}
}

void heapsort() {
	heap[1] = heap[sz--];
	int idx = 1;
	while (2 * idx <= sz) {
		int lchild = 2 * idx; int rchild = 2 * idx + 1;
		int minchild = lchild;
		if (rchild <= sz && heap[rchild] < heap[lchild])
			minchild = rchild;
		if (heap[idx] < heap[minchild]) break;
		int tmp = heap[idx];
		heap[idx] = heap[minchild];
		heap[minchild] = tmp;
		idx = minchild;
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x); push(x);
	}

	for (int i = 1; i <= n; i++) {
		printf(" %d", heap[1]);
		heapsort();
	}
}