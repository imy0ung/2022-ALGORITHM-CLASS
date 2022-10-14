#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)

// 4주차 퀵정렬

void quickSort(int* arr, int st, int en) {
	if (st + 1 >= en) return;
	int pivot = st;
	int lchild = st + 1; int rchild = en - 1;

	while (1) {
		while (lchild <= rchild && arr[pivot] >= arr[lchild]) lchild++; //pivot보다 큰거 detecting
		while (lchild <= rchild && arr[pivot] <= arr[rchild]) rchild--; //pivot보다 작은거 detecting
		if (lchild > rchild) break; // l과 r이 교차한 순간 break
		int tmp = arr[lchild];
		arr[lchild] = arr[rchild];
		arr[rchild] = tmp;
	}
	int tmp = arr[rchild];
	arr[rchild] = arr[pivot];
	arr[pivot] = tmp;

	quickSort(arr, st, rchild);
	quickSort(arr, rchild + 1, en); // *
}


int main() {
	int n; scanf("%d", &n);
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	quickSort(arr, 0, n);
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
}