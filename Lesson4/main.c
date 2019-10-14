/*
 * main.c
 *
 *  Created on: Oct 7, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

// Количество маршрутов
int routes(int x, int y) {
	if (x == 0 || y == 0) return 1;
	else return routes(x - 1, y) + routes(x, y - 1);
}

// Наибольшая общая подпоследовательность
//LCS(x*, y*) = 0; if x.len == 0 || y.len == 0
//LCS([x], [y]) = LCS(x* - 1, y* - 1) + 1, if [x] == [y]
//LCS(x*, y*) = max(LCS(x*, y* - 1), LCS(x* - 1, y*)), if [x] != [y]

int lcs_length(char* A, char* B) {

	if (*A == '\0' || *B == '\0')
		return 0;
	else if (*A == *B)
		return 1 + lcs_length(A + 1, B + 1);
	else {
		int x1 = lcs_length(A + 1, B);
		int x2 = lcs_length(A, B + 1);
		return (x1 > x2) ? x1 : x2;
	}
}

// Поиск с возвратом
// Задача о восьми ферзях
#define QUEENS 8
#define X 8
#define Y 8
int board[Y][X];

void annull() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  board[i][j] = 0;
	}
  }
}

void printBoard() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  printf("%3d", board[i][j]);
	}
	printf("\n");
  }
}

int checkQueen(int x, int y) {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  if (board[i][j] != 0)
		if (!(i == x && j == y)) {
		  if (i - x == 0 || j - y == 0)
			return 0;
		  if (abs(i - x) == abs(j - y))
			return 0;
		}
	}
  }
  return 1;
}

int checkBoard() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  if (board[i][j] != 0)
		if (checkQueen(i, j) == 0)
		  return 0;
	}
  }
  return 1;
}

int operations = 0;
int queens(int n) {
  if (checkBoard() == 0) return 0;
  if (n == QUEENS + 1) return 1;
  int row;
  int col;
  for (row = 0; row < Y; row++) {
	for (col = 0; col < X; col++) {
	  operations++;
	  if (board[row][col] == 0) {
		board[row][col] = n;
		if (queens(n + 1))
		  return 1;
		board[row][col] = 0;
	  }
	}
  }
  return 0;
}

int main(int argc, const char** argv) {

// Количество маршрутов
	int i;
	int j;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			printf("%7d ", routes(i, j));
		}
		printf("\n");
	}

// Наибольшая общая подпоследовательность
	char* x = "geekbrains";
	char* y = "geekminds";
	printf("\nlcs length = %d \n", lcs_length(x, y));

// Задача о восьми ферзях
	printf("\n");
	annull();
	queens(1);
	printBoard();
	printf("operations = %d\n", operations);

	return 0;
}
