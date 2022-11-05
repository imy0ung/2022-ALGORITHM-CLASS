#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int M, n, q;

//double hashing - clustering�� �����ϱ� ���� ���ο�
// �ؽ� �Լ��� �� ��.

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
		ridx = idx % M; // ťó�� �ε����� �����������
		if (hashTable[ridx] == 0) {
			hashTable[ridx] = x;
			for (int i = 0; i < cnt; i++)
				printf("C"); // �浹�� �Ͼ Ƚ����ŭ
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
			return; // ã�� ���� ��Ȳ
		}
		else if (hashTable[ridx] == x) {
			printf("%d %d\n", ridx, hashTable[ridx]);
			return; // ã�� ��Ȳ
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