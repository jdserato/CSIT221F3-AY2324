#include <iostream>
#include "arraylist.h"

struct foo {
	int* a;
	char ch, ch2;
	int i;
};

int main() {
	cout << "Size of foo " << sizeof(foo) << endl;
	ArrayList* list = new ArrayList();
	int *array = (int*) malloc(5 * sizeof(int));
	int* rearray = (int*) realloc(array, 10 * sizeof(int));
	int* rearray2 = (int*) realloc(rearray, 15 * sizeof(int));
	cout << "Address of realloc: " << rearray << endl;
	cout << "Address of realloc2: " << rearray2 << endl;
	int n;
	char op;
	do {
		cin >> op;
		switch (op) {
			case 'a':
				cin >> n;
				list->add(n);
				break;
			case 'p':
				list->print();
				break;
			case 'r':
				cin >> n;
				list->remove(n);
				break;
			case 'R':
				cin >> n;
				cout << "Removed " << list->removeAll(n) << " stuffs" << endl;
				break;
		}
	} while (op != 'x');
	list->print();
	list->add(13);
	list->add(7);
	list->add(20);
	list->add(9);
	list->add(35);
	list->print();
	list->add(17);
	list->print();
	cout << "Elem at pos 2: " << list->get(2) << endl; 
	cout << "Elem at pos 4: " << list->get(4) << endl; 
	cout << "Remove 20, found at " << list->remove(20) << endl;
	list->print(); 
	cout << "Remove 20, found at " << list->remove(20) << endl;
	list->print(); 
	cout << "Remove 10, found at " << list->remove(10) << endl;
	list->print();
	return 0;
}
