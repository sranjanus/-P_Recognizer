#include "Point.h"

void $PRecognizer(Point *points, int pSize, Template *templates, int tSize, Template &result, int &score){
	int n = 32;
	normalize(points, pSize, n);

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
}

int greedy_CloudMatch(Point *points, Template template, int n){
	float e = 0.5;
	int step = floor(pow(n, 1-e));
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

void normalize(Point *points, int n){
	resample(points, n);
	scale(points);
	translateToOrigin(points, n); 
}

void resample(Point *points, int n){
	float I = pathLength(points) / (n - 1);
	int D = 0;
	Point newPoint = points[0];
	for(int i = 1;i < )
}