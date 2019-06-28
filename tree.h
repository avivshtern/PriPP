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
	/*
	*/
	Fruit** getOrderdFruits() {
		return fruitRipeRateAVLTree->getOrderdArray();
	}

	void updateRottenFruits( int rottenBase, int rottenFactor){
		Fruit** orderdFrouits =	getOrderdFruits();
		for (int i = 0; i < fruitRipeRateAVLTree->size; i++) {
			if ((orderdFrouits[i]->getID()) % rottenBase == 0) {
				int newRipeRate = orderdFrouits[i]->getRipeRate() * rottenFactor;
				orderdFrouits[i]->changeRipeRate(newRipeRate);
			}
		}
		int treeSize = fruitRipeRateAVLTree->size;
		fruitRipeRateAVLTree->deleteTree();
		fruitRipeRateAVLTree = new AVL_Tree<int, Fruit>;
		for (int i = 0; i < treeSize; i++) {
			fruitRipeRateAVLTree->insert(orderdFrouits[i]->getRipeRate(), orderdFrouits[i]);
		}
		free(orderdFrouits);	
	}
	void display() {
		fruitRipeRateAVLTree->display();
	}
};

#endif