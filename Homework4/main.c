/*
 * main.c
 *
 *  Created on: Oct 8, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

// 1. *Количество маршрутов с препятствиями. Реализовать чтение массива
// с препятствием и нахождение количество маршрутов
int map[4][5] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
//int map[3][3] = {1, 1, 1, 0, 1, 0, 0, 1, 0};

int routes(int x, int y) {
	if (map[x][y] != 0) {
		if (x == 0 || y == 0)
			if (map[x - 1][y] != 0 || map[x][y - 1] != 0)
				return 1;
			else
				return 0;
		else
			return routes(x - 1, y) + routes(x, y - 1);
	}
	else
		return 0;
}

// Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.
#define X 8
#define Y 8
int board[X][Y];
int moveX[8] = {1, 2, 2, 1, -1, -2, -2, -1}; //2305775 по часовой
int moveY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int moveX[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; //6820545
//int moveY[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
//int moveX[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; //443170521
//int moveY[8] = {2, 1, -1, -2, -2, -1, 1, 2};
//int moveX[8] = {-1, -2, -1, 1, 2, 2, -2, 1}; //1358113823
//int moveY[8] = {2, -1, -2, -2, -1, 1, 1, 2};
//int moveX[8] = {1, -1, -2, -2, -1, 1, 2, 2}; //1882523503
//int moveY[8] = {2, 2, 1, -1, -2, -2, -1, 1};
//int moveX[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; //2305775 против часовой
//int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void printBoard() {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			printf("%4d", board[i][j]);
		}
		printf("\n");
	}
}

int checkKnight(int x, int y) {
	return x >= 0 && x < X && y >= 0 && y < Y && board[x][y] == 0;
}

int operation = 0;
int knight(int row, int col, int step) {
	board[row][col] = step;
	if (step > (X * Y - 1))
		return 1;
	for (int i = 0; i < 7; i++) {
		operation++;
		int rowNew = row + moveX[i];
		int colNew = col + moveY[i];
		if (checkKnight(rowNew, colNew) && knight(rowNew, colNew, step + 1))
			return 1;
	}
	board[row][col] = 0;
	return 0;
}

int main(int argc, const char** argv) {

// Количество маршрутов с препятствиями
	printf("Количество маршрутов с препятствиями\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%5d ", routes(i, j));
		}
		printf("\n");
	}

// Обход конём шахматной доски
	printf("Обход конем шахматной доски\n");
	knight(0, 0, 1);
	printBoard();
	printf("operation: %d\n", operation);

	return 0;
}

