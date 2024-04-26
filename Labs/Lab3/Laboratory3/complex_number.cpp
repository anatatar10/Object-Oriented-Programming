#include <math.h>
#include <stdio.h>

#include "complex_number.h"

Complex complex_create(float real, float imag) {
	Complex c;
	c.real = real;
	c.imag = imag;
	return c;

}

void set_real(Complex* c, float real) {
	c->real = real;
}

void set_imag(Complex* c, float imag) {
	c->imag = imag;
}

float get_real(Complex c) {
	return c.real;
}

float get_imag(Complex c) {
	return c.imag;
}


void complex_display(Complex c) {
	printf("c = %f + %f*i\n", c.real, c.imag);
}

Complex complex_add(Complex c1, Complex c2) {
	Complex sumComplex;
	sumComplex.real = c1.real + c2.real;
	sumComplex.imag = c1.imag + c2.imag;
	return sumComplex;
}

Complex complex_subtract(Complex c1, Complex c2)
{
	Complex difComplex;
	difComplex.real = c1.real - c2.real;
	difComplex.imag = c1.imag - c2.imag;
	return difComplex;
}

Complex complex_multiply(Complex c1, Complex c2) {
	Complex multiplComplex;
	multiplComplex.real = c1.real * c2.real - c1.imag *  c2.imag;
	multiplComplex.imag = c1.real * c2.imag + c1.imag * c2.real;
	return multiplComplex;
}

bool complex_equals(Complex c1, Complex c2) {
	if (c1.real == c2.real && c1.imag == c2.imag)
	{
		return true;
	}
	return false;
}

Complex complex_conjugate(Complex c) {
	Complex c1;
	c1.imag = -c.imag;
	c1.real = c.real;
	return c1;

}

void complex_scalar_mult(Complex* c, float s) {
	c->real = c->real * s;
	(*c).imag = (*c).imag * s;

}

float complex_mag(Complex c) {
	float result = sqrt(c.real * c.real + c.imag * c.imag);
	return result;
}

float complex_phase(Complex c) {
	float result = atan2(c.imag , c.real);
	return result;
}

void complex_to_polar(Complex c, float* r, float* theta) {
	*r = complex_mag(c);
	*theta = complex_phase(c);

}
