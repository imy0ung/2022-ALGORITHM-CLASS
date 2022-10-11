#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)

// 1ÁÖÂ÷ ¼±ÅÃÁ¤·Ä

int main() {
	int n; scanf("%d", &n);
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = n - 1; i >= 1; i--) {
		int max = i;
		for (int j = 0; j <= i; j++) {
			if (arr[j] >= arr[max]) {
				int tmp = arr[j];
				arr[j] = arr[max];
				arr[max] = tmp;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
}
