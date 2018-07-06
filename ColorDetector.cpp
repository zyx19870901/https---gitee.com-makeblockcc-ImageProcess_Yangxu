#include "ColorDetector.h"

ColorDetector::ColorDetector() :minDist(100)
{
	target[0] = target[1] = target[2] = 0;
}

ColorDetector::~ColorDetector()
{
}

void ColorDetector::setColorDistanceThreshold(int distance)
{
	if (distance < 0)
		distance = 0;
	minDist = distance;
}

int ColorDetector::getColorDistanceThreshold() const
{
	return minDist;
}

void ColorDetector::setTargetColor(unsigned char red, unsigned char green, unsigned char blue)
{
	target[2] = red;
	target[1] = green;
	target[0] = blue;
}

void ColorDetector::setTargetColor(Vec3b color)
{
	target = color;
}

Vec3b ColorDetector::getTargetColor() const
{
	return target;
}

Mat ColorDetector::process(const Mat & image)
{
	//按需重新分配二值图像
	//与输入图像的尺寸相同，但是只有一个通道
	result.create(image.rows, image.cols, CV_8U);

	//得到迭代器
	Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
	Mat_<uchar>::iterator itout = result.begin<uchar>();
	for (; it != itend; ++it, ++itout)//处理每个像素
	{
		//计算离目标颜色的距离
		if (getDistance(*it) < minDist)
		{
			*itout = 255;
		}
		else
		{
			*itout = 0;
		}
	}
	return result;
}

Mat ColorDetector::redSelect(const Mat & image)
{
	result.create(image.rows, image.cols, CV_8U);

	//得到迭代器
	Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
	Mat_<uchar>::iterator itout = result.begin<uchar>();
	for (; it != itend; ++it, ++itout)//处理每个像素
	{
		if (isRed(*it))
		{
			*itout = 255;
		}
		else
		{
			*itout = 0;
		}
	}
	return result;
}
Mat ColorDetector::blackSelect(const Mat & image)
{
	result.create(image.rows, image.cols, CV_8U);

	//得到迭代器
	Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
	Mat_<uchar>::iterator itout = result.begin<uchar>();
	for (; it != itend; ++it, ++itout)//处理每个像素
	{
		if (isBlack(*it))
		{
			*itout = 255;
		}
		else
		{
			*itout = 0;
		}
	}
	return result;
}
Mat ColorDetector::whiteSelect(const Mat & image)
{
	result.create(image.rows, image.cols, CV_8U);

	//得到迭代器
	Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
	Mat_<uchar>::iterator itout = result.begin<uchar>();
	for (; it != itend; ++it, ++itout)//处理每个像素
	{
		if (isWhite(*it))
		{
			*itout = 255;
		}
		else
		{
			*itout = 0;
		}
	}
	return result;
}

bool ColorDetector::isRed(Vec3b color)
{
	int R = color[2];
	int G = color[1];
	int B = color[0];
	bool bRed = ((R - G) > 8) && ((R - B) > 8);
	bool bWhite = (color[0] > 200) && (color[1] > 200) && (color[2] > 200);
	if (bRed && !bWhite)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ColorDetector::isBlack(Vec3b color)
{
	int R = color[2];
	int G = color[1];
	int B = color[0];
	bool bBlack = (R < 200) && (G < 100) && (B < 200);
	bool bRed = ((R - G) > 8) && ((R - B) > 8);
	if (bBlack && !bRed)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
bool ColorDetector::isWhite(Vec3b color)
{
	if ((color[0] > 200) && (color[1] > 200) && (color[2] > 200))
	{
		return true;
	}
	else
	{
		return false;
	}
}