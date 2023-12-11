#include <iostream>
#include "arrayheap.h"
using namespace std;
int main(void){
	Heap* heap = new ArrayHeap();
	char op;
	int n;
	do {
		cout << "Op: ";
		cin >> op;
		switch(op) {
			case 'i':
				cin >> n;
				heap->insert(n);
				break;
			case 'r':
				cout << "Removed " << heap->removeMin();
				break;
			case 'p':
				heap->print();
				break;
			case 'x':
				cout << "Exiting...";
				break;
		}
	} while (op != 'x');
}
