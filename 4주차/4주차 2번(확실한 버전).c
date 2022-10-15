#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
// 4주차 퀵정렬

void quickSort(int* arr, int st, int en) {
	if (st + 1 >= en) return; // base condition
	int pivot = arr[st]; // 피벗값 설정
	int lc = st + 1; int rc = en - 1; // lc rc 설정
	// lc는 피벗 바로 앞에!
	while (1) {
		while (lc <= rc && arr[lc] <= pivot) lc++; // 피벗 기준으로 작은거 디텍팅
		while (lc <= rc && arr[rc] >= pivot) rc--; // 피벗 기준으로 큰거 디텍팅
		if (lc > rc) break; // 서로 교차되면 break
		int tmp = arr[lc];
		arr[lc] = arr[rc];
		arr[rc] = tmp; // 서로 값 교환
	}
	// 피벗값과 rc값 교체
	int tmp = arr[rc];
	arr[rc] = arr[st];
	arr[st] = tmp;
	// 피벗값을 기준으로 퀵소트 시행
	quickSort(arr, st, rc); // st부터 rc-1까지
	quickSort(arr, rc + 1, en); // rc+1부터 en -1 까지
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
