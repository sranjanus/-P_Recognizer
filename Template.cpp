#include "Template.h"

Template::Template(int nop){
		points = new Point[nop];
}

Template::~Template(){
	delete points;
}

void Template::setName(string n){
	name = n;
}

void Template::setPointAtIndex(Point p, int index){
	points[index] = p;
}

Point Template::returnPointAtIndex(int index){
		return points[i];
}

Point* Template::returnPointsArray(){
	return points;
}