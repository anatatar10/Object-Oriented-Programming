#pragma once
#include<ostream>
#include<istream>
#include"point.h"
#include"size.h"
#include<cmath>

class Rectangle {
private:
	Point start;
	Size size;

public:
	Rectangle();
	Rectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	Rectangle(const Point& p1, const Point& p2);
	unsigned int getX() const;
	unsigned int getY() const;
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	Rectangle operator+=(const Point& other);
	Rectangle operator-=(const Point& other);
	Rectangle operator&(const Rectangle& other);
	Rectangle operator|(const Rectangle& other);
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);

	friend std::istream& operator>>(std::istream& is, Rectangle& rect);

	friend Rectangle operator+(Rectangle lhs, const Point& rhs);

	friend Rectangle operator-(Rectangle lhs, const Point& rhs);
	friend class RectangleTest;
};
