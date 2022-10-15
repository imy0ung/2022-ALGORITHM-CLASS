#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
// 4���� ������

void quickSort(int* arr, int st, int en) {
	if (st + 1 >= en) return; // base condition
	int pivot = arr[st]; // �ǹ��� ����
	int lc = st + 1; int rc = en - 1; // lc rc ����
	// lc�� �ǹ� �ٷ� �տ�!
	while (1) {
		while (lc <= rc && arr[lc] <= pivot) lc++; // �ǹ� �������� ������ ������
		while (lc <= rc && arr[rc] >= pivot) rc--; // �ǹ� �������� ū�� ������
		if (lc > rc) break; // ���� �����Ǹ� break
		int tmp = arr[lc];
		arr[lc] = arr[rc];
		arr[rc] = tmp; // ���� �� ��ȯ
	}
	// �ǹ����� rc�� ��ü
	int tmp = arr[rc];
	arr[rc] = arr[st];
	arr[st] = tmp;
	// �ǹ����� �������� ����Ʈ ����
	quickSort(arr, st, rc); // st���� rc-1����
	quickSort(arr, rc + 1, en); // rc+1���� en -1 ����
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