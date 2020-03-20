#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define MAX_LIST_SIZE			101
# define MEDIAN					MAX_LIST_SIZE/2
int sort[MAX_LIST_SIZE];
int list[MAX_LIST_SIZE];

void randnum()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < MAX_LIST_SIZE; i++) 
	{
		list[i] = rand() % MAX_LIST_SIZE + 1;
		printf("%d ", list[i]);
	}
	printf("\n");
}

int partition(int list[], int left, int right) 
{
	int pivot, low, high, l, h;
	pivot = (left + right) / 2;
	low = left;
	high = right;
	l = low;
	h = high;

	do {
		if (list[low] <= list[pivot])
			sort[l++] = list[low++];
		else
			sort[h--] = list[low++];
	} while (low < pivot);

	do {
		if (list[high] <= list[pivot])
			sort[l++] = list[high--];
		else
			sort[h--] = list[high--];
	} while (high > pivot);

	sort[l] = list[pivot];
	for (int i = 0; i <= right; i++)
		list[i] = sort[i];

	if (MEDIAN == l)
	{
		return list[l];
	}
		
	else 
	{
		if (l < MEDIAN) 
			return partition(list, l, right);
		else 
			return partition(list, left, l);
	}
}


int main() {
	int m;
	randnum();
	m = partition(list, 0, MAX_LIST_SIZE - 1);
	printf("Median : %d\n", m);
	return 0;
}