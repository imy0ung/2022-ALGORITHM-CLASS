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
// Ʈ���� ���..
node* insert(node* root, int data) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node)); // ������ �Ҵ�
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
		root->left = Delete(root->left, data); // ������ �������ִ� ����
	else if (data > root->data)
		root->right = Delete(root->right, data); // ���� ������ �Ҵ��� �Ǵ°�? = ���������ϰ� �Ѿ��
	// �ش� ��带 ã�´�.
	else {
		// �ڽ��� �� �� �϶�
		if (root->left != NULL && root->right != NULL) {
			tmproot = fMin(root->right); // ������ �ڽ� �� �������� ��� �� �༮
			root->data = tmproot->data;
			root->right = Delete(root->right, tmproot->data); // �ؿ� �ڽĿ��� �����ؼ� ���� ����
		}
		else {
			// �ڽ��� �ϳ��ų� ���� ��
			tmproot = (root->left == NULL) ? root->right : root->left; // �������� ����, ������ ����
			free(root);
			return tmproot; // ��ȯ�ؼ� ����Լ��� ���� ����
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
				root = Delete(root, x); // �� root��?  ���� �� �� ���, NULL���� �־������
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
