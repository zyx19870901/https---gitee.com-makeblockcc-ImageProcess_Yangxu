#ifndef _PROCESS_H_
#define _PROCESS_H_

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/photo.hpp"

// #include <opencv2\core\core.hpp>
// #include <opencv2\imgcodecs\imgcodecs.hpp>
// #include <opencv2\imgproc\imgproc.hpp>
// #include <opencv2\highgui\highgui.hpp>
// #include <opencv2\calib3d\calib3d.hpp>

#include "ColorDetector.h"
#include "circle_code.h"
// #include "stb_image.h"
// #include "stb_image_write.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;
using namespace cv;

void delBackground(const Mat& src, Mat& dst);

void undistortImage(const Mat &src, Mat &dst/*, float &height*/);

void autoFocusImage(const Mat &image, float* height);

void findPosImage(const Mat &image, float* pos_x, float* pos_y);

void getExposureCam(int* exposure);

void easyFunImg(const Mat &image, float* x, float* y, vector<vector<float> > &b);

void cvThin(const Mat& src, Mat& dst, int intera);//细化算法

void cvDilate(const Mat& src, Mat& dst, int ksize);

void cutRedline(const Mat& src, vector<vector<Point> > &contours);

void cutBlackline(const Mat& src, Mat& mask, vector<vector<Point> > &contours);

void autoThreshold(const Mat &src, Mat &dst);

bool findLogo(const Mat& src, const Mat& mask);

#endif //_PROCESS_H_
