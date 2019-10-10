/*
 * main.c
 *
 *  Created on: Oct 9, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

#define T char
//#define SZ 100
//
//T Stack[SZ];
//int idx = -1;
//
//void push(T i) {
//   if (idx < SZ)
// 	Stack[++idx] = i;
//   else
// 	printf("Stack overflow");
// }
//
//T pop() {
//   if (idx != -1) {
// 	return Stack[idx--];
//   } else {
// 	printf("Stack is empty");
// 	return -1;
//   }
//}

typedef int boolean;
#define true 1
#define false 0

typedef struct Node {
	T data;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} Stack;

boolean push(Stack *st, T value) {
	Node *temp = (Node*) malloc(sizeof(Node));
	if (temp == NULL)
		return false;

	temp->data = value;
	temp->next = st->head;

	st->head = temp;
	st->size++;
	return true;
}

T pop(Stack *st) {
	if (st->size == 0) {
		return -1;
	}

	Node *temp = st->head;
	T result = st->head->data;

	st->head = st->head->next;
	st->size--;
	free(temp);
	return result;
}

int main(int argc, const char** argv) {

	Stack s;
	s.size = 0;
	s.head = NULL;

	push(&s, 'a');
	push(&s, 'b');
	push(&s, 'c');
	push(&s, 'd');
	push(&s, 'e');
	push(&s, 'f');
	push(&s, 'g');
	push(&s, 'h');

	while (s.size > 0) {
		printf("%c ", pop(&s));
	}
	printf("\n");

	return 0;
}
