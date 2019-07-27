#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include<iostream>
#include <algorithm>
#include <array>
using namespace std;

template <typename Key, typename T>
class Visitor {
public:
	virtual void visitNode(T* visitData) = 0;
};

template <typename Key, typename T> // Key must have < and > operators implemented
class AVL_Tree
{
	struct node
	{
		Key value;
		T* data;
		node* left;
		node* right;
		int height;
	};

	node* root;


	void makeEmpty(node* t)
	{
		if (t == NULL)
			return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	node* insert(Key x, T* data, node* t)
	{
		if (t == NULL)
		{
			size++;
			t = new node;
			t->value = x;
			t->data = data;
			t->height = 0;
			t->left = t->right = NULL;
		}

		else if (x < t->value)
		{
			t->left = insert(x, data, t->left);
			if (height(t->left) - height(t->right) == 2)
			{
				if (x < t->left->value)
					t = singleRightRotate(t);
				else
					t = doubleRightRotate(t);
			}
		}
		else if (x > t->value)
		{
			t->right = insert(x, data, t->right);
			if (height(t->right) - height(t->left) == 2)
			{
				if (x > t->right->value)
					t = singleLeftRotate(t);
				else
					t = doubleLeftRotate(t);
			}
		}

		t->height = max(height(t->left), height(t->right)) + 1;
		return t;
	}

	node* singleRightRotate(node*& t)
	{
		node* u = t->left;
		t->left = u->right;
		u->right = t;
		t->height = max(height(t->left), height(t->right)) + 1;
		u->height = max(height(u->left), t->height) + 1;
		return u;
	}

	node* singleLeftRotate(node*& t)
	{
		node* u = t->right;
		t->right = u->left;
		u->left = t;
		t->height = max(height(t->left), height(t->right)) + 1;
		u->height = max(height(t->right), t->height) + 1;
		return u;
	}

	node* doubleLeftRotate(node*& t)
	{
		t->right = singleRightRotate(t->right);
		return singleLeftRotate(t);
	}

	node* doubleRightRotate(node*& t)
	{
		t->left = singleLeftRotate(t->left);
		return singleRightRotate(t);
	}

	node* findMin(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	node* remove(Key x, node* t)
	{
		node* temp;

		// Element not found
		if (t == NULL)
			return NULL;

		// Searching for element
		else if (x < t->value)
			t->left = remove(x, t->left);
		else if (x > t->value)
			t->right = remove(x, t->right);

		// Element found
		// With 2 children
		else if (t->left && t->right)
		{
			temp = findMin(t->right);
			t->value = temp->value;
			t->right = remove(t->value, t->right);
		}
		// With one or zero child
		else
		{
			temp = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			delete temp;
			size--;
		}
		if (t == NULL)
			return t;

		t->height = max(height(t->left), height(t->right)) + 1;

		// If node is unbalanced
		// If left node is deleted, right case
		if (height(t->left) - height(t->right) == 2)
		{
			// right right case
			if (height(t->left->left) - height(t->left->right) == 1)
				return singleLeftRotate(t);
			// right left case
			else
				return doubleLeftRotate(t);
		}
		// If right node is deleted, left case
		else if (height(t->right) - height(t->left) == 2)
		{
			// left left case
			if (height(t->right->right) - height(t->right->left) == 1)
				return singleRightRotate(t);
			// left right case
			else
				return doubleRightRotate(t);
		}
		return t;
	}

	int height(node* t)
	{
		return (t == NULL ? -1 : t->height);
	}

	int getBalance(node* t)
	{
		if (t == NULL)
			return 0;
		else
			return height(t->left) - height(t->right);
	}

	void inorder(node* t)
	{
		if (t == NULL)
			return;
		inorder(t->left);
		cout << t->value << " ";
		inorder(t->right);
	}

	void inorderVisit(node* t, T* array[], int* index)
	{
		if (t == NULL)
			return;
		inorderVisit(t->left, array, index);
		array[*index] = t->data;
		*index += 1;
		inorderVisit(t->right, array, index);
	}

	node* findNode(Key x, node* t)
	{
		// Element not found
		if (t == NULL)
			return NULL;
		// Searching for element
		else if (x < t->value)
			return findNode(x, t->left);
		else if (x > t->value)
			return findNode(x, t->right);
		return t;
	}

	void deleteTree(node* t) {
		if (t == NULL) return;
		deleteTree(t->left);
		deleteTree(t->right);
		delete t;
	}

	void visit(node* t, Visitor<Key, T>* visitor) {
		if (t == NULL) return;
		visitor->visitNode(t->data);
		visit(t->left, visitor);
		visit(t->right, visitor);

	}


public:
	int size = 0;

	AVL_Tree()
	{
		root = NULL;
	}

	void insert(Key x, T* data)
	{
		root = insert(x, data, root);
	}

	T* getMin()
	{
		node* n = findMin(root);
		return n->data;
	}

	void remove(Key x)
	{
		root = remove(x, root);
	}

	T* find(Key x)
	{
		node* n = findNode(x, root);
		if (n != NULL)
		{
			return n->data;
		}
		return NULL;
	}

	void display()
	{
		if (root != NULL) {
			inorder(root);
		}
		//cout << endl;

	}

	T** getOrderdArray() {
		T** sortedArray = new T * [size];
		int index = 0;
		inorderVisit(root, sortedArray, &index);
		return sortedArray;
	}

	void deleteTree() {
		deleteTree(root);
	}

	void visit(Visitor<Key,T>* visitor) {
		visit(root, visitor);
	}

};

#endif




