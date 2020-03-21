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
	return j;//Tij의 k를 반환한다.
}

void obst(int p[], int q[], int cost[][MAX_SIZE], int root[][MAX_SIZE], int weight[][MAX_SIZE], int n)
{
	/*n개의 서로 다른 식별자 a[1]...a[n]과 확률 p[1]...p[n] 그리고 q[0]...q[n]이 주어졌을 때,
	a[i]...a[j]에 대한 최적 이진 트리의 비용 c[i][j](1<=i<=j<n)를 계산한다.
	그 트리의 가중치와 루트도 계산한다.*/
	int i, j, k, m, min, minpos;
	/*0 또는 1개의 노드를 가진 트리를 초기화*/
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
	/*나머지 대각선에 대해 계산한다.*/
	for (m = 2; m <= n - m; m++)
		for (i = 0; i <= n - m; i++) {
			j = i + m;
			weight[i][j] = weight[i][j - 1] + p[j] + q[j];
			/*knuth_min은 Tij의 k를 반환한다.
			이 때, cost[i][k-1] + cost[k][j]는 최소가 된다.*/
			k = knuth_min(cost, root, i, j);
			cost[i][j] = weight[i][j] + cost[i][k - 1] + cost[k][j];
			root[i][j] = k;
		}
}