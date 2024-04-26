#include "GammaCorrection.h"

GammaCorrection::GammaCorrection()
{
	gamma = 0;
}

GammaCorrection::GammaCorrection(double gamma)
{
	this->gamma = gamma;
}

void GammaCorrection::process(const Image& src, Image& dst)
{
	double aux;
	dst = Image(src);
	for (unsigned int i = 0; i < src.height(); i++)
	{
		for (unsigned int j = 0; j < src.width(); j++)
		{
			aux = pow(dst.at(i, j), gamma);
			if (aux > 255)
			{
				aux = 255;
			}
			else if (aux < 0)
			{
				aux = 0;
			}
			dst.at(i, j) = (int)aux;
		}
	}
}
