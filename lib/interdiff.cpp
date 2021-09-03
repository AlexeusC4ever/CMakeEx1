#include "interdiff.h"
#include <vector>
#include <algorithm>

Interdiff::Interdiff(const std::vector<Point>& points_) : points(points_) {
	try {
		if (points.size() < 2) throw "Not enough points";
	}
	catch (...) {
		throw;
	}
	std::sort(points.begin(), points.end(), [](Point a, Point b) {
		return a.x < b.x;
		});
}

float Interdiff::interpolation(float x) const {
	float result = 0;
	size_t i = 0;
	size_t mount = points.size();
	while (x > points[i].x) {
		if (i == mount - 1) break;
		++i;
	}
	if (i == 0) {
		result = (x - points[1].x) / (points[0].x - points[1].x) * points[0].y_x +
			(x - points[0].x) / (points[1].x - points[0].x) * points[1].y_x;
	}
	else {
		result = (x - points[i].x) / (points[i - 1].x - points[i].x) * points[i - 1].y_x +
			(x - points[i - 1].x) / (points[i].x - points[i - 1].x) * points[i].y_x;
	}
	return result;

}

float Interdiff::diff(float x) const {
	float result = 0;
	size_t i = 0;
	size_t mount = points.size();
	while (x > points[i].x) {
		if (i == mount - 1) break;
		++i;
	}
	if (i == 0) ++i;
	if(x == points[i].x && i != 0 && i != mount - 1) 
		result = (points[i + 1].y_x - points[i - 1].y_x) / (points[i + 1].x - points[i - 1].x);
	else 
		result = (points[i].y_x - points[i - 1].y_x) / (points[i].x - points[i - 1].x);
	return result;
}