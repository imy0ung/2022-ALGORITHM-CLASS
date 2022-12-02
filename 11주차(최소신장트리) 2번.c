#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning(disable:4996)

// MST (minimum spanning tree)
// Kruscal Algoritm

int n, m;
int p[10000];

typedef struct {
	int v1; int v2; int cost;
}edge;

void sort(edge* arr) {
	for (int i = 0; i < m; i++) {
		for (int j = m - 1; j > 0; j--) {
			if (arr[j].cost < arr[j - 1].cost) {
				edge tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

int find(int x) {
	if (p[x] < 0) return x; // ������ �ȵǾ�����
	return p[x] = find(p[x]); // ����Ǿ��ִٸ� ���� �θ� ã��
}

bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0; // ���ٸ� �θ� �����Ű� cycle�� ������
	else if (u < v) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	edge* graphData = (edge*)calloc(m, sizeof(edge));

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &graphData[i].v1, &graphData[i].v2, &graphData[i].cost);
	}
	sort(graphData);
	for (int i = 0; i < n; i++)
		p[i] = -1;
	int cnt = 0; int ans = 0;
	for (int i = 0; i < m; i++) {
		int a = graphData[i].v1;
		int b = graphData[i].v2;
		int c = graphData[i].cost;
		if (!is_diff_group(a, b)) continue; // ���� ���� �׷��̸�
		printf(" %d", c);
		ans += c; cnt++;
		if (cnt == n - 1) break; // �ּҽ���Ʈ���� v-1���� �������� �̷��������
	}
	printf("\n%d", ans);
}