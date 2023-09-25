#include <iostream>
#include "rectangle.h"
using namespace std;

int main(int argc, char** argv) {
	point p1, p2;
	cout << "Size of point is " << sizeof(Point) << endl;
	cout << "Enter x and y for first point: ";
	cin >> p1.x >> p1.y;
	cout << "Enter x and y for second point: ";
	cin >> p2.x >> p2.y;
	Rectangle rec;
	rec.p1 = p1;
	rec.p2 = p2;
//	Point mid = p1.midpoint(&p2);
	cout << "Original Point 1 is " << rec.p1.x << " and " << rec.p1.y << endl;
	cout << "Original Point 2 is " << rec.p2.x << " and " << rec.p2.y << endl;
	Rectangle* pares = rec.twin();
	cout << "Pares Point 1 is " << pares->p1.x << " and " << pares->p1.y << endl;
	cout << "Pares Point 2 is " << pares->p2.x << " and " << pares->p2.y << endl;
	cout << "Before " << pares << endl;
	free(pares);
	cout << "After " << pares << endl;
	cout << "Pares Point 1 is " << pares->p1.x << " and " << pares->p1.y << endl;
	cout << "Pares Point 2 is " << pares->p2.x << " and " << pares->p2.y << endl;
	
//	cout << "Midpoint is: (" << mid.x << "," << mid.y <<")"<< endl;
	return 0;
}
