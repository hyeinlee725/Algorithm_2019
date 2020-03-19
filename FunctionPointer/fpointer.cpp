#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

int list[MAX_SIZE];
int n;

int ascend(int x, int y)
{
	if (x > y) 
		return TRUE;
	else 
		return FALSE;
}
int descend(int x, int y)
{
	if (x < y) 
		return TRUE;
	else 
		return FALSE;
}

void insertion_sort(int list[], int n, int(*f)(int, int))
{
	int i, j;

	int key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && f(list[j], key); j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}
int main()
{
	int i;
	int list[MAX_SIZE];
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)         // 난수 생성 및 출력 
		list[i] = rand() % 100;
	insertion_sort(list, n, ascend);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
