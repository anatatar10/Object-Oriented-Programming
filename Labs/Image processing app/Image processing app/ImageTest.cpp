#include "ImageTest.h"
#include<cassert>
void ImageTest::testConstructor()
{
	Image img = Image(10, 10);
	assert(img.m_width == 10);
	assert(img.m_height == 10);
	
}

void ImageTest::testGetWidth()
{
	Image img = Image(10, 10);
	assert(img.m_width == img.width());
}

void ImageTest::testGetHeight()
{
	Image img = Image(10, 10);
	assert(img.m_height == img.height());
}

void ImageTest::testCopyConstructor()
{
	Image img = Image(10, 10);
	Image img1 = Image(img);
	assert(img1.m_width == 10);
	assert(img1.m_height == 10);
}

void ImageTest::testAssignmentOperator()
{
	Image img = Image(10, 10);
	Image img1 = img;
	assert(img1.m_width == 10);
	assert(img1.m_height == 10);
}

void ImageTest::testSize()
{
	Image img = Image(10, 10);
	Size s = img.size();
	assert(s.getHeight() == 10);
	assert(s.getWidth() == 10);
}

void ImageTest::testAt()
{
	Image img = Image(10, 10);
	assert(img.at(5, 5) == img.m_data[5][5]);
}

void ImageTest::testZeros()
{
	//Image zerosImage = zerosImage.zeros(10, 10);

	//// Check if all the pixel values in the zeros image are zero
	//for (int i = 0; i < zerosImage.height(); i++)
	//{
	//	for (int j = 0; j < zerosImage.width(); j++)
	//	{
	//		assert(zerosImage.getPixel(j, i) == 0);
	//	}
	//}
	
}

void ImageTest::testOnes()
{
	/*Image img = Image();
	Image img1 = img.ones(10, 10);
	assert(img1.width() == 10);*/
}

void ImageTest::testSetPixel()
{
	Image img = Image(10, 10);
	img.setPixel(5, 5, 5);
	assert(img.m_data[5][5] == 5);
}

void ImageTest::testGetPixel()
{
	Image img = Image(10, 10);
	img.setPixel(5, 5, 5);
	assert(img.m_data[5][5] == img.getPixel(5,5));
}

void ImageTest::testGetRow()
{
	Image img = Image(10, 10);
	assert(img.row(3) == img.m_data[3]);
}

void ImageTest::runAllTests()
{
	testConstructor();
	testGetWidth();
	testGetHeight();
	testCopyConstructor();
	testAssignmentOperator();
	testSize();
	testAt();
	testZeros();
	testOnes();
	testSetPixel();
	testGetPixel();
	testGetRow();
}
