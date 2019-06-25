#ifndef TREE_H
#define TREE_H
#include "Fruit.h" 
#include "AVLTree.h"
#include <iostream>
#define MAX_SIZE 10000

using namespace std;

class Tree
{
	int treeNum_;
	AVL_Tree<int, Fruit>* fruitRipeRateAVLTree;


public:

	Tree(int treeNum)
	{
		treeNum_ = treeNum;
		fruitRipeRateAVLTree = new AVL_Tree<int, Fruit>();
	}

	Tree()
	{
		treeNum_ = NULL;
		fruitRipeRateAVLTree = new AVL_Tree<int, Fruit>();
	}

	int getTreeNum()
	{
		return treeNum_;
	}
	
	void addFruit(Fruit* f)
	{
		fruitRipeRateAVLTree->insert(f->getRipeRate(), f);
	}



};

#endif