#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
// 4���� ������

int heap[100000];
int sz = 0;

void push(int x) {
	heap[++sz] = x; // �� �迭�� ������ ����
	int idx = sz;
	while (idx != 1) {
		int parent = idx / 2; // �θ��� // ���� IDX�� SZ�� ��������..
		if (heap[parent] < heap[idx]) break; // ���� ������Ű�� ����
		int tmp = heap[parent];
		heap[parent] = heap[idx];
		heap[idx] = tmp; // ����
		idx = parent; // �ݺ�
	}
}

void pop() {
	heap[1] = heap[sz--]; // ����
	int idx = 1;
	// idx * 2�� sz���� ũ�ٴ� ���� �ش� ��尡 �ܸ������ ��
	while (2 * idx <= sz) {
		int lc = 2 * idx; int rc = 2 * idx + 1;
		int min_c = lc;
		if (rc <= sz && heap[lc] > heap[rc]) min_c = rc;
		if (heap[idx] <= heap[min_c]) break;
		int tmp = heap[idx];
		heap[idx] = heap[min_c];
		heap[min_c] = tmp; // �������鼭 �� ����
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