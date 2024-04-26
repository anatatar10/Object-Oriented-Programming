#include"image.h"
#include<iostream>
#include<ostream>
#include<fstream>

Image::Image() : m_data{ nullptr }, m_width{ 0 }, m_height{ 0 } {}

Image::Image(unsigned int w, unsigned int h)
{
	this->m_width = w;
	this->m_height = h;
	this->m_data = new unsigned char* [h];
	for (unsigned int i = 0; i < h; i++)
	{
		m_data[i] = new unsigned char[w];
		for (unsigned int j = 0; j < w; j++)
		{
			m_data[i][j] = 0;
		}
	}
}

unsigned int Image::width() const
{
	return this->m_width;
}

unsigned int Image::height() const
{
	return this->m_height;
}

Image::Image(const Image& other)
{
	*this = other;
}

Image::~Image()
{
	release();
}

Image& Image::operator=(const Image& other)
{
	if (this == &other) //this gives the address
	{
		return *this;
	}

	this->m_width = other.m_width;
	this->m_height = other.m_height;
	this->m_data = new unsigned char* [m_height];
	for (int i = 0; i < m_height; i++)
	{
		m_data[i] = new unsigned char[m_width];
		for (int j = 0; j < m_width; j++)
		{
			m_data[i][j] = other.m_data[i][j];
		}
	}
	return *this;
}

Image Image::operator+(const Image& imag)
{
	if (this->m_width == imag.m_width && this->m_height == imag.m_height)
	{
		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
			{
				int result = m_data[i][j] + imag.m_data[i][j];
				if (result > 255)
					result = 255;
				m_data[i][j] = result;
			}
		}
	}
	return *this;
}

Image Image::operator-(const Image& imag)
{
	if (this->m_width == imag.m_width && this->m_height == imag.m_height)
	{
		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
			{
				int result = m_data[i][j] - imag.m_data[i][j];
				if (result < 0)
					result = 0;
				m_data[i][j] = result;
			}
		}
	}
	return *this;
}

Image Image::operator*(const Image& imag)
{
	if (this->m_width == imag.m_width && this->m_height == imag.m_height)
	{
		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
			{
				int result = m_data[i][j] * imag.m_data[i][j];
				if (result > 255)
					result = 255;
				m_data[i][j] = result;
			}
		}
	}
	return *this;
}

bool Image::getROI(Image& roiImg, Rectangle roiRect)
{
	if (roiRect.getX() + roiRect.getWidth() > this->m_width)
		return false;
	if (roiRect.getY() + roiRect.getHeight() > this->m_height)
		return false;
	roiImg.release();
	roiImg = Image(roiRect.getWidth(), roiRect.getHeight());
	for (int i = roiRect.getY(); i < roiRect.getY() + roiRect.getHeight(); i++)
	{
		unsigned char* p1, * p2;
		p1 = *(roiImg.m_data + i - roiRect.getY());
		p2 = *(this->m_data + i);
		for (int j = roiRect.getX(); i < roiRect.getX() + roiRect.getWidth(); i++)
		{
			*p1 = *(p2 + roiRect.getX());
			p1++;
			p2++;
		}
		//roiImg.m_data[i - roiRect.getY()][j - roiRect.getX()] = this->m_data[i][j];
	}
	return true;
}

bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	Rectangle rct(x, y, width, height);
	return getROI(roiImg, rct);

}

bool Image::isEmpty() const
{
	if (this->m_data == nullptr || this->m_width == 0 || this->m_height == 0)
		return true;
	return false;
}

void Image::release()
{
	if (this->m_data != nullptr)
	{
		for (int i = 0; i < m_height; i++)
		{
			delete[] m_data[i];
		}
		delete[] m_data;
		m_data = nullptr;
	}
	this->m_height = 0;
	this->m_width = 0;
}

Size Image::size() const
{
	return Size(this->m_width, this->m_height);
}

//unsigned int width, height

unsigned char& Image::at(unsigned int y, unsigned int x)
{
	if (x < this->m_width && y < this->m_height)
		return this->m_data[y][x];
	exit(1);
}

unsigned char& Image::at(Point pt)
{
	return at(pt.getX(), pt.getY());
}

static Image zeros(unsigned int width, unsigned int height)
{
	return Image(width, height);
}

static Image ones(unsigned int width, unsigned int height)
{
	Image img(width, height);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img.setPixel(i, j, 1);
		}
	}
	return img;
}


void Image::setPixel(unsigned int x, unsigned int y, unsigned char value)
{
	m_data[x][y] = value;
}

unsigned char* Image::row(int y)
{
	if (y < this->m_height)
	{
		return this->m_data[y];
	}
	exit(1);
}

bool Image::load(std::string imagePath)
{
	std::ifstream file(imagePath, std::ios::binary);
	if (!file.is_open())
	{
		return false;
	}
	std::string type;
	file >> type;
	unsigned int width, height;
	unsigned int maxVal;
	file >> width >> height >> maxVal;
	if (type != "P5")
	{
		return false;
	}
	if (maxVal != 255)
	{
		return false;
	}
	release();
	m_width = width;
	m_height = height;
	this->m_data = new unsigned char* [height];
	for (int i = 0; i < height; i++)
	{
		m_data[i] = new unsigned char[width];
		file.read(reinterpret_cast<char*>(m_data[i]), m_width);
	}
	file.close();
	return true;
}

bool Image::save(std::string imagePath)
{
	std::ofstream file(imagePath, std::ios::binary);
	if (!file.is_open())
	{
		return false;
	}
	file << "P5\n";

	file << this->m_width << " " << this->m_height << "\n";
	file << "255" << "\n";
	for (int i = 0; i < m_height; i++)
	{
		file.write(reinterpret_cast<char*>(m_data[i]), m_width);
	}
	file.close();
	return true;

}

std::ostream& operator<<(std::ostream& os, const Image& dt)
{
	for (int i = 0; i < dt.m_height; i++)
	{
		for (int j = 0; j < dt.m_width; j++)
		{
			os << static_cast<int>(dt.m_data[i][j]) << " ";
		}
		os << "\n";
	}
	return os;
}

unsigned char Image::getPixel(unsigned int x, unsigned int y) const
{
	return this->m_data[x][y];
}