#pragma once

class Size {
private:
	unsigned int width, height;
public:
	Size();
	Size(unsigned int width, unsigned int height);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	friend class RectangleTest;
	friend class SizeTest;
};
