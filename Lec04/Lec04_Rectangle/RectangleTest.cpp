#include "Rectangle.h"

int main() {
	Rectangle rect;

	rect.read("Rectangle Test");
	printf("\n");

	rect.print("Input Rectangle");
	printf(" -> Area: %4.2f\n", rect.getArea());
	printf(" -> Peri: %4.2f\n", rect.getPerimeter());

	if (rect.isSquare()) {
		printf(" -> Result: OK.\n");
	}
	else {
		printf(" -> Result: NO.\n");
	}

	return 0;
}
