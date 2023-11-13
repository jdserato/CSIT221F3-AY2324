#include "bintree.h"
#include <iostream>
using namespace std;
class MyBinTree : public BinaryTree {
	node* root;
	int size;
	
	public:
	MyBinTree() {
		root = nullptr;
		size = 0;
	}
	
	node* addRoot(int elem) {
		if (!root) {
			node* n = (node*) calloc(1, sizeof(node));
			n->elem = elem;
			root = n;
			size++;
			return root;
		} else {
			return nullptr;
		}
	}
	node* addLeft(node* p, int e) {
		if (!p->left) {
			node* n = (node*) calloc(1, sizeof(node));
			n->elem = e;
			n->parent = p;
			p->left = n;
			size++;
			return n;
		} else {
			return nullptr;
		}
	}
	node* addRight(node* p, int e) {
		
	}
	void print() {
		cout << "Size: " << size << endl;
		print(root);
	}
	
	void print(node* n) {
		if (n) {
			cout << n->elem << endl;
			print(n->left);
			print(n->right);
		}
	}
};
