#include "heap.h"
#include "arraylist.h"
class ArrayHeap : public Heap {
	ArrayList* array;
	
	public:
	ArrayHeap() {
		array = new ArrayList();
	}
	
	void insert(int num) {
		array->add(num);
		// Check for violations
		int curr_ind = array->_size()-1;
		while (true) {
			int par_ind = (curr_ind - 1) / 2;
			if (num < array->get(par_ind+1)) {
				array->swap(curr_ind, par_ind);
				curr_ind = par_ind;
			} else {
				break;
			}
		}
	}
	int removeMin(){
		
	}
	void print(){
		array->print();
	}
};
