#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

// Loadfactor = 원소의개수/테이블의크기
// Loadfactor <= 1(Chaining), Loadfactor <= 0.75(Open addressing)

// chaining
// 1. 구조체로 hashtable 만든다.
// 2. insert에서 리스트 원리로.
// 3. delete 역시 리스트 개념
// 4. print가 약간 특이한데, 있는거만 출력하는 거임

typedef struct node {
	int id;
	struct node* next;
}node;

int M;

int my_hash(int x, int M) {
	return (M + x % M) % M; // 음수인 경우 고려해줘야함.
}

void insert(node* hashTable, int x) {
	node* p = hashTable + my_hash(x, M); // 해당위치에 접근
	node* newnode = (node*)malloc(sizeof(node));
	newnode->id = x;
	newnode->next = NULL;

	if (p->next == NULL)
		p->next = newnode; // 없으면 넣어주고
	else {
		newnode->next = p->next; // 리스트로 넣어주기
		p->next = newnode;
	}
} // o(1)

int search(int x, node* hashtable) {
	node* p = hashtable + my_hash(x, M);
	int searchNum = 0;
	if (p->next == NULL)
		return 0; // 해당노드가 비어있으면 없는 거임
	else {
		while (1) {
			p = p->next;
			searchNum++; 
			if (p->id == x)
				return searchNum; // 찾으면 반환
			if (p->next == NULL)
				return 0; // 없으면 없는 거임
		}
	}
	return 0;
}

int Delete(int x, node* hashTable) {
	node* p = hashTable + my_hash(x, M);
	node* q = p;
	int deleteNum = 0;
	if (p->next == NULL)
		return 0; // 비어있으면 없는 것
	while (1) {
		p = p->next;
		deleteNum++;
		if (p->id == x) {
			// 리스트 삭제 구현
			while (q->next != p)
				q = q->next; // 이전 노드까지 detecting
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
		p = hashTable + i; // M개의 리스트에서 i번째 hashtable접근
		if (p->next != NULL) { // 있으면 출력
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
		(hashTable + i)->next = NULL; // hashtable 초기화
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