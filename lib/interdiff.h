#ifndef _DIFFINTER_H_
#define _DIFFINTER_H_

#include <vector>
#include <iostream>
#include <algorithm>

struct Point {
	float x;
	float y_x;
};

struct Interdiff {
	Interdiff(std::vector<Point>& points_) : points(points_) {
		try{
			if(points.size() < 2) throw "Not enough points";
		}
		catch(const char* a){
			std::cout << a << std::endl;
			throw;
		}
		std::sort(points.begin(), points.end(), [](Point a, Point b){
			return a.x < b.x;
		});
	}
	float interpolation(float x);
	float diff(float x);

private:
	std::vector<Point> points;
};

#endif  /*_DIFFINTER_H_*/