#include"image.h"
#include"ImageProcessing.h"
#include"BrightnessAndContrast.h"
#include"GammaCorrection.h"
#include"ImageConvultion.h"
#include <stdio.h>
#include"ImageTest.h"
#include"pointTest.h"
#include"RectangleTest.h"
#include"SizeTest.h"

void drawCircle(Image& img, Point center, int radius, unsigned char color)
{
    int x = radius, y = 0;
    int radiusError = 1 - x;

    while (x >= y)
    {
        img.at(center.getX() + x, center.getY() + y) = color;
        img.at(center.getX() + y, center.getY() + x) = color;
        img.at(center.getX() - y, center.getY() + x) = color;
        img.at(center.getX() - x, center.getY() + y) = color;
        img.at(center.getX() - x, center.getY() - y) = color;
        img.at(center.getX() - y, center.getY() - x) = color;
        img.at(center.getX() + y, center.getY() - x) = color;
        img.at(center.getX() + x, center.getY() - y) = color;
        y++;
        if (radiusError < 0)
        {
            radiusError += 2 * y + 1;
        }
        else
        {
            x--;
            radiusError += 2 * (y - x) + 1;
        }
    }
}

void drawLine(Image& img, Point p1, Point p2, unsigned char color)
{
    int x0 = p1.getX();
    int y0 = p1.getX();
    int x1 = p2.getY();
    int y1 = p2.getY();
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        img.at(x0, y0) = color;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
    img.at(x1, y1) = color;
}

void drawRectangle(Image& img, Rectangle r, unsigned char color)
{
    Point p1(r.getX(), r.getY()), p2(r.getX() + r.getWidth(), r.getY() + r.getHeight());
    drawLine(img, p1, Point(p1.getX(), p1.getY()), color);
    drawLine(img, p1, Point(p1.getX(), p2.getY()), color);
    drawLine(img, Point(p2.getY(), p1.getY()), p2, color);
    drawLine(img, Point(p1.getX(), p2.getY()), p2, color);
}

void drawRectangle(Image& img, Point tl, Point br, unsigned char color)
{
    drawRectangle(img, Rectangle(tl, br), color);
}


int main()

{
    ImageTest::runAllTests();
    pointTest::runAllTests();
    RectangleTest::runAllTests();
    SizeTest::runAllTests();
	Image img = Image();
	Image out = Image();
	img.load("sample1.pgm");
	img.save("test.pgm");

	BrightnessAndConstrast bc = BrightnessAndConstrast(3, 0.5);
	bc.process(img, out);
	out.save("sample1_out1.pgm");

	GammaCorrection g = GammaCorrection(0.5); //overall brightness
	out = Image();
	g.process(img, out);
	out.save("sample1_out2.pgm");

    Point p = Point(100, 100);
    drawCircle(img, p, 50, 'b');
    img.save("sample1_out3_circle.pgm");
    Point p1 = Point(200, 200);
    drawLine(img, p, p1, 'b');
    img.save("sample1_out3_circle_line.pgm");
    Point p2 = Point(300, 300);
    Point p3 = Point(100, 250);
    Rectangle r = Rectangle(p2, p3);
    drawRectangle(img, r, 'r');
    img.save("sample1_out3_circle_line_rectangle.pgm");

    Image img1 = Image();
    img1.load("dwsample-pgm-640.pgm");
    img1.save("test_dwsample-pgm-640.pgm");
    drawLine(img1, p, p1, 'b');
    img1.save("test_dwsample-pgm-640_circle_line.pgm");
	return 0;
}