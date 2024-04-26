#include"point.h"
#include<iostream>
#include<ostream>

Point::Point() : x{ 0 }, y{ 0 } {}


Point::Point(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;

}

unsigned int Point::getX() const
{
	return this->x;
}

unsigned int Point::getY() const
{
	return this->y;
}

void Point::setX(unsigned int x)
{
	this->x = x;
}

void Point::setY(unsigned int y)
{
	this->y = y;
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
	//int x, y;
	is >> p.x >> p.y;
	return is;

}
