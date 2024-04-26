#pragma once
#include"ImageProcessing.h"
class ImageConvultion : public ImageProcessing
{
public:
	ImageConvultion(unsigned int k, unsigned char** kernel);
	void process(const Image& src, Image& dst) override;

private:
	unsigned int k;
	unsigned char** kernel;

};

