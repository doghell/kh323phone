#pragma once

#include "inttypes.h"

extern "C" void yv12_to_yv12_mmx(uint8_t * y_dst, uint8_t * u_dst, uint8_t * v_dst,
				int y_dst_stride, int uv_dst_stride,
				uint8_t * y_src, uint8_t * u_src, uint8_t * v_src,
				int y_src_stride, int uv_src_stride,
				int width, int height, int vflip);

class CColorSpaceConvert
{
public:
	CColorSpaceConvert(void);
	virtual ~CColorSpaceConvert(void);

	bool RGB24_To_I420(unsigned char* pI420,unsigned char* pRGB24,int nWidth,int nHeight,bool bVFlip = true);
	bool YUY2_To_I420(unsigned char* pI420,unsigned char* pYUY2,int nWidth,int nHeight,bool bVFlip = true);
	bool RGB32_To_I420(unsigned char* pI420,unsigned char* pRGB32,int nWidth,int nHeight,bool bVFlip = true);
};
