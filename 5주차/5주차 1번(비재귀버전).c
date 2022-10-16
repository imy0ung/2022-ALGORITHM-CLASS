#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
// 5ÁÖÂ÷ ÄüÁ¤·Ä

int ans;

int main() {
	int n, key; scanf("%d %d", &n, &key);
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int st = 0; int en = n - 1;
	while (1) {
		int mid = (st + en) / 2;
		if (arr[mid] >= key)
			ans = mid;
		if (st >= en) break;
		if (arr[mid] < key)
			st = mid + 1;
		else if (arr[mid] > key)
			en = mid - 1;
	}
	if (key > arr[n - 1])
		printf(" %d", n);
	else
		printf(" %d", ans);
} 
