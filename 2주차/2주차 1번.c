#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)

// 2ÁÖÂ÷ »ðÀÔ½Ä Èü

int heap[100000];
int sz = 0;

void push(int x) {
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1) {
		int parent = idx / 2;
		if (heap[parent] > heap[idx]) break;
		int tmp = heap[parent];
		heap[parent] = heap[idx];
		heap[idx] = tmp;
		idx = parent;
	}
}

void del() {
	heap[1] = heap[sz--];
	int idx = 1;
	while (2 * idx <= sz) {
		int lchild = 2 * idx; int rchild = 2 * idx + 1;
		int max_child = lchild;
		if (rchild <= sz && heap[lchild] < heap[rchild]) {
			max_child = rchild;
		}
		if (heap[max_child] < heap[idx]) break;
		int tmp = heap[max_child];
		heap[max_child] = heap[idx];
		heap[idx] = tmp;

		idx = max_child;
	}
}

int main() {
	while (1) {
		char cmd; scanf("%c", &cmd);

		if (cmd == 'i') {
			int x; scanf("%d", &x);
			getchar();
			printf("0\n");
			push(x);
		}

		if (cmd == 'p') {
			for (int i = 1; i <= sz; i++)
				printf(" %d", heap[i]);
			printf("\n");
		}

		if (cmd == 'd') {
			printf("%d\n", heap[1]);
			del();
		}

		if (cmd == 'q')
			break;
	}
}
