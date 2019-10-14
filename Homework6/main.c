/*
 * main.c
 *
 *  Created on: Oct 14, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

// Хэш-функция. На вход функции подается строка, на выходе сумма кодов символов.
int hash(char *str) {
	int hash = 0;
	while(*str) {
		hash += *str;
		str++;
	}
	return hash;
}

//unsigned long hash(unsigned char *str) {
//    unsigned long hash = 5381;
//    int c;
//    while (c = *str++)
//        hash = ((hash << 5) + hash) + c;
//    return hash;
//}

// Двоичное дерево поиска
typedef int T;

typedef int boolean;
#define true 1
#define false 0

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Создание нового узла
Node* createNode(T value, Node *parent) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = value;
    temp->parent = parent;
    return temp;
}

// Вставка узла
boolean insert(Node **head, int value) {
    Node *temp = NULL;
    if (*head == NULL) {
        *head = createNode(value, NULL);
        return true;
    }

    temp = *head;
    while (temp) {
        if (value > temp->data) {
            if (temp->right) {
                temp = temp->right;
                continue;
            } else {
                temp->right = createNode(value, temp);
                return true;
            }
        } else if (value < temp->data) {
            if (temp->left) {
                temp = temp->left;
                continue;
            } else {
                temp->left = createNode(value, temp);
                return true;
            }
        } else
        	return false;
    }
    return true;
}

// Обход дерева поиска
void preOrderTravers(Node *root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inorderTraversal(Node *root) {
    if (root) {
    	inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root) {
    if (root) {
    	postorderTraversal(root->left);
    	postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Поиск в двоичном дереве
Node* findMinNode(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* findMaxNode(Node *root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}

Node* searchNode(Node *root, int key) {
    if ((root == NULL) || (root->data = key))
        return root;
    if (key < root->data)
        return searchNode(root->left, key);
    else
    	return searchNode(root->right, key);
}

// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root) {
	if (root) {
		printf("%d",root->data);
		if (root->left || root->right) {
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

int main(int argc, const char** argv) {

// Хэш-функция. На вход функции подается строка, на выходе сумма кодов символов.
	printf("HASH = %d\n", hash("bodo"));
	printf("HASH = %d\n", hash("bada"));
	printf("HASH = %d\n", hash("dada"));
	printf("-----------------------\n");

// Двоичное дерево поиска
	Node *tree = NULL;

	insert(&tree, 10);
	insert(&tree, 7);
	insert(&tree, 9);
	insert(&tree, 12);
	insert(&tree, 6);
	insert(&tree, 14);
	insert(&tree, 11);
	insert(&tree, 3);
	insert(&tree, 4);

//	int value = -1;
//	while (value != 0) {
//		printf("Value: ");
//		scanf("%d", &value);
//		insert(&tree, value);
//	}

	printTree(tree);
	printf("\n");

	printf("PreOrderTravers:\n");
	preOrderTravers(tree);
	printf("\n");
	printf("InorderTraversal:\n");
	inorderTraversal(tree);
	printf("\n");
	printf("PostorderTraversall:\n");
	postorderTraversal(tree);

	printf("\n");
	printf("max = %d\n", findMaxNode(tree)->data);
	printf("min = %d\n", findMinNode(tree)->data);
	printf("Search: %d\n", searchNode(tree, 6)->data);

	return 0;
}
