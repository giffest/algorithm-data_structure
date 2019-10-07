/*
 * main.c
 *
 *  Created on: Oct 1, 2019
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

// Линейный поиск в массиве
int linearSearch(int* arr, int len, int value) {
	int i = 0;
	while (i < len && arr[i] != value) {
		count++;
		i++;
	}
  return (i == len) ? -1 : i;
}

// Линейный поиск с барьером
int linearSearchFlag(int* arr, int len, int value) {
	int i = 0;
	arr[len+1] = value; // выход: достигли i == len - не нашли значение
	while (arr[i] != value) {
		count++;
		i++;
	}
	return (i == len+1) ? -1 : i;
}

// Пузырьковая сортировка
void swap(int *a, int *b) {
//	*a ^= *b;
//	*b ^= *a;
//	*a ^= *b;

	int t = *a;
	*a = *b;
	*b = t;
}

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

// Сортировка методом выбора
void pickSort(int* arr, int len) {
	int i;
	int j;
	for (i = 0; i < len; i++) {
		int flag = i;
		for (j = i + 1; j < len; j++) {
			count++;
			if (arr[j] < arr[flag]) {
				count++;
				flag = j;
			}
		}
		swap(&arr[i], &arr[flag]);
  }
}

// Сортировка вставками
void insSort(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		count++;
		int temp = arr[i];
		int j = i;
		while (j > 0 && arr[i - 1] > temp) {
			count++;
			swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}

// Поиск методом половинного деления
int binarySearch(int* arr, int len, int value) {
	int left = 0;
	int right = len - 1;
	int mid = (left + right) / 2;
	while (left <= right && arr[mid] != value) {
		count++;
		if (arr[mid] < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	if (arr[mid] == value)
		return mid;
	else
		return -1;
}

// Интерполяционный поиск
int interpolationSearch(int* arr, int len, int value) {
    int min = 0;
    int max = len - 1;
    while (min < max) {
    	count++;
        int mid = min + (max - min) * abs((value - arr[min])) / (arr[max] - arr[min]);
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value) {
            min = mid + 1;
        }
        else if (arr[mid] > value) {
            max = mid - 1;
        }
    }
    return - 1;
}


int main(int argc, const char** argv) {
	srand(time(NULL));
	int SIZE = 53;
	int arr[SIZE];
	fillArray(arr, SIZE);
	printArray(arr, SIZE);

	int ind = linearSearch(arr, SIZE, 9);
	printf("index = %d\n", ind);
	printf("Count1:%d\n", count);

	count = 0;
	int ind2 = linearSearchFlag(arr, SIZE, 9);
	printf("index2 = %d\n", ind2);
	printf("Count2:%d\n", count);

	count = 0;
	bubbleSort(arr, SIZE);
	printArray(arr, SIZE);
	printf("Count3:%d\n", count);

	count = 0;
	pickSort(arr, SIZE);
	printArray(arr, SIZE);
	printf("Count4:%d\n", count);

	count = 0;
	insSort(arr, SIZE);
	printArray(arr, SIZE);
	printf("Count5:%d\n", count);

	count = 0;
	printf("index3 = %d\n", binarySearch(arr, SIZE, 23));
	printf("Count6:%d\n", count);

	count = 0;
	printf("index4 = %d\n", interpolationSearch(arr, SIZE, 23));
	printf("Count7:%d", count);

    return 0;
}
