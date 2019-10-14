/*
 * main.c
 *
 *  Created on: Oct 14, 2019
 *      Author: Dmitry Shakhtorin
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
} Node;

int arr[] = {5, 8, 7, 3, 0, 9, 1, 2, 4, 6};
int i = 0;

void preOrderTravers(Node *root) {
  if (root) { // if (root != NULL)
	printf("%d ", root->data);
	//(
	preOrderTravers(root->left);
	//,
	preOrderTravers(root->right);
	//)
  }
}

void printTree(Node *root) {
  if (root)
	{
      printf("%d",root->data);
	  if (root->left || root->right)
		{
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

Node* tree(int a, Node* parent) {
  Node *node;
  if (a == 0) {
	node = NULL;
  } else {
	int v = arr[i++];
	node = (Node *) malloc(sizeof(Node));
	node->data = v;
	node->parent = parent;
	int nL = a / 2;
	int nR = a - nL - 1;
	node->left = tree(nL, node);
	node->right = tree(nR, node);
  }
  return node;
}

int main(int argc, const char** argv) {
  Node *t = tree(10, NULL);
  printTree(t);
  printf("\n");
  return 0;
}


