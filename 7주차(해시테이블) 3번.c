#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int M, n, q;

//double hashing - clustering을 방지하기 위해 새로운
// 해시 함수를 둔 것.

int my_hash(int x) {
	return (M + x % M) % M;
}

int doubleHash(int x) {
	return q - (x % q);
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
			idx += doubleHash(x);
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
		else idx += doubleHash(x);
	}
	printf("-1\n");
}

void print(int* hashTable) {
	for (int i = 0; i < M; i++)
		printf(" %d", hashTable[i]);
	printf("\n");
}

int main() {
	scanf("%d %d %d", &M, &n, &q);
	int* hashTable = (int*)calloc(M,sizeof(int));

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
		if (com == 'p')
			print(hashTable);
		if (com == 'e') {
			print(hashTable);
			break;
		}
	}
}