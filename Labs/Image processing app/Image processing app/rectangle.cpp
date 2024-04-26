#include"rectangle.h"
#include<algorithm>

Rectangle::Rectangle()
{
	this->start.setX(0);
	this->start.setY(0);
}

Rectangle::Rectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	this->start = Point(x, y);
	this->size = Size(width, height);
}

Rectangle::Rectangle(const Point& p1, const Point& p2)
{
	this->start.setX(p1.getX());
	this->start.setY(p1.getY());
	this->size = Size(p2.getX() - p1.getX(), p2.getY() - p1.getY());


}

unsigned int Rectangle::getX() const
{
	return start.getX();
}

unsigned int Rectangle::getY() const
{
	return start.getY();
}

unsigned int Rectangle::getWidth() const
{
	return size.getWidth();
}

unsigned int Rectangle::getHeight() const
{
	return size.getHeight();
}

Rectangle Rectangle::operator+=(const Point& other)
{
	this->start.setX(other.getX() + this->getX());
	this->start.setY(other.getY() + this->getY());
	return *this;
}

Rectangle Rectangle::operator-=(const Point& other)
{
	this->start.setX(this->getX() - other.getX());
	this->start.setY(this->getY() - other.getY());
	return *this;
}

Rectangle Rectangle::operator&(const Rectangle& other)
{
	int minX, minY, maxX, maxY;
	maxX = std::max(this->start.getX(), other.getX());
	maxY = std::max(this->start.getY(), other.getY());
	minX = std::min(this->start.getX() + this->getWidth(), other.getX() + other.getWidth());
	minY = std::min(this->start.getY() + this->getHeight(), other.getY() + other.getHeight());
	Point p1(maxX, maxY);
	Point p2(minX, minY);
	if (minX <= maxX || minY <= maxY)
	{
		return Rectangle();
	}
	else
		return Rectangle(p1, p2);
}

Rectangle Rectangle::operator|(const Rectangle& other)
{
	int minX, minY, maxX, maxY;
	minX = std::min(this->start.getX(), other.getX());
	minY = std::min(this->start.getY(), other.getY());
	maxX = std::max(this->start.getX() + this->getWidth(), other.getX() + other.getWidth());
	maxY = std::max(this->start.getY() + this->getHeight(), other.getY() + other.getHeight());
	Point p1(minX, minY);
	Point p2(maxX, maxY);
	return Rectangle(p1, p2);
}




std::ostream& operator<<(std::ostream& os, const Rectangle& rect)
{
	os << "(" << rect.getX() << ", " << rect.getY() << ", " << rect.getWidth() << ", " << rect.getHeight() << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rect)
{
	int x, y, width, height;
	is >> x >> y >> width >> height;
	rect.start.setX(x);
	rect.start.setY(y);
	rect.size = Size(width, height);
	return is;
}

Rectangle operator+(Rectangle lhs, const Point& rhs)
{
	lhs += rhs;
	return lhs;
}

Rectangle operator-(Rectangle lhs, const Point& rhs)
{
	lhs -= rhs;
	return lhs;
}
