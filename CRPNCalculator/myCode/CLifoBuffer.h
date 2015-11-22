/*
 * CLifoBuffer.h
 *
 *  Created on: 19-Nov-2015
 *      Author: Shashank_Ravindra
 */

#ifndef CLIFOBUFFER_H_
#define CLIFOBUFFER_H_

#include "CFraction.h"

class CLifoBuffer
{
private:
	int m_size;
	int m_tos;
	CFraction* m_pBuffer;

public:
	CLifoBuffer(int size = 15);
	~CLifoBuffer();
	void print();
	bool push(const CFraction& data);
	bool pop(CFraction& data);
};

#endif /* CLIFOBUFFER_H_ */
