#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
// 5주차 퀵정렬

int ans;

void find(int *arr, int st, int en, int key) {
	int mid = (st + en) / 2;
	if (arr[mid] <= key)
		ans = mid; // 어차피 가장큰값이니까..
	if (st >= en) return; // base condition 여기에 마지막에 비교가안된다..
	if (arr[mid] < key) find(arr, mid + 1, en, key);
	else if (arr[mid] > key) find(arr, st, mid - 1, key);
}

int main() {
	int n, key; scanf("%d %d", &n, &key);
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	find(arr, 0, n - 1, key); // n -1에 주목
	if (arr[0] > key) printf(" -1\n");
	else printf(" %d\n", ans);
} 
