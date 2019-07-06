//
//#include <iostream>
//#include "FieldManager.h"
////#include "Fruit.h"
////#include "AVLTree.h"
////#include "Tree.h"
//using namespace std;
//
//#define MAX_SIZE 10000
//
////typedef avl_tree<int, Fruit, int, MAX_SIZE, false> FruitAVLTree;
//
//int main()
//{
//	/*
//	Fruit* fruit = new Fruit(1, 12);
//	Fruit* fruit2 = new Fruit(2, 11);
//	Fruit* fruit3 = new Fruit(3, 45);
//	Fruit* fruit4 = new Fruit(4, 15);
//	int x = 5;
//	FruitAVLTree myTree;
//	Fruit f(1, 1);
//	myTree.insert(f.getID(), f);
//	myTree.insert(20, f);
//	myTree.insert(45, f);
//	myTree.insert(15, f);
//	for (FruitAVLTree::iterator it = myTree.begin(); it != myTree.end(); it++)
//	{
//		cout << "Fruit " << it.key() << endl;
//
//
//	AVL_Tree<int ,Fruit> myTree;
//	myTree.insert(fruit3->getID(), fruit3);
//	myTree.insert(fruit2->getID(), fruit2);
//	myTree.insert(fruit4->getID(), fruit4);
//	myTree.insert(fruit->getID(), fruit);
//	Fruit* f = myTree.find(30);
//	myTree.display();
//	Fruit** FruitList = myTree.getOrderdArray();
//	for (int i = 0; i < myTree.size; i++) {
//		cout << FruitList[i]->getRipeRate() << endl;
//	}
//	myTree.deleteTree();
//
//
//	Tree myFruitTree;
//	myFruitTree.addFruit(fruit);
//	myFruitTree.addFruit(fruit2);
//	myFruitTree.addFruit(fruit3);
//	myFruitTree.addFruit(fruit4);
//	myFruitTree.display();
//	myFruitTree.updateRottenFruits(2, 4);
//	myFruitTree.display();
//	
//	}*/
//	FieldManager Orchard;
//	/*
//	for (int i = 0; i < 4; i++){
//		Orchard.plantTree(i);
//		for (int j = 0; j < 20; j++) {
//			Orchard.addFruit(i, i*4+ j, i*j);
//		}
//	}
//	*/
//	Orchard.plantTree(1);
//	Orchard.addFruit(1, 1, 10);
//	Orchard.addFruit(1, 2, 11);
//	Orchard.addFruit(1, 3, 12);
//	Orchard.addFruit(1, 4, 13);
//	Orchard.plantTree(2);
//	Orchard.addFruit(2, 5, 10);
//	Orchard.addFruit(2, 6, 11);
//	Orchard.addFruit(2, 7, 12);
//	Orchard.addFruit(2, 8, 13);
//
//	Tree* tree1 = Orchard.findTree(1);
//	Tree* tree2 = Orchard.findTree(2);
//	cout << "A tree1 ";
//	tree1->display();
//	cout << "  -  tree2 ";
//	tree2->display();
//	cout << endl;
//
//	Orchard.UpdateRottenFruits(1,2);
//	cout << "B tree1 ";
//	tree1->display();
//	cout << "  -  tree2 ";
//	tree2->display();
//	cout << endl;
//	Orchard.UpdateRottenFruits(3, 2);
//	cout <<"C tree1 ";
//	tree1->display();
//	cout << "  -  tree2 ";
//	tree2->display();
//	cout << endl;
//	Orchard.deleteField();
//}