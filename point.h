typedef int coord;
typedef struct Point{
	coord y; //4
	coord x; //4
	
	Point midpoint(Point* other) {
		Point midpoint;
		midpoint.x = (other->x + this->x) / 2;
		midpoint.y = (other->y + this->y) / 2;
		return midpoint;
	}
} point;
