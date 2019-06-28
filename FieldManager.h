#ifndef FIELDMAMANGER_H
#define FIELDMAMANGER_H
#include <iostream>
#include "Tree.h"
#include "StatusType.h"



class UpdateRottenFruitsVisitor :public Visitor<int, Tree> {
	int _rottenBase;
	int _rottenFactor;
public:
	UpdateRottenFruitsVisitor(int rottenBase, int rottenFactor) {
		_rottenBase = rottenBase;
		_rottenFactor = rottenFactor;
	}
	virtual void visitNode(Tree* visitData) {
		visitData->updateRottenFruits(_rottenBase, _rottenFactor);
	}
};

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
		fruitsIDTree->insert(f->getID(),f);
	}

	void pickFruit(int fruitID)
	{
		int x;
	}

	void RateFruit(int fruitID, int ripeRate)
	{
		Fruit* f = fruitsIDTree->find(fruitID);
		f->changeRipeRate(ripeRate);
	}
	
	void UpdateRottenFruits(int rottenBase, int rottenFactor)
	{
		UpdateRottenFruitsVisitor* visitor = new UpdateRottenFruitsVisitor(rottenBase, rottenFactor);
		treesTree->visit(visitor);

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