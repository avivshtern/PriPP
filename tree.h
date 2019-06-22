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
	AVL_Tree<Fruit> fruitRipeRateAVLTree;


public:

	Tree(int treeNum)
	{
		treeNum_ = treeNum;
	}

	Tree()
	{
		treeNum_ = NULL;
	}

	int getTreeNum()
	{
		return treeNum_;
	}
	
	void addFruit(Fruit* f)
	{
		AVL_Tree<Fruit>* myFruitRipeRateTree;
		myFruitRipeRateTree->insert(f->getRipeRate(), f);
	}



};

#endif