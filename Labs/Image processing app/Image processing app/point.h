#pragma once
#include<iostream>
#include<ostream>
class Point {

private:
	unsigned int x, y;

public:
	Point();
	Point(unsigned int x, unsigned int y);
	Point(const Point& other);
	unsigned int getX() const;
	unsigned int getY() const;
	void setX(unsigned int x);
	void setY(unsigned int y);

	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	friend std::istream& operator>>(std::istream& is, Point& p);
	friend class pointTest;
	friend class RectangleTest;
};