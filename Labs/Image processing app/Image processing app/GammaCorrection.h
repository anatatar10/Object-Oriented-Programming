#pragma once
#include"ImageProcessing.h"
class GammaCorrection : public ImageProcessing
{
public:
	GammaCorrection();
	GammaCorrection(double gamma);
	void process(const Image& src, Image& dst) override;

private:
	double gamma;
};

