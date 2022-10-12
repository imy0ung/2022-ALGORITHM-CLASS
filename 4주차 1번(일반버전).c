#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)

// 4주차 합병정렬

int arr[100000];
int tmp[100000];

void merge(int st, int en) {
	int mid = (st + en) / 2;
	int lidx = st; int ridx = mid;
	for (int i = st; i < en; i++) {
		if (lidx >= mid) tmp[i] = arr[ridx++];
		else if (ridx >= en) tmp[i] = arr[lidx++];
		else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
		else tmp[i] = arr[ridx++];
	}
	for (int i = st; i < en; i++)
		arr[i] = tmp[i];
}

void mergeSort(int st, int en) {
	if (st + 1 >= en) return; // base condition
	int mid = (st + en) / 2;
	mergeSort(st, mid);
	mergeSort(mid, en);
	merge(st, en);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	mergeSort(0, n);
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
}