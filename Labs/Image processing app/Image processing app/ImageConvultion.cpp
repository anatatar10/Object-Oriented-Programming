#include "ImageConvultion.h"
#include<cmath>

ImageConvultion::ImageConvultion(unsigned int k, unsigned char** kernel)
{

	this->k = k;
	this->kernel = new unsigned char* [k];
	for (int i = 0; i < k; i++)
	{
		this->kernel[i] = new unsigned char[k];
		for (int j = 0; j < k; j++)
		{
			this->kernel[i][j] = kernel[i][j];
		}
	}
}

void ImageConvultion::process(const Image& src, Image& dst)
{
	double aux = 0;
	dst = Image(src);
	for (int i = 0; i < src.height(); i++)
	{
		for (int j = 0; j < src.width(); j++)
		{
			aux = 0;
			for (int k1 = 0; k1 < this->k; k++)
			{
				for (int k2 = 0; k2 < this->k; k++)
				{
					int x, y;
					x = i + k1 - k / 2;
					y = j + k2 - k / 2;
					if (x >= 0 && x < src.height() && y >= 0 && y < src.width())
					{
						aux += src.getPixel(x, y) * this->kernel[k1][k2];
					}
				}
			}
			if (aux < 0)
			{
				aux = 0;
			}
			if (aux > 255)
			{
				aux = 255;
			}
			dst.setPixel(i, j, round(aux));
		}
	}

}