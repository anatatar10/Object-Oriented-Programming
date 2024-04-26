#include "BrightnessAndContrast.h"
#include "image.h"


BrightnessAndConstrast::BrightnessAndConstrast()
{
	gain = 1;
	bias = 0;
}

BrightnessAndConstrast::BrightnessAndConstrast(double gain, double bias)
{
	this->gain = gain;
	this->bias = bias;
}

void BrightnessAndConstrast::process(const Image& src, Image& dst) 
{
	double aux;
	dst = Image(src);
	for (unsigned int i = 0; i < src.height(); i++)
	{
		for (unsigned int j = 0; j < src.width(); j++)
		{
			aux = gain * dst.at(i, j) + bias;
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
