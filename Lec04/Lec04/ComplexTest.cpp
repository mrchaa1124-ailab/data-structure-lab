#include "Complex.h"

int main() { // void main()에서 int main()으로 수정
	Complex a, b, c;

	//a = readComplex(" A = ");
	//b = readComplex(" B = ");
	//c = addComplex(a, b);

	//printComplex(a, " A = ");
	//printComplex(b, " B = ");
	//printComplex(c, " A+B = ");

	//v4
	a.read("A = ");
	b.read("B = ");

	c.add(a, b); 

	a.print(" A = ");
	b.print(" B = ");
	c.print(" A+B = ");


	return 0; // return문 추가
}
