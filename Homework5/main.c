/*
 * main.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

#define T char
typedef int boolean;
#define true 1
#define false 0

// 1. Программа проверки, является ли введенная скобочная последовательность
// правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
// неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
// Например: (2+(2*2)) или [2/{5*(4+7)}]
char* bracketsСheck(const char *s) {
	switch (*s) {
		case '\0':
		case ')':
		case '}':
		case ']':
        	return (char*)s;
		case '(': {
			char* ret = bracketsСheck(s + 1);
			return (*ret == ')') ? bracketsСheck(ret + 1) : (char*)s;
        }
        case '{': {
            char* ret = bracketsСheck(s + 1);
            return (*ret == '}') ? bracketsСheck(ret + 1) : (char*)s;
        }
        case '[' : {
            char * ret = bracketsСheck(s + 1);
            return (*ret == ']') ? bracketsСheck(ret + 1) : (char*)s;
        }
        default :
            return bracketsСheck(s + 1);
    }
}

// 2. Функция копирования односвязного списка
typedef struct Node {
	T data;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} Stack;

Node* сopyStack(Node *head) {
   Node* current = head;
   Node* newStack = NULL;
   Node* tail = NULL;
   while (current != NULL) {
      if (newStack == NULL) {
    	 newStack = malloc(sizeof(Node));
    	 newStack->data = current->data;
    	 newStack->next = NULL;
         tail = newStack;
      }
      else {
         tail->next = malloc(sizeof(Node));
         tail = tail->next;
         tail->data = current->data;
         tail->next = NULL;
      }
      current = current->next;
   }
   return(newStack);
}

// 3. Очередь на основе двусвязного списка.
typedef struct _Node2 {
    void *data;
    struct _Node2 *next;
    struct _Node2 *prev;
} Node2;

typedef struct _Stack2 {
    size_t size;
    Node2 *head;
    Node2 *tail;
} Stack2;

Stack2* createStack2() {
    Stack2 *temp = (Stack2*) malloc(sizeof(Stack2));
    temp->size = 0;
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

void deleteStack2(Stack2 **st) {
    Node2 *temp = (*st)->head;
    Node2 *next = NULL;
    while (temp) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(*st);
    (*st) = NULL;
}

boolean pushFront(Stack2 *st, void *value) {
    Node2 *temp = (Node2*) malloc(sizeof(Node2));
    if (temp == NULL)
    	return false;

    temp->data = value;
    temp->next = st->head;
    temp->prev = NULL;
    if (st->head)
        st->head->prev = temp;

    st->head = temp;

    if (st->tail == NULL)
        st->tail = temp;

    st->size++;
    return true;
}

void* popFront(Stack2 *st) {
    Node2 *prev;
    void *temp;
    if (st->head == NULL)
    	return false;

    prev = st->head;
    st->head = st->head->next;
    if (st->head)
        st->head->prev = NULL;

    if (prev == st->tail)
        st->tail = NULL;

    temp = prev->data;
    free(prev);

    st->size--;
    return temp;
}

boolean pushBack(Stack2 *st, void *data) {
    Node2 *temp = (Node2*) malloc(sizeof(Node2));
    if (temp == NULL)
    	return false;

    temp->data = data;
    temp->next = NULL;
    temp->prev = st->tail;
    if (st->tail)
        st->tail->next = temp;

    st->tail = temp;

    if (st->head == NULL)
        st->head = temp;

    st->size++;
    return true;
}

void* popBack(Stack2 *st) {
    Node2 *next;
    void *temp;
    if (st->tail == NULL)
    	return false;

    next = st->tail;
    st->tail = st->tail->prev;
    if (st->tail)
        st->tail->next = NULL;

    if (next == st->head)
        st->head = NULL;

    temp = next->data;
    free(next);

    st->size--;
    return temp;
}

Node2* getN(Stack2 *st, size_t index) {
    Node2 *temp = st->head;
    size_t i = 0;
    while (temp && i < index) {
        temp = temp->next;
        i++;
    }
    return temp;
}

Node2* getNitem(Stack2 *st, size_t index) {
    Node2 *temp = NULL;
    size_t i;

    if (index < st->size/2) {
        i = 0;
        temp = st->head;
        while (temp && i < index) {
            temp = temp->next;
            i++;
        }
    } else {
        i = st->size - 1;
        temp = st->tail;
        while (temp && i > index) {
            temp = temp->prev;
            i--;
        }
    }
    return temp;
}

boolean insertItem(Stack2 *st, size_t index, void *data) {
    Node2 *item = NULL;
    Node2 *ins = NULL;
    item = getN(st, index);
    if (item == NULL)
    	return false;

    ins = (Node2*) malloc(sizeof(Node2));
    ins->data = data;
    ins->prev = item;
    ins->next = item->next;
    if (item->next)
        item->next->prev = ins;

    item->next = ins;

    if (!item->prev)
        st->head = item;

    if (!item->next)
        st->tail = item;

    st->size++;
    return true;
}

void* deleteN(Stack2 *st, size_t index) {
    Node2 *item = NULL;
    void *temp = NULL;
    item = getN(st, index);
    if (item == NULL)
    	return false;

    if (item->prev)
        item->prev->next = item->next;

    if (item->next)
        item->next->prev = item->prev;

    temp = item->data;

    if (!item->prev)
        st->head = item->next;

    if (!item->next)
        st->tail = item->prev;

    free(item);
    st->size--;
    return temp;
}

void printStack2(Stack2 *st, void (*fun)(void*)) {
    Node2 *temp = st->head;
    while (temp) {
        fun(temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printInt(void *data) {
    printf("%d ", *((int*) data));
}

Stack2* fromArray(void *arr, size_t n, size_t size) {
    Stack2 *temp = NULL;
    size_t i = 0;
    if (arr == NULL)
        return false;

    temp = createStack2();
    while (i < n) {
        pushBack(temp, ((char*)arr + i * size));
        i++;
    }
    return temp;
}

int main(int argc, const char** argv) {

// Проверка скобочной последовательности
	char buf[BUFSIZ];

	while (printf("String: ") && fgets(buf, BUFSIZ, stdin) && *buf != '\n')
		printf("%s\n", (*bracketsСheck(buf)) ? "FAIL" : "OK");

// Очередь на основе двусвязного списка.
    Stack2 *st = createStack2();
    int a, b, c, d, e, f, g, h;

    a = 1;
    b = 2;
    c = 3;
    d = 4;
    e = 5;
    f = 6;
    g = 7;
    h = 8;
    pushFront(st, &a);
    pushFront(st, &b);
    pushFront(st, &c);
    pushBack(st, &d);
    pushBack(st, &e);
    pushBack(st, &f);
    printf("двусвязная очередь:\n");
    printStack2(st, printInt);

    printf("длина очереди: %d\n", (int)(st->size));
    printf("n = 2: %d\n", *((int*)(getNitem(st, 2))->data));
    printf("n = 5: %d\n", *((int*)(getNitem(st, 5))->data));
    printf("popFront %d\n", *((int*)popFront(st)));
    printf("popFront %d\n", *((int*)popFront(st)));
    printf("head %d\n", *((int*)(st->head->data)));
    printf("tail %d\n", *((int*)(st->tail->data)));
    printf("popBack %d\n", *((int*)popBack(st)));
    printf("popBack %d\n", *((int*)popBack(st)));
    printf("длина очереди: %d\n", (int)(st->size));
    printf("очередь:\n");
    printStack2(st, printInt);

    printf("вставка значения в очередь:\n");
    insertItem(st, 1, &g);
    printStack2(st, printInt);

    printf("удаление значения из очереди:\n");
    deleteN(st, 0);
    printStack2(st, printInt);

    printf("удаление очереди...\n");
    deleteStack2(&st);

    return 0;
}

