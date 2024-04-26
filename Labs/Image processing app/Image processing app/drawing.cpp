#include"image.h"
#include"point.h"
#include"rectangle.h"

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
    Point p1(r.getX(), r.getY()), p2(r.getX()+r.getWidth(), r.getY()+r.getHeight());
    drawLine(img, p1, Point(p1.getX(), p1.getY()), color);
    drawLine(img, p1, Point(p1.getX(), p2.getY()), color);
    drawLine(img, Point(p2.getY(), p1.getY()), p2, color);
    drawLine(img, Point(p1.getX(), p2.getY()), p2, color);
}

void drawRectangle(Image& img, Point tl, Point br, unsigned char color)
{
    drawRectangle(img, Rectangle(tl, br), color);
}