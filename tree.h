#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Fruit.h" 
#include "AVLTree.h"
#include "FruitIDAndRipeRate.h"

#define MAX_SIZE 10000

using namespace std;

class Tree
{
	int treeNum_;
	AVL_Tree<FruitIDAndRipeRate, Fruit>* fruitRipeRateAVLTree;


public:

	Tree(int treeNum)
	{
		treeNum_ = treeNum;
		fruitRipeRateAVLTree = new AVL_Tree<FruitIDAndRipeRate, Fruit>();
	}

	Tree()
	{
		treeNum_ = NULL;
		fruitRipeRateAVLTree = new AVL_Tree<FruitIDAndRipeRate, Fruit>();
	}

	int getTreeNum()
	{
		return treeNum_;
	}
	
	void addFruit(Fruit* f)
	{
		fruitRipeRateAVLTree->insert(f->getFruitIDAndRipeRate(), f);
	}
	
	int pickFruit(int fruitID, int ripeRate)
	{
		FruitIDAndRipeRate <fruitID, ripeRate> key;
		fruitRipeRateAVLTree->remove(key);
	}

	int getBestFruitID()
	{
		Fruit* f = fruitRipeRateAVLTree->getMin();
		return f->getID;
	}

	Fruit** getOrderedFruits() 
	{
		return fruitRipeRateAVLTree->getOrderdArray();
	}

	int getSize() {
		return fruitRipeRateAVLTree->size;
	}

	void updateRottenFruits( int rottenBase, int rottenFactor){
		Fruit** orderdFrouits =	getOrderdFruits();
		for (int i = 0; i < fruitRipeRateAVLTree->size; i++) {
			if ((orderedFruits[i]->getID()) % rottenBase == 0) {
				int newRipeRate = orderedFruits[i]->getRipeRate() * rottenFactor;
				orderedFruits[i]->changeRipeRate(newRipeRate);
			}
		}
		int treeSize = fruitRipeRateAVLTree->size;
		fruitRipeRateAVLTree->deleteTree();
		fruitRipeRateAVLTree = new AVL_Tree<FruitIDAndRipeRate, Fruit>;
		for (int i = 0; i < treeSize; i++) {
			fruitRipeRateAVLTree->insert(orderedFruits[i]->getFruitIDAndRipeRate(), orderedFruits[i]);
		}
		free(orderedFruits);	
	}
	void display() {
		fruitRipeRateAVLTree->display();
	}

	void deleteTree() {
		fruitRipeRateAVLTree->deleteTree();
	}
};

#endif