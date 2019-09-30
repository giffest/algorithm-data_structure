/*
 * main.c
 *
 *  Created on: Sep 30, 2019
 *     	Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

void cycle(int a, int b) {
  while (a < b) {
	printf("%d ", a);
	a++;
  }
  printf("%d ", a);
}

void loop(int a, int b) {
  printf("%d ", a);
  a++;
  if (a < b) {
	loop(a, b);
  }
  printf("%d ", a);
}

int f(int i) {
  int result = 1;
  while (i > 0) {
	result *= i--;
  }
  return result;
}

int F(int n) {
  if (n == 0)
	return 1;
  return F(n - 1) * n;
}

int operations = 0;
void put(int from, int to) {
  printf("%d -> %d | ", from, to);
  if ((++operations % 8) == 0) printf("\n");
}

void hanoi(int from, int to, int n) {
  int temp = from ^ to;
  if (n == 1)
	put(from, to);
  else {
	hanoi(from, temp, n - 1);
	put(from, to);
	hanoi(temp, to, n - 1);
  }
}

int main(int argc, const char** argv) {

	cycle(0, 5);
	printf("\n");
	loop(0, 5);
	printf("\n");

	int disks = 8;
	hanoi(1, 3, disks);
	printf("\nOperations: %d", operations);

    return 0;
}

