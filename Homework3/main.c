/*
 * main.c
 *
 *  Created on: Oct 7, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

int count = 0;
void fillArray(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		arr[i] = rand() % 100;
	}
}

void printArray(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void copyArray(int* arr2, int* arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		arr2[i] = arr[i];
	}
}

// Пузырьковая сортировка
void bubbleSort(int* arr, int len) {
	int i;
	int j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - 1; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				count++;
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void bubbleSortOpt(int* arr, int len) {
	int i;
	int j;
	for (i = 0; i < len; i++) {
		int swapCount = 1;
		for (j = 0; j < len - 1; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				count++;
				swap(&arr[j], &arr[j + 1]);
				swapCount = 0;
			}
		}
		if (swapCount == 1)
			break;
	}
}


void bubbleSortOpt2(int* arr, int len) {
	int i = 0;
	int swapCount = 0;
	while (i < len) {
		count++;
		if (i + 1 != len && arr[i] > arr[i + 1]) {
			count++;
			swap(&arr[i], &arr[i + 1]);
			swapCount = 1;
		}
		i++;
		if (i == len && swapCount == 1) {
			count++;
			i = 0;
			swapCount = 0;
		}
	}
}

// Шейкерная сортировка - Сортировка перемешиванием - Двунаправленная сортировка
void cocktailSort(int* arr, int len) {
	int left = 0;
	int right = len - 1;
	while (left < right) {
		count++;
		for (int i = left; i < right; i++) {
			count++;
			if (arr[i] > arr[i + 1]) {
				count++;
				swap(&arr[i], &arr[i + 1]);
			}
		}
		right--;
		for (int i = right; left < i; i--) {
			count++;
			if (arr[i] < arr[i - 1]) {
				count++;
				swap(&arr[i], &arr[i - 1]);
			}
		}
		left++;
	}
}

// Pigeon Hole сортировка - Сортировка методом подсчета
void pigeonholeSort(int* arr, int len) {
	int i;
	int j;
	int min = arr[0];
	int max = arr[0];
	for (i = 0; i < len; i++) {
		count++;
	    if (arr[i] < min)
	    	min = arr[i];
	    if (arr[i] > max)
	        max = arr[i];
	    }
	int k = max - min + 1;
	int phole[k];
	for(i = 0; i < k; i++) {
		count++;
		phole[i] = 0;
	}
	for(i = 0; i < len; i++) {
		count++;
	    phole[arr[i] - min]++;
	}
	int index = 0;
	for(j = 0; j < k; j++) {
		count++;
	    while(phole[j] --> 0) {
	    	count++;
	    	arr[index++] = j + min;
	    }
	}
}

int main(int argc, const char** argv) {
	srand(t(NULL));
	int SIZE = 53;
	int arr[SIZE], arr2[SIZE], arr3[SIZE], arr4[SIZE], arr5[SIZE];
	fillArray(arr, SIZE);
	printArray(arr, SIZE);
	copyArray(arr2, arr, SIZE);
	copyArray(arr3, arr, SIZE);
	copyArray(arr4, arr, SIZE);
	copyArray(arr5, arr, SIZE);

	printf("Пузырьковая сортировка. Вариант 0\n");
	bubbleSort(arr, SIZE);
	printArray(arr, SIZE);
	printf("Count:%d\n", count);

	printf("Вариант 1\n");
	count = 0;
	bubbleSortOpt(arr2, SIZE);
	printArray(arr2, SIZE);
	printf("Count:%d\n", count);

	printf("Вариант 2\n");
	count = 0;
	bubbleSortOpt(arr3, SIZE);
	printArray(arr3, SIZE);
	printf("Count:%d\n", count);

	printf("Шейкерная сортировка\n");
	count = 0;
	cocktailSort(arr4, SIZE);
	printArray(arr4, SIZE);
	printf("Count:%d\n", count);

	printf("Pigeon Hole сортировка\n");
	count = 0;
	pigeonholeSort(arr5, SIZE);
	printArray(arr5, SIZE);
	printf("Count:%d\n", count);

    return 0;
}
