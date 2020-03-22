#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 6;
int w[] = { 0, 2, 10, 13, 17, 22, 42 };
int W = 52;
bool include[7];//true or false�� ǥ���ϱ� ���� bool type���� ��

bool promising(int i, int weight, int total) {//������ �Ϳ� ���� ���ǽ�
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);//������ && (�ش�||������)
}

void sum_of_subset(int i, int weight, int total) { //�κ� ������ ��
	if (promising(i, weight, total))
	{
		if (weight == W)
		{
			for (int j = 0; j <= i; j++)
			{
				if (include[j])
				{
					printf(" item %d ", j);
				}
			}
			printf("\n");
		}

		else // �������� ������ �ȵ����� ������� �׻� 2���� �־����
		{
			include[i + 1] = true;
			sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = false;
			sum_of_subset(i + 1, weight, total - w[i + 1]);
		}
	}
}

int main(void) {
	int total = 0;
	for (int i = 1; i <= 6; i++)
		total += w[i];
	sum_of_subset(0, 0, total);
	return 0;
}
/*
item 2,item 6,
item 3,item 4,item 5,
Press any key to continue
*/
