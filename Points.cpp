struct Point {
	int x;
	int y;
	int strokeId;
};

class Templates {
	Point *points;

public:
	Templates(int nop){
		points = new Point[nop];
	}
};