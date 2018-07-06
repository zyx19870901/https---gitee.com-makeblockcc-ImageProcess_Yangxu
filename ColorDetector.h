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
	int minDist;	//��С�ɽ��ܾ���
	Vec3b target;	//Ŀ��ɫ
	Mat result;		//���ͼ��
	int getDistance(Vec3b color) {
	return abs(color[0] - target[0]) + abs(color[1] - target[1]) + abs(color[2] - target[2]);
	}
public:
	//������ɫ������ֵ
	void setColorDistanceThreshold(int distance);
	//��ȡ��ɫ������ֵ
	int getColorDistanceThreshold() const;
	//����Ŀ����ɫRGB(������ʽ)
	void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
	//����Ŀ����ɫRGB(������ʽ)
	void setTargetColor(Vec3b color);
	//��ȡĿ����ɫ
	Vec3b getTargetColor() const;
	//��ɫ��⴦��ԭͼ��-->Ŀ����ɫ��ֵͼ��
	Mat process(const cv::Mat &image);

	//��ɫ��ȡ����ԭͼ��-->Ŀ����ɫ��ֵͼ��
	Mat redSelect(const cv::Mat &image);
	//��ɫ��ȡ����ԭͼ��-->Ŀ����ɫ��ֵͼ��
	Mat blackSelect(const cv::Mat &image);
	//��ɫ��ȡ����ԭͼ��-->Ŀ����ɫ��ֵͼ��
	Mat whiteSelect(const cv::Mat &image);

	//��ɫ�ж�
	bool isRed(Vec3b color);
	//��ɫ�ж�
	bool isBlack(Vec3b color);
	//��ɫ�ж�
	bool isWhite(Vec3b color);
};
