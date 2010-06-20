#include "StdAfx.h"
#include "ColorSpaceConvert.h"
#include "swscale.h"

CColorSpaceConvert::CColorSpaceConvert(void)
{
}

CColorSpaceConvert::~CColorSpaceConvert(void)
{
}

void yv12_to_yv12_c(uint8_t * y_dst, uint8_t * u_dst, uint8_t * v_dst,
				int y_dst_stride, int uv_dst_stride,
				uint8_t * y_src, uint8_t * u_src, uint8_t * v_src,
				int y_src_stride, int uv_src_stride,
				int width, int height, int vflip)
{
	int width2 = width / 2;
	int height2 = height / 2;
	int y;

	if (vflip) {
		y_src += (height - 1) * y_src_stride;
		u_src += (height2 - 1) * uv_src_stride;
		v_src += (height2 - 1) * uv_src_stride;
		y_src_stride = -y_src_stride;
		uv_src_stride = -uv_src_stride;
	}

	for (y = height; y; y--) {
		memcpy(y_dst, y_src, width);
		y_src += y_src_stride;
		y_dst += y_dst_stride;
	}

	for (y = height2; y; y--) {
		memcpy(u_dst, u_src, width2);
		u_src += uv_src_stride;
		u_dst += uv_dst_stride;
	}

	for (y = height2; y; y--) {
		memcpy(v_dst, v_src, width2);
		v_src += uv_src_stride;
		v_dst += uv_dst_stride;
	}
}

bool CColorSpaceConvert::RGB24_To_I420(unsigned char* pI420,unsigned char* pRGB24,int nWidth,int nHeight,bool bVFlip)
{
	SwsContext* swsc = NULL;
	unsigned char* pSrcI420 = NULL;
	bool bRet = false;
	do
	{
		SwsParams params;
		memset(&params,0,sizeof(params));
		params.cpu=0;
		params.methodLuma.method=params.methodChroma.method=SWS_POINT;

		swsc=sws_getContext(nWidth,nHeight,IMGFMT_BGR24,nWidth,nHeight,IMGFMT_I420,&params,NULL,NULL,NULL);
		if(swsc == NULL)
		{
			break;
		}

		BYTE* srcImage[3];
		srcImage[0]=pRGB24;
		srcImage[1]=NULL;
		srcImage[2]=NULL;
		int srcStride[3];
		srcStride[0]=nWidth*3;
		srcStride[1]=0;
		srcStride[2]=0;

		pSrcI420 = new unsigned char[nWidth * nHeight * 3 / 2];
		if(pSrcI420 == NULL)
		{
			break;
		}

		BYTE* dstImage[3];
		dstImage[0]=pSrcI420;
		dstImage[1]=dstImage[0]+nWidth*nHeight;
		dstImage[2]=dstImage[1]+nWidth*nHeight/4;
		int dstStride[3];
		dstStride[0]=nWidth;
		dstStride[1]=nWidth>>1;
		dstStride[2]=nWidth>>1;

		if(sws_scale_ordered(swsc,srcImage,srcStride,0,nHeight,dstImage,dstStride)>0)
		{
			BYTE* pDstYuv[3];
			pDstYuv[0]=pI420; 										
			pDstYuv[1]=pDstYuv[0] + nWidth * nHeight; 		
			pDstYuv[2]=pDstYuv[1] + nWidth * nHeight / 4;		

			int nDstStride[3];
			nDstStride[0]=nWidth; 
			nDstStride[1]=nWidth/2;
			nDstStride[2]=nWidth/2;

			yv12_to_yv12_mmx(pDstYuv[0],pDstYuv[1],pDstYuv[2],nDstStride[0],nDstStride[1],
				dstImage[0],dstImage[1],dstImage[2],dstStride[0],dstStride[1],nWidth,nHeight,bVFlip ? 1 : 0);

			bRet = true;		
		}
		
	}while(0);

	if(pSrcI420)
	{
		delete []pSrcI420;
		pSrcI420 = NULL;
	}
	if(swsc)
	{
		sws_freeContext(swsc);
		swsc = NULL;
	}
	return bRet;
}

bool CColorSpaceConvert::YUY2_To_I420(unsigned char* pI420,unsigned char* pYUY2,int nWidth,int nHeight,bool bVFlip)
{
	SwsContext* swsc = NULL;
	bool bRet = false;
	do
	{
		SwsParams params;
		memset(&params,0,sizeof(params));
		params.cpu=0;
		params.methodLuma.method=params.methodChroma.method=SWS_POINT;

		swsc=sws_getContext(nWidth,nHeight,IMGFMT_YUY2,nWidth,nHeight,IMGFMT_YV12,&params,NULL,NULL,NULL);
		if(swsc == NULL)
		{
			break;
		}

		BYTE* srcImage[3];
		srcImage[0]=pYUY2;
		srcImage[1]=NULL;
		srcImage[2]=NULL;
		int srcStride[3];
		srcStride[0]=nWidth*2;
		srcStride[1]=0;
		srcStride[2]=0;

		BYTE* dstImage[3];
		dstImage[0]=pI420;
		dstImage[1]=dstImage[0]+nWidth*nHeight;
		dstImage[2]=dstImage[1]+nWidth*nHeight/4;
		int dstStride[3];
		dstStride[0]=nWidth;
		dstStride[1]=nWidth>>1;
		dstStride[2]=nWidth>>1;

		if(sws_scale_ordered(swsc,srcImage,srcStride,0,nHeight,dstImage,dstStride)>0)
		{
			bRet = true;		
		}
		
	}while(0);

	if(swsc)
	{
		sws_freeContext(swsc);
		swsc = NULL;
	}
	return bRet;
}

bool CColorSpaceConvert::RGB32_To_I420(unsigned char* pI420,unsigned char* pRGB32,int nWidth,int nHeight,bool bVFlip)
{
	SwsContext* swsc = NULL;
	unsigned char* pSrcI420 = NULL;
	bool bRet = false;
	do
	{
		SwsParams params;
		memset(&params,0,sizeof(params));
		params.cpu=0;
		params.methodLuma.method=params.methodChroma.method=SWS_POINT;

		swsc=sws_getContext(nWidth,nHeight,IMGFMT_BGR32,nWidth,nHeight,IMGFMT_I420,&params,NULL,NULL,NULL);
		if(swsc == NULL)
		{
			break;
		}

		BYTE* srcImage[3];
		srcImage[0]=pRGB32;
		srcImage[1]=NULL;
		srcImage[2]=NULL;
		int srcStride[3];
		srcStride[0]=nWidth*4;
		srcStride[1]=0;
		srcStride[2]=0;

		pSrcI420 = new unsigned char[nWidth * nHeight * 3 / 2];
		if(pSrcI420 == NULL)
		{
			break;
		}

		BYTE* dstImage[3];
		dstImage[0]=pSrcI420;
		dstImage[1]=dstImage[0]+nWidth*nHeight;
		dstImage[2]=dstImage[1]+nWidth*nHeight/4;
		int dstStride[3];
		dstStride[0]=nWidth;
		dstStride[1]=nWidth>>1;
		dstStride[2]=nWidth>>1;

		if(sws_scale_ordered(swsc,srcImage,srcStride,0,nHeight,dstImage,dstStride)>0)
		{
			BYTE* pDstYuv[3];
			pDstYuv[0]=pI420; 										
			pDstYuv[1]=pDstYuv[0] + nWidth * nHeight; 		
			pDstYuv[2]=pDstYuv[1] + nWidth * nHeight / 4;		

			int nDstStride[3];
			nDstStride[0]=nWidth; 
			nDstStride[1]=nWidth/2;
			nDstStride[2]=nWidth/2;

			yv12_to_yv12_mmx(pDstYuv[0],pDstYuv[1],pDstYuv[2],nDstStride[0],nDstStride[1],
				dstImage[0],dstImage[1],dstImage[2],dstStride[0],dstStride[1],nWidth,nHeight,bVFlip ? 1 : 0);

			bRet = true;		
		}
		
	}while(0);

	if(pSrcI420)
	{
		delete []pSrcI420;
		pSrcI420 = NULL;
	}
	if(swsc)
	{
		sws_freeContext(swsc);
		swsc = NULL;
	}
	return bRet;
}
