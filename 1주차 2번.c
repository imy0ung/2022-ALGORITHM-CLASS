#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)

// 1주차 삽입정렬

int main() {
	int n; scanf("%d", &n);
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i < n; i++) {
		for (int j = i; j >= 1; j--) {
			if (arr[j] <= arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
			else
				break;
		}
	}

	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
}