#include "complex_number.h"
#include <sstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cmath>
#include"complex_number.h"
using namespace std;
#define M_PI  3.1415926535f 

DisplayType Complex::DISPLAY_TYPE{ DisplayType::RECTANGULAR_FORM };

Complex::Complex() : real{ 0.0f }, imag{ 0.0f } //uniform initialization
{}

Complex::Complex(float r, float i)
{
	real = r;
	imag = i;
}

void Complex::setImag(float i)
{
	this->imag = i;
}
void Complex::setReal(float r)
{
	this->real = r;
}

float Complex::getImag() const {
	return this->imag;
}
float Complex::getReal() const {
	return this->real;
}

void Complex::setDisplayType(DisplayType dt) {
	DISPLAY_TYPE = dt;
}
DisplayType Complex::getDisplayType() {
	return DISPLAY_TYPE;
}

Complex Complex::add(const Complex & c) {
	return Complex(this->real + c.real, this->imag + c.imag);
}
Complex Complex::subtract(const Complex& c) {
	return Complex(this->real - c.real, this->imag - c.imag);
}
Complex Complex::multiply(const Complex & c) const
{
	return Complex(this->real * c.real - this->imag * c.imag, this->real * c.imag + this->imag * c.real);
}

void Complex::multiply(float c) {
	this->real = this->real * c;
	this->imag = this->imag * c;
}
bool Complex::equals(const Complex & c) const
{
	if (this->real == c.real && this->imag == c.imag)
		return true;
	return false;
}

Complex Complex::conjugate()
{
	return Complex(this->real, -this->imag);
}

float Complex::phase() const
{
	float result = atan2(this->imag, this->real);
	return result;
}
float Complex::magnitude() const {
	float result = sqrt(this->real * this->real + this->imag * this->imag);
	return result;
}

void Complex::toPolar(float* r, float* theta) const {
	*r = this->magnitude();
	*theta = this->phase();
}
 
Complex Complex::operator+(const Complex& other) {
	return this->add(other);
}

Complex Complex::operator-(const Complex& other)
{
	return this->subtract(other);
}

Complex operator*(const Complex& c1, const Complex& c2)
{
	return c1.multiply(c2);
}

bool Complex::operator==(const Complex& other)
{
	return this->equals(other);
}

bool Complex::operator!=(const Complex& other)
{
	return !this->equals(other);
}

std::string Complex::toString() const {
	if (getDisplayType() == DisplayType::RECTANGULAR_FORM)
	{
		if (this->real == 0 && this->imag == 0)
			return "0";
		int ok = 1;
		ostringstream sstr1, sstr2;
		sstr1 << std::setprecision(2) << std::fixed;
		sstr2 << std::setprecision(2) << std::fixed;
		float v = this->real;
		float v1 = this->imag;
		if (v1 < 0)
			ok = 0;
		sstr1 << v;
		sstr2 << v1;
		string result1 = sstr1.str();
		string result2 = sstr2.str();
		if(ok == 0)
			return result1 + result2 + "i";
		return result1 + "+" + result2 + "i";
		
	}
	else
	{

		float mag, phase;
		mag = this->magnitude();
		phase = this->phase()*180/M_PI;
		if (mag == 0 && phase == 0)
			return "0";
		ostringstream sstr1, sstr2;
		sstr1 << std::setprecision(2) << std::fixed;
		sstr2 << std::setprecision(2) << std::fixed;
		float v = mag;
		float v1 = phase;
		sstr1 << v;
		sstr2 << v1;
		string result1 = sstr1.str();
		string result2 = sstr2.str();

		return result1+"*(cos("+result2+")"+" " + "+" + " " + "i*sin(" + result2 + "))";

	}
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	
	/*is << std::setprecision(2) << std::fixed;
	if (Complex::getDisplayType() == DisplayType::RECTANGULAR_FORM)
	{
		
		if (c.imag < 0)
			is<<fixed<<setprecision(2)<<c.real<<c.imag<< "*i";
		else
			is<<fixed<<setprecision(2)<<c.real<< "+" <<c.imag<< "*i";
		
	}
	else
	{
		float mag, phase;
		mag = c.magnitude();
		phase = c.phase()*180/M_PI;
		is<< fixed<<setprecision(2)<<mag<<"*(cos"<<"("<<phase<<")" << "+isin" <<"(" << phase << "))";
	}*/
	os << c.toString();
	return os;
}
std::istream& operator>>(std::istream& is, Complex& c) {
	is >> c.real >> c.imag;
	return is;
}