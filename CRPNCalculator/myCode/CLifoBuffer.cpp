/*
 * CLifoBuffer.cpp
 *
 *  Created on: 19-Nov-2015
 *      Author: Shashank_Ravindra
 */
#include"CLifoBuffer.h"
#include "CFraction.h"
#include <iostream>
using namespace std;

CLifoBuffer::CLifoBuffer(int size)
{
	m_size = size;
	m_tos = -1;
	m_pBuffer = new CFraction[m_size];

//	cout << "The size " << m_size << " the content of the buffer " << &m_pBuffer
//			<< endl;
}
CLifoBuffer::~CLifoBuffer()
{
	delete[] m_pBuffer;
}
void CLifoBuffer::print()
{
	cout << " The maximum size of the buffer is " << m_size << endl;
	for (int i = 0; i < m_size; i++)
	{
		cout << " The content of the buffer is " << m_pBuffer[i] << endl;
	}
}
bool CLifoBuffer::push(const CFraction& data)
{

	if (m_tos == m_size - 1)
	{
		return false;
	}
	else
	{
		m_tos++;
		m_pBuffer[m_tos] = data;
		cout << "The value pushed " << m_pBuffer[m_tos] << " at position "
				<< m_tos << endl;
		return true;

	}

}
bool CLifoBuffer::pop(CFraction& data)
{
	if (m_tos == -1)
	{
		return false;

	}
	else
	{
		data = this->m_pBuffer[m_tos];
		m_tos--;
		return true;
	}

}
