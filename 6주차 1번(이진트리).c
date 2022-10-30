#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

node* root; int flag = 0;
// 트리는 재귀..
node* insert(node* root, int data) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node)); // 데이터 할당
		root->right = root->left = NULL;
		root->data = data;
		return root;
	} // 
	if (data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	
	return root;
}

node* fMin(node* root) {
	node* min = root;
	while (min->left != NULL)
		min = min->left;
	return min;
}

node* Delete(node* root, int data) {
	node* tmproot = NULL;
	if (root == NULL)
		return NULL; // base condition
	if (data < root->data)
		root->left = Delete(root->left, data); // 남은거 대입해주는 역할
	else if (data > root->data)
		root->right = Delete(root->right, data); // 과연 데이터 할당이 되는가? = 개념이해하고 넘어가기
	// 해당 노드를 찾는다.
	else {
		// 자식이 두 개 일때
		if (root->left != NULL && root->right != NULL) {
			tmproot = fMin(root->right); // 오른쪽 자식 중 왼쪽으로 계속 간 녀석
			root->data = tmproot->data;
			root->right = Delete(root->right, tmproot->data); // 밑에 자식에도 접근해서 삭제 진행
		}
		else {
			// 자식이 하나거나 없을 때
			tmproot = (root->left == NULL) ? root->right : root->left; // 오른쪽이 빈지, 왼쪽이 빈지
			free(root);
			return tmproot; // 반환해서 재귀함수를 통해 대입
		}
	}
	return root;
}

void search(node* root, int key) {
	if (root == NULL) {
		flag = 1;
		printf("X\n");
		return;
	}
	if (key < root->data)
		search(root->left, key);
	else if (key > root->data)
		search(root->right, key);
	else {
		printf("%d\n", root->data);
		return;
	}
}

void print(node* root)
{
	if (root == NULL)
		return;
	printf(" %d", root->data);
	print(root->left);
	print(root->right);
}

int main() {
	char com; int x;

	while (1) {
		flag = 0;
		scanf("%c", &com);
		
		if (com == 'i') {
			scanf("%d", &x);
			root = insert(root, x);
		}
		if (com == 'd') {
			scanf("%d", &x);
			search(root, x);
			if (flag != 1)
				root = Delete(root, x); // 왜 root로?  만약 다 빈 경우, NULL값을 넣어줘야함
		}
		if (com == 's') {
			scanf("%d", &x);
			search(root, x);
		}
		if (com == 'p') {
			print(root);
			printf("\n");
		}
		if (com == 'q')
			break;
	}
	return 0;
}
