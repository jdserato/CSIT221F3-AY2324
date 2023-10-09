#include <iostream>
#include <cstdlib>
#include "list.h"
#include "node.h"
using namespace std;

class DoublyLL : public List {
private:
	node *head, *tail;
	int size;
	
	void addBetween(int elem, node* pred, node* succ){
		node* n = (node*) malloc( sizeof(node) );
		n->elem = elem;
		n->prev = pred;
		n->next = succ;
		pred->next = n;
		succ->prev = n;
		size++;
	}
	
	// 1. Create removeNode with only one parameter
	void removeNode(node* n) {
		node* pred = n->prev;
		node* succ = n->next;
		
		pred->next = succ;
		succ->prev = pred;
		
		free(n);
		size--;
	}
	
public:
	// 2. revise remove(int num) by using removeNode(node*)
	
	DoublyLL() {
		cout << "HELLO constructor here" << endl;	
		head = (node*) calloc(1, sizeof(node));
		tail = (node*) calloc(1, sizeof(node));
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	
	void addFirst(int num) {
		addBetween(num, head, head->next);
	}
	
	void addLast(int num) {
		addBetween(num, tail->prev, tail);
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
		node* curr = head->next;
		int pos = 1;
		while (curr != tail) {
			if (curr->elem == num) {
				removeNode(curr);
				return pos;
			}
			curr = curr->next;
			pos++;
		}
		return -1;
	}
	
	void addAt(int num, int pos) {
		node* curr = head;
		int ctr = 0;
		if (pos > size+1) {
			pos = size+1;
		}
		while (ctr < pos) {
			curr = curr->next;
			ctr++;
		}
		addBetween(num, curr->prev, curr);
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
		node* curr = head->next;
		cout << "Size: " << size << endl;
		cout << "FROM HEAD: ";
		while (curr != tail) {
			cout << curr->elem << " -> ";
			curr = curr->next;
		}
		curr = tail->prev;
		cout << endl << "FROM TAIL: ";
		while (curr != head) {
			cout << curr->elem << " -> ";
			curr = curr->prev;
		}
		cout << endl;
	}
	
};
