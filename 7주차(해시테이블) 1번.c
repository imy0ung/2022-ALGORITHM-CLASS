#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

// Loadfactor = �����ǰ���/���̺���ũ��
// Loadfactor <= 1(Chaining), Loadfactor <= 0.75(Open addressing)

// chaining
// 1. ����ü�� hashtable �����.
// 2. insert���� ����Ʈ ������.
// 3. delete ���� ����Ʈ ����
// 4. print�� �ణ Ư���ѵ�, �ִ°Ÿ� ����ϴ� ����

typedef struct node {
	int id;
	struct node* next;
}node;

int M;

int my_hash(int x, int M) {
	return (M + x % M) % M; // ������ ��� ����������.
}

void insert(node* hashTable, int x) {
	node* p = hashTable + my_hash(x, M); // �ش���ġ�� ����
	node* newnode = (node*)malloc(sizeof(node));
	newnode->id = x;
	newnode->next = NULL;

	if (p->next == NULL)
		p->next = newnode; // ������ �־��ְ�
	else {
		newnode->next = p->next; // ����Ʈ�� �־��ֱ�
		p->next = newnode;
	}
} // o(1)

int search(int x, node* hashtable) {
	node* p = hashtable + my_hash(x, M);
	int searchNum = 0;
	if (p->next == NULL)
		return 0; // �ش��尡 ��������� ���� ����
	else {
		while (1) {
			p = p->next;
			searchNum++; 
			if (p->id == x)
				return searchNum; // ã���� ��ȯ
			if (p->next == NULL)
				return 0; // ������ ���� ����
		}
	}
	return 0;
}

int Delete(int x, node* hashTable) {
	node* p = hashTable + my_hash(x, M);
	node* q = p;
	int deleteNum = 0;
	if (p->next == NULL)
		return 0; // ��������� ���� ��
	while (1) {
		p = p->next;
		deleteNum++;
		if (p->id == x) {
			// ����Ʈ ���� ����
			while (q->next != p)
				q = q->next; // ���� ������ detecting
			q->next = p->next; 
			free(p);
			return deleteNum;
		}
		if (p->next == NULL)
			return 0;
	}
	return 0;
}

void print(node* hashTable) {
	struct node* p;
	for (int i = 0; i < M; i++) {
		p = hashTable + i; // M���� ����Ʈ���� i��° hashtable����
		if (p->next != NULL) { // ������ ���
			p = p->next;
			printf(" %d", p->id); 
			while (p->next != NULL) {
				p = p->next;
				printf(" %d", p->id);
			}
		}
	}
	printf("\n");
}

int main() {
	scanf("%d", &M);
	node* hashTable = (node*)malloc(sizeof(node) * M);

	for (int i = 0; i < M; i++) {
		(hashTable + i)->next = NULL; // hashtable �ʱ�ȭ
	}

	while (1) {
		char com; int x;
		getchar();
		scanf("%c", &com);

		if (com == 'i') {
			scanf("%d", &x);
			insert(hashTable, x);
		}
		if (com == 's') {
			scanf("%d", &x);
			printf("%d\n", search(x, hashTable));
		}
		if (com == 'd') {
			scanf("%d", &x);
			printf("%d\n", Delete(x, hashTable));
		}
		if (com == 'p') {
			print(hashTable);
		}
		if (com == 'e') {
			break;
		}
	}
	return 0;
}