#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4 //

int knuth_min(int cost[][MAX_SIZE], int root[][MAX_SIZE], int i, int j) {
	for (i = 0; i < MAX_SIZE; i++) {
		if (cost[0][i] + cost[i][MAX_SIZE] < cost[0][i + 1] + cost[i + 1][MAX_SIZE])
			j = i;
		else if (cost[0][i] + cost[i][MAX_SIZE] > cost[0][i + 1] + cost[i + 1][MAX_SIZE])
			j = i + 1;
	}
	return j;//Tij�� k�� ��ȯ�Ѵ�.
}

void obst(int p[], int q[], int cost[][MAX_SIZE], int root[][MAX_SIZE], int weight[][MAX_SIZE], int n)
{
	/*n���� ���� �ٸ� �ĺ��� a[1]...a[n]�� Ȯ�� p[1]...p[n] �׸��� q[0]...q[n]�� �־����� ��,
	a[i]...a[j]�� ���� ���� ���� Ʈ���� ��� c[i][j](1<=i<=j<n)�� ����Ѵ�.
	�� Ʈ���� ����ġ�� ��Ʈ�� ����Ѵ�.*/
	int i, j, k, m, min, minpos;
	/*0 �Ǵ� 1���� ��带 ���� Ʈ���� �ʱ�ȭ*/
	for (i = 0; i < n; i++) {
		weight[i][i] = q[i];
		root[i][i] = 0;
		cost[i][i] = 0;
		cost[i][i + 1] = weight[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
		root[i][i + 1] = i + 1;
	}
	weight[n][n] = q[n];
	root[n][n] = 0;
	cost[n][n] = 0;
	/*������ �밢���� ���� ����Ѵ�.*/
	for (m = 2; m <= n - m; m++)
		for (i = 0; i <= n - m; i++) {
			j = i + m;
			weight[i][j] = weight[i][j - 1] + p[j] + q[j];
			/*knuth_min�� Tij�� k�� ��ȯ�Ѵ�.
			�� ��, cost[i][k-1] + cost[k][j]�� �ּҰ� �ȴ�.*/
			k = knuth_min(cost, root, i, j);
			cost[i][j] = weight[i][j] + cost[i][k - 1] + cost[k][j];
			root[i][j] = k;
		}
}