#ifndef __HPQUEUEBUFFER_H__
#define __HPQUEUEBUFFER_H__

#include "AVAutoLock.h"

class HPQueueBuffer
{
public:
	HPQueueBuffer(int nBufferLen);
	virtual ~HPQueueBuffer(void);
public:
	int Read(char*pBuffer,int nLen);
	void Write(char*pData,int nLen);
protected:
	int GetFilledSize(void);
	int GetFreeSize(void);
	void MovePointer(char**p,int nOffset);
protected:
	AVCritSec		m_AVCritSecHPQueueBuffer;
	char*			m_pBufferHead;
	char*			m_pBufferTail;
	int				m_nBufferLen;
	char*			m_pFront;
	char*			m_pBack;
	bool			m_bEmpty;
};


#endif