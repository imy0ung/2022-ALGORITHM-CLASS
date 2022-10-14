#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)

// 4���� ������

void quickSort(int* arr, int st, int en) {
	if (st + 1 >= en) return;
	int pivot = st;
	int lchild = st + 1; int rchild = en - 1;

	while (1) {
		while (lchild <= rchild && arr[pivot] >= arr[lchild]) lchild++; //pivot���� ū�� detecting
		while (lchild <= rchild && arr[pivot] <= arr[rchild]) rchild--; //pivot���� ������ detecting
		if (lchild > rchild) break; // l�� r�� ������ ���� break
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