#pragma once
#include"ImageProcessing.h"

class BrightnessAndConstrast : public ImageProcessing
{

public:
	BrightnessAndConstrast();
	BrightnessAndConstrast(double gain, double bias);
	void process(const Image& src, Image& dst) override;
private:
	double gain, bias;
};
