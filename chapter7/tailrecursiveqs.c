// Tail Recursive Quicksort Program Implementation
// Tail Recursive Version is more efficient because of no extra stack calls and previous stack frames can be used again repeatedly
// In Place Sorting Algorithm
// Worst Case Running Time: O(n^2), but in most cases its expected run time is: (nlgn)
// Expected time running is faster compared to Heap Sort and Merge Sort (both of them also run in nlgn but quicksort's hidden constants are much smaller)
// Last element is taken as pivot


#include <stdio.h>
#include <stdlib.h>


int partition(int array[], int startindex, int endindex);
void trquicksort(int array[], int startindex, int endindex);

int main() {
	int *numberlist, n, i;
	printf("Enter the number of elements in your list: ");
	scanf("%d", &n);
	numberlist = (int *)malloc(n * sizeof(int));
	printf("Enter the numbers: \n");
	for(i = 0; i < n; i++)
		scanf("%d", &numberlist[i]);
	trquicksort(numberlist, 0, n - 1);
	for(i = 0; i < n; i++) {
		printf("%d ", numberlist[i]);
	}
	printf("\n");
	return 0;
}

int partition(int a[], int p, int r) {
	int pivot, i, j, temp;
	pivot = a[r];
	i = p - 1;
	for(j = p; j < r; j++) {
		if(a[j] <= pivot) {
			i = i + 1;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	temp = a[i + 1];
	a[i + 1] = a[r]; 
	a[r] = temp;
	return (i + 1);
}

void trquicksort(int a[], int p, int r) {
	int q;
	while (p < r) {
		q = partition(a, p, r);
		trquicksort(a, p, q - 1);
		p = q + 1;
	}
	return;
}
