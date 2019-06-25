#ifndef FIELDMAMANGER_H
#define FIELDMAMANGER_H
#include <iostream>
#include "Fruit.h"
#include "Tree.h"
#include "AVLTree.h"

using namespace std;
class FieldManager
{
public:
	AVL_Tree<Tree>* treesTree;
	AVL_Tree<Fruit>* fruitsIDTree;

	FieldManager()
	{
		treesTree = new AVL_Tree<Tree>();
		fruitsIDTree = new AVL_Tree<Fruit>();
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

};

#endif