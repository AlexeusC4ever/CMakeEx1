#ifndef DIFFINTER_H_
#define DIFFINTER_H_

#include <vector>

struct Point {
	float x;
	float y_x;
};

struct Interdiff {
	Interdiff(const std::vector<Point>& points_);
	float interpolation(float x) const;
	float diff(float x) const;

private:
	std::vector<Point> points;
};

#endif  /*DIFFINTER_H_*/