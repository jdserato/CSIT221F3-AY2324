#include <iostream>
#include <cstdlib>
#include "list.h"
#include "node.h"
using namespace std;

class DoublyLL : public List {
	node *head, *tail;
	int size;
	
public:
	void addFirst(int num) {
		// Create the node
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
		// Step 2: Set the n's next to head
		n->next = head;
		if (head) {
			head->prev = n;
		}
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
		n->prev = tail;
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
		addLast(num);
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
	
	int remove(int num) {
		node* curr = head;
		int pos = 1;
		while (curr) {
			if (curr->elem == num) {
				if (pos == 1) {
					removeFirst();
					return pos;
				}
				if (pos == size) {
					removeLast();
					return pos;
				}
				node* pred = curr->prev;
				node* succ = curr->next;
				pred->next = succ;
				succ->prev = pred;
				free(curr);
				size--;
				return pos;
			}
			curr = curr->next;
			pos++;
		}
	}
	
	void addAt(int num, int pos) {
		if (pos == 1) {
			addFirst(num);
			return;
		}
		if (pos > size) {
			addLast(num);
			return;
		}
		node* curr = head;
		int ctr = 1;
		while (ctr < pos) {
			curr = curr->next;
			ctr++;
		} cout << "97 is good" << endl;
		node* pred = curr->prev; cout << "98 is good" << endl;
		node* succ = curr;cout << "99 is good" << endl;
		node* n = (node*) malloc (sizeof(node));cout << "100is good" << endl;
		n->elem = num;cout << "101is good" << endl;
		n->next = succ;cout << "102is good" << endl;
		n->prev = pred;cout << "103is good" << endl;
		pred->next = n;cout << "104is good" << endl;
		succ->prev = n;cout << "105is good" << endl;
		size++;
	}
	
	void removeFirst() {
		if (size == 0) {
			return;
		}
		head = head->next;
		if (head) {
			free(head->prev);
			head->prev = nullptr;
		} else {
			tail = nullptr;
		}
		size--;
	}
	
	void removeLast() {
		if (size == 0) {
			return;
		}
		tail = tail->prev;
		if (tail) {
			free(tail->next);
			tail->next = nullptr;
		} else {
			head = nullptr;
		}
		size--;
	}
	
	void print() {
		node* curr = head;
		cout << "Size: " << size << endl;
		cout << "FROM HEAD: ";
		while (curr != nullptr) {
			cout << curr->elem << " -> ";
			curr = curr->next;
		}
		curr = tail;
		cout << endl << "FROM TAIL: ";
		while (curr != nullptr) {
			cout << curr->elem << " -> ";
			curr = curr->prev;
		}
		cout << endl;
	}
	
};
