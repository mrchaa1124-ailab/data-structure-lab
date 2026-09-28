#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>

class Rectangle {
private:
	double width;
	double height;

public:
	void set(double w, double h) {
		width = w;
		height = h;
	}

	void read(const char* msg = "Rectangle Info") {
		printf("[%s]\n", msg);
		printf(" Width: ");
		scanf("%lf", &width);
		printf(" Height: ");
		scanf("%lf", &height);
	}

	double getArea() {
		return width * height;
	}

	double getPerimeter() {
		return 2 * (width + height);
	}

	bool isSquare() {
		return width == height;
	}

	void print(const char* name = "Rectangle") {
		printf(" %s -> W: %4.2f, H: %4.2f\n", name, width, height);
	}
};
