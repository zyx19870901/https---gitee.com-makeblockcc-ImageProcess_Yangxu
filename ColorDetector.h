//#pragma once
//#include <opencv2\opencv.hpp>	//opencv3.2.0
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

class ColorDetector
{
public:
	ColorDetector();
	~ColorDetector();

private:
	int minDist;	//最小可接受距离
	Vec3b target;	//目标色
	Mat result;		//结果图像
	int getDistance(Vec3b color) {
	return abs(color[0] - target[0]) + abs(color[1] - target[1]) + abs(color[2] - target[2]);
	}
public:
	//设置颜色距离阈值
	void setColorDistanceThreshold(int distance);
	//获取颜色距离阈值
	int getColorDistanceThreshold() const;
	//设置目标颜色RGB(分量形式)
	void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
	//设置目标颜色RGB(向量形式)
	void setTargetColor(Vec3b color);
	//获取目标颜色
	Vec3b getTargetColor() const;
	//颜色检测处理（原图像-->目标颜色二值图像）
	Mat process(const cv::Mat &image);

	//红色提取处理（原图像-->目标颜色二值图像）
	Mat redSelect(const cv::Mat &image);
	//黑色提取处理（原图像-->目标颜色二值图像）
	Mat blackSelect(const cv::Mat &image);
	//白色提取处理（原图像-->目标颜色二值图像）
	Mat whiteSelect(const cv::Mat &image);

	//红色判断
	bool isRed(Vec3b color);
	//黑色判断
	bool isBlack(Vec3b color);
	//白色判断
	bool isWhite(Vec3b color);
};
