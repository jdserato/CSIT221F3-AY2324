#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class LinkedList : public List {
	node *head, *tail;
	int size;
	
public:
	void addFirst(int num) {
		node* n = new node;
		n->elem = num;
		// Step 2: Set the n's next to head
		n->next = head;
		// Step 3: Head to n
		head = n;
		if (!tail) {
			tail = n;
		}
		// Step 4: Inc size
		size++;
	}
	
	void addLast(int num) {
		// STEP 1: Create node
		node* n = (node*) malloc( sizeof(node) );
		cout << "n is " << n << endl;
		n->elem = num;
		n->next = nullptr;
		// STEP 2: Tail's next = n
		if (tail) {
			cout << "Have tail" << endl;
			tail->next = n;
		} else {
			cout << "Have no tail" << endl;
			head = n;
		}
		// STEP 3: Tail = n
		tail = n;
		// STEP 4: Increment size
		size++;
	}
		
	void add(int num) {
		addFirst(num);
	}
	
	int removeFirst() {
		if (!head) {
			return -1;
		}
		int tmp = head->elem;
		// Step 1: Get next head
		node* n_head = head->next;
		// Step 2: Free head
		free(head);
		// Step 3: Set head to n_head
		head = n_head;
		// Step 4: Size--
		size--;
		return tmp;
	}
	
	int get(int pos) {
		node* curr = head;
		int ctr = 1;
		while (ctr < pos) {
			curr = curr->next;
			ctr++;
		}
		return curr->elem;
	}
	
	int _size() {
		return size;
	}
	
	int remove(int num) {
		
	}
	
	void print() {
		node* curr = head;
		cout << "Size: " << size << endl;
		while (curr != nullptr) {
			cout << curr->elem << " @" << curr << endl;
			curr = curr->next;
		}
		cout << endl;
	}
	
};
