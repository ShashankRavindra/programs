/*
 * CMeasurementValue.h
 *
 *  Created on: 26-Oct-2015
 *      Author: Shashank_Ravindra
 */

#ifndef CMEASUREMENTVALUE_H_
#define CMEASUREMENTVALUE_H_

enum t_unit
{
	A, V, S, W, NONE
};

class CMeasurementValue
{
private:
	double m_value;
	t_unit m_unit;
	unsigned int m_time;

public:
	CMeasurementValue(double value = 0, t_unit unit = NONE);
	void setValue(double value, t_unit unit);
	void print();
	void setTime(unsigned short hh, unsigned short mm, unsigned short ss);
	void getTime(unsigned short& hh, unsigned short& mm, unsigned short& ss);
	void printWithTime();
	double getValue();
	~CMeasurementValue();
};

double createRandomValue(int min, int max);

#endif /* CMEASUREMENTVALUE_H_ */
