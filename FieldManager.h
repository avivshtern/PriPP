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
	AVL_Tree<int, Tree>* treesAVLTree;
	AVL_Tree<int, Fruit>* fruitsAVLIDTree;

	FieldManager()
	{
		treesAVLTree = new AVL_Tree<int, Tree>();
		fruitsAVLIDTree = new AVL_Tree<int, Fruit>();
	}

	void plantTree(int treeNum)
	{
		Tree* t = new Tree(treeNum);
		treesAVLTree->insert(treeNum, t);
	}

	void addFruit(int treeNum, int fruitID, int ripeRate)
	{
		Fruit* f = new Fruit(fruitID, ripeRate, treeNum);
		Tree* t = treesAVLTree->find(treeNum);
		t->addFruit(f);
		fruitsAVLIDTree->insert(f->getID(),f);
	}

	void pickFruit(int fruitID)
	{
		Fruit* f = fruitsAVLIDTree->find(fruitID);
		Tree* t = treesAVLTree->find(f->getParentTreeNum());
		t->pickFruit(fruitID, f->getRipeRate());
		fruitsAVLIDTree->remove(fruitID);
		delete f;
	}

	void getBestFruit(int treeNum, int* bestFruitID)
	{
		Tree* t = treesAVLTree->find(treeNum);
		bestFruitID = t->getBestFruitID; 
	}

	void RateFruit(int fruitID, int ripeRate)
	{
		Fruit* f = fruitsAVLIDTree->find(fruitID);
		f->changeRipeRate(ripeRate);
	}
	
	void UpdateRottenFruits(int rottenBase, int rottenFactor)
	{
		UpdateRottenFruitsVisitor* visitor = new UpdateRottenFruitsVisitor(rottenBase, rottenFactor);
		treesAVLTree->visit(visitor);

	}

	Fruit* findFruitByID(int fruitID)
	{
		return fruitsAVLIDTree->find(fruitID);
	}

	Tree* findTree(int treeNum)
	{
		return treesAVLTree->find(treeNum);
	}


};

#endif