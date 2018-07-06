#ifndef _FRAME_PROCESSOR_H_
#define _FRAME_PROCESSOR_H_

#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack (1)

typedef enum
{
	FRAME_PROCESS_SUCCESS = 0,
	FRAME_PROCESS_FAILED, 
}FRAME_PROCESS_RET;

typedef struct
{
	int len;
	int width;
	int height;
//	unsigned long long pts;
	unsigned char* data;
}FRAME;
#pragma pack ()

FRAME_PROCESS_RET init();
FRAME_PROCESS_RET uninit();

FRAME_PROCESS_RET getExposureValue(int* exposure);
FRAME_PROCESS_RET findPos(FRAME frame, float* pos_x, float* pos_y);
FRAME_PROCESS_RET undistort(FRAME frame, FRAME* newFrame);
FRAME_PROCESS_RET autoFocus(FRAME frame, float* height);
FRAME_PROCESS_RET easyFun(FRAME frame, float* x, float* y, std::vector<std::vector<float> > &b);

#ifdef __cplusplus
}
#endif

#endif //_FRAME_PROCESSOR_H_