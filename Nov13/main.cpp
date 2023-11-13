#include <iostream>
#include "mybintree.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	MyBinTree* tree = new MyBinTree();
	node* fifty = tree->addRoot(50);
	tree->addRoot(60);
	tree->addLeft(fifty, 40); 
	tree->print();
	return 0;
}
