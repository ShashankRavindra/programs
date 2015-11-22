/*
 * CRpnCalculator.h
 *
 *  Created on: 19-Nov-2015
 *      Author: Shashank_Ravindra
 */

#ifndef CRPNCALCULATOR_H_
#define CRPNCALCULATOR_H_

#include "CLifoBuffer.h"
class CRpnCalculator
{
private:
	CLifoBuffer stack;

public:
	CRpnCalculator();
	bool pushValue(const CFraction& data);
	bool popResult(CFraction& data);
	void add();
	void subtract();
	void multiply();
	void divide();
};

#endif /* CRPNCALCULATOR_H_ */
