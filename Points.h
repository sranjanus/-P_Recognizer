struct Point {
	int x;
	int y;
	int strokeId;
};

class Template {
	Point *points;

public:
	Template(int nop){
		points = new Point[nop];
	}

	Point returnPointAtIndex(int index){
		return points[i];
	}
};