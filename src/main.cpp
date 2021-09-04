#include <iostream>
#include <fstream>
#include <vector>
#include "interdiff.h"

int main() {
	std::ifstream fin;
	fin.open("points.txt");
	if (!fin.is_open()) {
		std::cout << "file error";
		return 2;
	}

	std::cout << "x\t" << "y" << std::endl;
	std::vector<Point> points;
	Point a;
	while (!fin.eof()) {
		fin >> a.x;
		fin >> a.y_x;
		points.push_back(a);
		std::cout << a.x << "\t" << a.y_x << std::endl;
	}

	std::cout << "\n";
	try {
		Interdiff in(points);

		std::vector<float> sample_x = { 53, 2, -23, -123, 21, -3, 1,321 ,-321, 12, 121 };

		for (float ex : sample_x) {
			std::cout << "f'(" << ex << ") = " << in.diff(ex) << std::endl;
		}
	}
	catch (...) {
		std::cout << "Error was occured" << std::endl;
	}
}