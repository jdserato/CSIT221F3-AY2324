#include <iostream>
#include "point.h"
using namespace std;

int main(int argc, char** argv) {
	point p1, p2;
	cout << "Size of point is " << sizeof(Point) << endl;
	cout << "Enter x and y for first point: ";
	cin >> p1.x >> p1.y;
	cout << "Enter x and y for second point: ";
	cin >> p2.x >> p2.y;
	Point mid = p1.midpoint(&p2);
	cout << "Point 1 is " << p1.x << " and " << p1.y << endl;
	cout << "Midpoint is: (" << mid.x << "," << mid.y <<")"<< endl;
	return 0;
}
