#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <sys/time.h>
#include "../headers/utils.h"
struct BinaryTreeNode
{
	int key;
	struct BinaryTreeNode *left, *right;
};

struct BinaryTreeNode *newNodeCreate(int value)
{
	struct BinaryTreeNode *temp = (struct BinaryTreeNode *)malloc(
		sizeof(struct BinaryTreeNode));
	temp->key = value;
	temp->left = temp->right = NULL;
	return temp;
}

struct BinaryTreeNode *searchNode(struct BinaryTreeNode *root, int target)
{
	if (root == NULL || root->key == target)
	{
		return root;
	}
	if (root->key < target)
	{
		return searchNode(root->right, target);
	}
	return searchNode(root->left, target);
}

struct BinaryTreeNode *insertNode(struct BinaryTreeNode *node, int value)
{
	if (node == NULL)
	{
		return newNodeCreate(value);
	}
	if (value < node->key)
	{
		node->left = insertNode(node->left, value);
	}
	else if (value > node->key)
	{
		node->right = insertNode(node->right, value);
	}
	return node;
}

void postOrder(struct BinaryTreeNode *root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d ", root->key);
	}
}

void inOrder(struct BinaryTreeNode *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf(" %d ", root->key);
		inOrder(root->right);
	}
}

void preOrder(struct BinaryTreeNode *root)
{
	if (root != NULL)
	{
		printf(" %d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

struct BinaryTreeNode *findMin(struct BinaryTreeNode *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->left != NULL)
	{
		return findMin(root->left);
	}
	return root;
}

struct BinaryTreeNode *deleteNode(struct BinaryTreeNode *root, int x)
{
	if (root == NULL)
		return NULL;

	if (x > root->key)
	{
		root->right = deleteNode(root->right, x);
	}
	else if (x < root->key)
	{
		root->left = deleteNode(root->left, x);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if (root->left == NULL || root->right == NULL)
		{
			struct BinaryTreeNode *temp;
			if (root->left == NULL)
			{
				temp = root->right;
			}
			else
			{
				temp = root->left;
			}
			free(root);
			return temp;
		}
		else
		{
			struct BinaryTreeNode *temp = findMin(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	return root;
}

void freeTree(struct BinaryTreeNode *root)
{
	if (root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

void test(int amount)
{
	printf("\n\n\n");
	printf("Running test suite for %d elements\n", amount);

	generate_random_data(amount);
	int *data;
	int read_size = read_from_file(&data);

	if (amount != read_size)
	{
		printf("Error reading data from file\n");
		return;
	}

	int upperBreakpoint = (amount * 3) / 5;
	int lowerBreakpoint = (amount * 8) / 9;

	int upperIndex = generate_random_int(0, upperBreakpoint);
	int middleIndex = generate_random_int(upperBreakpoint, lowerBreakpoint);
	int lowerIndex = generate_random_int(lowerBreakpoint, amount);
	int rootKey = data[0];
	int N = amount + 1;

	// Initialize the root node
	struct BinaryTreeNode *root = NULL;

	printf("Inserting %d elements\n", amount);
	struct timeval start, end;
	gettimeofday(&start, NULL);

	root = insertNode(root, rootKey);

	for (int i = 1; i < amount; i++)
	{
		insertNode(root, data[i]);
	}

	inOrder(root);

	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	printf("Required time to add elements: %ld ms\n", micros);

	{
		printf("Inserting %d element\n", N);

		struct timeval start, end;
		gettimeofday(&start, NULL);

		insertNode(root, N);

		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
		printf("Required time to add N + 1 element: %ld ms\n", micros);
	}
	{
		printf("Searching for element in upper part of the tree\n");
		struct timeval start, end;
		gettimeofday(&start, NULL);

		if (searchNode(root, upperIndex) == NULL)
		{
			return;
		}

		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
		printf("Required to find element in upper part of the tree: %ld ms\n", micros);
	}
	{
		printf("Searching for element in middle part of the tree\n");
		struct timeval start, end;
		gettimeofday(&start, NULL);

		if (searchNode(root, middleIndex) == NULL)
		{
			return;
		}

		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
		printf("Required to find element in middle part of the tree: %ld ms\n", micros);
	}
	{
		printf("Searching for element in lower part of the tree\n");
		struct timeval start, end;
		gettimeofday(&start, NULL);

		if (searchNode(root, lowerIndex) == NULL)
		{
			return;
		}

		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
		printf("Required to find element in lower part of the tree: %ld ms\n", micros);
	}
	{
		printf("Deleting element in lower part of the tree\n");
		struct timeval start, end;
		gettimeofday(&start, NULL);

		deleteNode(root, lowerIndex);

		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
		printf("Required to delete element in lower part of the tree: %ld ms\n", micros);
	}
	{
		printf("Deleting element in middle part of the tree\n");
		// ensure the tree has enough elements
		insertNode(root, lowerIndex);

		struct timeval start, end;
		gettimeofday(&start, NULL);

		deleteNode(root, middleIndex);

		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
		printf("Required to delete element in middle part of the tree: %ld ms\n", micros);
	}

	{
		printf("Deleting element root of the tree\n");
		// ensure the tree has enough elements
		insertNode(root, middleIndex);

		struct timeval start, end;
		gettimeofday(&start, NULL);
		struct BinaryTreeNode *root = NULL;

		deleteNode(root, rootKey);

		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
		printf("Required to delete root of the tree: %ld ms\n", micros);
	}

	// Free the tree memory
	freeTree(root);
}

int main()
{

	int size = 7;
	int cases[size] = {100, 500, 1000, 10000, 100000, 500000, 1000000};
	for (int i = 0; i < size; i++)
	{
		test(cases[i]);
	}

	return 0;
}
