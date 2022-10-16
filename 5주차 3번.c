#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
// 6주차 사전

int main() {
	int a, b, n; scanf("%d %d %d", &a, &b, &n);
	getchar();
	while (n--) {
		char com; scanf("%c", &com);
		int mid = (a + b) / 2;
		if (com == 'Y') a = mid + 1;
		else if (com == 'N') b = mid;
		if (a == b) {
			printf("%d\n", a);
			break;
		} 
	}
} 