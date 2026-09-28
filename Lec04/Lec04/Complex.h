#pragma once
#define _CRT_SECURE_NO_WARNINGS // Visual Studio scanf 에러 방지
#include <cstdio>

//
//struct Complex {
//	double real;
//	double imag;
//};
//
//inline void setComplex(Complex& c, double r, double i) {
//	c.real = r;
//	c.imag = i;
//}
//
//extern Complex readComplex(const char* msg = " 복소수 = ");
//extern void printComplex(Complex c, const char* msg = " 복소수 = ");
//extern Complex addComplex(Complex a, Complex b);
//


// v4

class Complex {
	double real;
	double imag;

public:
	void set(double r, double i) {
		real = r;
		imag = i;
	}
	void read(const char* msg = "복소수 = ") {
		printf_s(" %s ", msg);
		scanf_s("%lf%lf", &real, &imag);
	}
	void print(const char* msg = "복소수 = ") {
		printf_s(" %s %4.2f + %4.2fi\n", msg, real, imag);
	}
	void add(Complex a, Complex b) {
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}
};