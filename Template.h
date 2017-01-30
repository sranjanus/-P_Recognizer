#include <string.h>

struct Point {
	int x;
	int y;
	int strokeId;
};

class Template {
	Point *points;
	string name;

public:
	Template(int nop);
	~Template();

	void setName(string n);
	void setPointAtIndex(Point p, int index);

	Point returnPointAtIndex(int index);
	Point* returnPointsArray();
};