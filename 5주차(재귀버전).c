#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
// 5���� ������

int ans;

void find(int *arr, int st, int en, int key) {
	int mid = (st + en) / 2;
	if (arr[mid] <= key)
		ans = mid; // ������ ����ū���̴ϱ�..
	if (st >= en) return; // base condition ���⿡ �������� �񱳰��ȵȴ�..
	if (arr[mid] < key) find(arr, mid + 1, en, key);
	else if (arr[mid] > key) find(arr, st, mid - 1, key);
}

int main() {
	int n, key; scanf("%d %d", &n, &key);
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	find(arr, 0, n - 1, key); // n -1�� �ָ�
	if (arr[0] > key) printf(" -1\n");
	else printf(" %d\n", ans);
} 