#include"size.h"

Size::Size() : width{ 0 }, height{ 0 } {}

Size::Size(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
}

unsigned int Size::getWidth() const
{
	return this->width;
}

unsigned int Size::getHeight() const
{
	return this->height;
}