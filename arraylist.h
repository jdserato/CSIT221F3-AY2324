#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

class ArrayList : public List {
	int *array;
	int size = 0;
	int capacity;
	
	public:
	ArrayList() {
		cout << "HEY YOU CALLED ME" << endl;
		capacity = 5;
		array = (int*) calloc( capacity, sizeof(int) );
		cout << "Negative capacity: " << (size_t) -capacity << endl;
		cout << "Address (constructor): " << array << endl;
	}
		
	void add(int num) {
		cout << "Adding " << num << endl;
		if (size >= capacity) {
			capacity *= 1.5;
			array = (int*) realloc(array, capacity * sizeof(int) );
			cout << "New capacity: " << capacity << endl;
			cout << "Address: " << array << endl;
		}
		array[size] = num;
		size++;
	}
	
	int get(int pos) {
		int index = pos-1;
		return array[index];
	}
	
	int remove(int num) {
		// STEP 1: Find the num
		for (int i = 0; i < size; i++) {
			if (array[i] == num) {
				// STEP 2: Move elements to left
				for (int j = i+1; j < size; j++){
					array[j-1] = array[j];
				}
				// STEP 3: Reset last elem
				array[size-1] = 0;
				size--;
				if (size <= capacity * (2.0/3)) {
					capacity *= 0.75;
					if (capacity < 5) {
						capacity = 5;
					}
					array = (int*) realloc(array, capacity * sizeof(int) );
					cout << "New capacity: " << capacity << endl;
					cout << "Address: " << array << endl;
				}
				return i+1;
			}
		}
		return -1;
	}
	
	void reset() {
		for (int i = 0; i < capacity; i++) {
			array[i] = 0;
		}
		size = 0;
	}
	
	void print() {
		cout << "Size: " << size << endl;
		for (int i = 0; i < capacity; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};
