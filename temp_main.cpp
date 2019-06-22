
#include <iostream>
#include "Fruit.h"
#include "AVLTree.h"
using namespace std;

#define MAX_SIZE 10000

typedef avl_tree<int, Fruit, int, MAX_SIZE, false> FruitAVLTree;

int main()
{
	int x = 5;
	FruitAVLTree myTree;
	Fruit f(1, 1);
	myTree.insert(f.getID(), f);
	myTree.insert(20, f);
	myTree.insert(45, f);
	myTree.insert(15, f);
	for (FruitAVLTree::iterator it = myTree.begin(); it != myTree.end(); it++)
	{
		cout << "Fruit " << it.key() << endl;
	}
}