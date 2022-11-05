#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int M, n;

int my_hash(int x) {
	return (M + x % M) % M;
}

void insert(int x, int* hashTable) {
	int idx = my_hash(x);
	int ridx = 0; int cnt = 0;
	while (1) {
		ridx = idx % M; // 큐처럼 인덱스를 갱신해줘야함
		if (hashTable[ridx] == 0) {
			hashTable[ridx] = x;
			for (int i = 0; i < cnt; i++)
				printf("C"); // 충돌이 일어난 횟수만큼
			printf("%d\n", ridx);
			return;
		}
		else {
			idx++;
			cnt++;
		}
	}
}

void search(int x, int* hashTable) {
	int idx = my_hash(x);
	int ridx = 0;
	while (1) {
		ridx = idx % M;
		if (hashTable[ridx] == 0) {
			printf("-1\n");
			return; // 찾지 못한 상황
		}
		else if (hashTable[ridx] == x) {
			printf("%d %d\n", ridx, hashTable[ridx]);
			return; // 찾은 상황
		}
		else idx++;
	}
	printf("-1\n");
}

int main() {
	scanf("%d %d", &M, &n);
	int* hashTable = (int*)calloc(M, sizeof(int));

	while (1) {
		getchar();
		char com; int x; scanf("%c", &com);

		if (com == 'i') {
			scanf("%d", &x);
			insert(x, hashTable);
		}
		if (com == 's') {
			scanf("%d", &x);
			search(x, hashTable);
		}
		if (com == 'e')
			break;
	}
}