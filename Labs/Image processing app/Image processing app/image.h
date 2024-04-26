#pragma once
#include<string>
#include"rectangle.h"

class Image
{
public:
	Image();
	Image(unsigned int w, unsigned int h);
	Image(const Image& other);

	~Image();

	bool load(std::string imagePath);
	bool save(std::string imagePath);

	Image& operator=(const Image& other);

	Image operator+(const Image& other);
	Image operator-(const Image& other);
	Image operator*(const Image& other);

	bool getROI(Image& roiImg, Rectangle roiRect);
	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	bool isEmpty() const;

	Size size() const;

	unsigned int width() const;
	unsigned int height() const;

	unsigned char& at(unsigned int x, unsigned int y);

	unsigned char& at(Point pt);

	unsigned char* row(int y);

	void release();

	friend std::ostream& operator<<(std::ostream& os, const Image& dt);

	static Image zeros(unsigned int width, unsigned int height);
	static Image ones(unsigned int width, unsigned int height);

	void setPixel(unsigned int x, unsigned int y, unsigned char value);

	unsigned char getPixel(unsigned int x, unsigned int y) const;
	friend class ImageTest;
private:
	unsigned char** m_data;
	unsigned int m_width;
	unsigned int m_height;
};
