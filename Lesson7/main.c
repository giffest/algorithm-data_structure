/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
  int data;
  int used;
  List *children;
} GraphNode;

int widthTravers(GraphNode *start, GraphNode *stop) {
  pushQueue(queue, start);
  start->used = 1;
  while (queue->size != 0) {
	GraphNode current = popQueue(queue);
	if (current->data == stop->data)
	  return 1;

	int i;
	for (i = 0; i < children->size; i++) {
	  if (children[i].used != 1) {
		pushQueue(queue, children.get(i));
		get(children, i).used = 1;
	  }
	}
  }
}

const int width = 9;
const int height = 8;
const int OBSTACLE = -1;
const int UNVISITED = -2;
int graph[height][width];
int len;
int pointX[height * width];
int pointY[height * width];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int lee(int sx, int sy, int ex, int ey) {
  int x, y, vector, distance, stop;
  if (sx == ex && sy == ey) return 0;
  if (graph[sy][sx] == OBSTACLE || graph[ey][ex] == OBSTACLE) return 0;

  distance = 0;
  graph[sy][sx] = distance;
  do {
	stop = 1;
	for (y = 0; y < height; y++) {
	  for (x = 0; x < width; x++) {
		if (graph[y][x] == distance) {
		  for (vector = 0; vector < 4; vector++) {
			int newX = x + dx[vector];
			int newY = y + dy[vector];
			if (newX >= 0 && newX < width &&
				newY >= 0 && newY < height &&
				graph[newY][newX] == UNVISITED) {
			  stop = 0;
			  graph[newY][newX] = distance + 1;
			}
		  }
		}
	  }
	}
	distance++;
  } while (!stop && graph[ey][ex] == UNVISITED);

  if (graph[ey][ex] == UNVISITED) return 0;

  len = graph[ey][ex];
  x = ex;
  y = ey;
  while (distance > 0) {
	pointX[distance] = x;
	pointY[distance] = y;
	distance--;
	for (vector = 0; vector < 4; vector++) {
	  int newX = x + dx[vector];
	  int newY = y + dy[vector];
	  if (newX >= 0 && newX < width &&
		  newY >= 0 && newY < height &&
		  graph[newY][newX] == distance) {
		x = newX;
		y = newY;
	  }
	}
  }
  return 1;
}

int main(int argc, const char** argv) {
  lee(2, 3, 6, 5);
  return 0;
}


