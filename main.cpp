#include <iostream>
#include "arraystack.h"

int main() {
//	cout << "Size of foo " << sizeof(foo) << endl;
//	ArrayList* list = new ArrayList();
//	int *array = (int*) malloc(5 * sizeof(int));
//	int* rearray = (int*) realloc(array, 10 * sizeof(int));
//	int* rearray2 = (int*) realloc(rearray, 15 * sizeof(int));
//	cout << "Address of realloc: " << rearray << endl;
//	cout << "Address of realloc2: " << rearray2 << endl;
	int n;
	char op;
	
	Stack* stack = new ArrayStack();
	
	do {
		cin >> op;
		switch (op) {
			case 'a':
				cin >> n;
				stack->push(n);
				break;
			case 'p':
				stack->print();
				break;
			case 'r':
				cout << "Removed " << stack->pop() << endl;
				break;
			case 't':
				cout << "Top Element: " << stack->top() << endl;
				break;
			case 's':
				cout << "Size " << stack->size() << endl;
				break;
			case 'e':
				cout << "Is Empty? " << stack->isEmpty() << endl;
				break;
		}
	} while (op != 'x');
	return 0;
}
