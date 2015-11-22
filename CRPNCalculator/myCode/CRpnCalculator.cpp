/*
 * CRpnCalculator.cpp
 *
 *  Created on: 19-Nov-2015
 *      Author: Shashank_Ravindra
 */
#include "CRpnCalculator.h"
#include"CLifoBuffer.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

CRpnCalculator::CRpnCalculator()
{

}
bool CRpnCalculator::pushValue(const CFraction& data)
{

	return stack.push(data);

}
bool CRpnCalculator::popResult(CFraction& data)
{

	return stack.pop(data);

}
void CRpnCalculator::add()
{
	CFraction a, b, c;
	bool x, y;

	x = popResult(a);
	y = popResult(b);

	if (x && y)
	{
		c = a + b;
		pushValue(c);
	}
	else
	{
		cerr << "Out of memory" << endl;
	}
}
void CRpnCalculator::subtract()
{
	CFraction a, b, c;
	bool x, y;

	y = popResult(b);
	x = popResult(a);


	if (x && y)
	{
		c = a - b;
		pushValue(c);
	}
	else
	{
		cerr << "Out of memory" << endl;
	}
}
void CRpnCalculator::multiply()
{
	CFraction a, b, c;
	bool x, y;

	x = popResult(a);
	y = popResult(b);

	if (x && y)
	{
		c = b*a;
		pushValue(c);
	}
	else
	{
		cerr << "Out of memory" << endl;
	}
}
void CRpnCalculator::divide()
{
	CFraction a, b, c;
	bool x, y;

	x = popResult(a);
	y = popResult(b);

	if (x && y)
	{
		c = b/a;
		pushValue(c);
	}
	else
	{
		cerr << "Out of memory" << endl;
	}
}

