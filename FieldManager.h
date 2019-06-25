#ifndef FIELDMAMANGER_H
#define FIELDMAMANGER_H
#include <iostream>
#include "Fruit.h"
#include "Tree.h"
#include "AVLTree.h"
#include "StatusType.h"

using namespace std;
class FieldManager
{
public:
	AVL_Tree<int, Tree>* treesTree;
	AVL_Tree<int, Fruit>* fruitsIDTree;

	FieldManager()
	{
		treesTree = new AVL_Tree<int, Tree>();
		fruitsIDTree = new AVL_Tree<int, Fruit>();
	}

	void plantTree(int treeNum)
	{
		Tree* t = new Tree(treeNum);
		treesTree->insert(treeNum, t);
	}

	void addFruit(int treeNum, int fruitID, int ripeRate)
	{
		Fruit* f = new Fruit(fruitID, ripeRate, treeNum);
		Tree* t = treesTree->find(treeNum);
		t->addFruit(f);
		fruitsIDTree->insert(f);
	}

	void pickFruit(int fruitID)
	{
		int x;
	}

	void RateFruit(int fruitID, int ripeRate)
	{
		Fruit* f = fruitsIDTree->find(fruitID);
		f.changeRipeRate(ripeRate);
	}

	void UpdateRottenFruits(int rottenBase, int rottenFactor)
	{

	}

	Fruit* findFruitByID(int fruitID)
	{
		return fruitsIDTree->find(fruitID);
	}

	Tree* findTree(int treeNum)
	{
		return treesTree->find(treeNum);
	}



};

#endif