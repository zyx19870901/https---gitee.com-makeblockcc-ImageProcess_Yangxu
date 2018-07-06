#include "FrameProcessor.h"
#include "Process.h"
#include "circle_code.h"
#include <string>

std::vector<uchar> outData;

FRAME_PROCESS_RET frame2Mat(FRAME frame, cv::Mat &image)
{
	std::vector<uchar> frame_mat_outData;
	frame_mat_outData.clear();
	
	frame_mat_outData.resize(frame.len);
	frame_mat_outData.assign(frame.data, frame.data + frame.len);
	image = cv::imdecode(cv::Mat(frame_mat_outData), CV_LOAD_IMAGE_COLOR);  
	std::cout << "len: " << frame.len << std::endl;

	return FRAME_PROCESS_SUCCESS;
}

FRAME_PROCESS_RET mat2Frame(cv::Mat& image, FRAME* newFrame)
{
	outData.clear();
	std::cout << "enter mat2Frame()" << std::endl;

    if (image.empty())
    {
        std::cout << "Image Load Failed!" << std::endl;
        return FRAME_PROCESS_FAILED;
    }

	cv::imencode(".jpg", image, outData);
	std::cout << "imencode()" << std::endl;
	newFrame->data = outData.data();
	newFrame->height = image.size().height;
	newFrame->width = image.size().width;
	newFrame->len = outData.size();
		
	return FRAME_PROCESS_SUCCESS;
}

FRAME_PROCESS_RET init()
{
	return FRAME_PROCESS_SUCCESS;
}

FRAME_PROCESS_RET uninit()
{
	return FRAME_PROCESS_SUCCESS;
}

FRAME_PROCESS_RET undistort(FRAME frame, FRAME* newFrame)
{
	std::cout << "enter undistort()" << std::endl; 
	cv::Mat srcImage, dstImage;
	frame2Mat(frame, srcImage);

	undistortImage(srcImage, dstImage/*, c_height*/);
	std::cout << "out undistortImage()" << std::endl;
	mat2Frame(dstImage, newFrame);
	return FRAME_PROCESS_SUCCESS;
}

FRAME_PROCESS_RET autoFocus(FRAME frame, float* height)
{
	// std::cout << "autoFocus:" << std::endl;

	cv::Mat tmpImage;
	frame2Mat(frame, tmpImage);
	autoFocusImage(tmpImage, height);
	return FRAME_PROCESS_SUCCESS;
}

FRAME_PROCESS_RET findPos(FRAME frame, float* pos_x, float* pos_y)
{
	cv::Mat tmpImage;
	frame2Mat(frame, tmpImage);
	findPosImage(tmpImage, pos_x, pos_y);
	return FRAME_PROCESS_SUCCESS;
}

FRAME_PROCESS_RET getExposureValue(int* exposure)
{
	getExposureCam(exposure);
	return FRAME_PROCESS_SUCCESS;
}

FRAME_PROCESS_RET easyFun(FRAME frame, float* x, float* y, std::vector<std::vector<float> > &b)
{
	std::cout << "enter easyFun()" << std::endl;
	cv::Mat tmpImage;
	frame2Mat(frame, tmpImage);
	std::cout << "out frame2Mat()" << std::endl;
	easyFunImg(tmpImage, x, y, b);
	std::cout << "b.size(): " << b.size() << std::endl;
	std::cout << "out easyFun()" << std::endl;
	return FRAME_PROCESS_SUCCESS;
}

//////////////////////////////新接口////////////////////////////////////////////