#include "Point.h"

#include <math.h>

void $PRecognizer(Point *points, int pSize, Template *templates, int tSize, Template &result, float &score){
	int n = 32;
	normalize(&points, pSize, n);

	score = 9999;
	int d = 0;

	for(int i = 0;i < tSize;i++){
		normalize(templates[i], n);
		d = greedy_CloudMatch(points, templates[i], n);
		if(score > d){
			score = d;
			result = templates[i];
		}
	}
	score = findMax((2-score)/2, 0);
}

int greedy_CloudMatch(Point *points, Template template, int n){
	float e = 0.5;
	int step = int(floor(pow(n, 1-e)));
	int min = 9999;
	int d1, d2;
	for(int i = 0;i < n-1;i++){
		d1 = cloudDistance(points, template, n, i);
		d2 = cloudDistance(points, template, n, i);
		min = findMin(min, d1, d2);
	}
	return min;
}

int cloudDistance(Point *points, Template template, int n, int start){
	bool matched[n];
	int sum = 0;
	int i = start;
	int min, d, index, weight;
	do {
		min = 9999;
		for(int j = 0;j < n;j++){
			if(!matched[j]){
				d = eculideanDistance(points[i], template.returnPointAtIndex(j));
				if(d < min){
					d = min;
					index = j
				}
				matched[index] = true;
				weight = 1 - ((i - start + n)%n)/n;
				sum = sum + weight*min;
				i = (i + 1)%n;
			}
		}
	} while(i == start);
	return sum;
}

void normalize(Point **points, int nop, int n){
	Point* newPoints = resample(*points, n);
	delete (*points);
	points = newPoints;
	scale(points);
	translateToOrigin(points, n); 
}

Point* resample(Point *points, Point *newPoints, int n){
	float I = pathLength(points) / (n - 1);
	int D = 0, d = 0, j = 1;
	Point* newPoints = new Point[n];
	newPoints[0] = points[0];
	for(int i = 1;i < nop;i++){
		if(points[i].strokeId == points[i-1].strokeId){
			d = eculideanDistance(points[i-1], points[i]);
			if((D + d) >= I){
				Point q;
				q.x = points[i - 1].x + ((I - D)/d)*(points[i].x - points[i - 1].x);
				q.y = points[i - 1].y + ((I - D)/d)*(points[i].y - points[i - 1].y);
				q.strokeId = points[i].strokeId;
				newPoints[j++] = q;
				points[i] = q;
				D = 0
			} else {
				D = D + d;
			}
		}
	}

	return newPoints;
}

int eculideanDistance(Point a, Point b){

}

float findMax(float a, float b){
	if(a > b)
		return a;
	else 
		b;
}

int findMin(int a, int b, int c){
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

