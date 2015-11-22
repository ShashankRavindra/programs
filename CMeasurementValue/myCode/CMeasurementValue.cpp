/*
 * CMeasurementValue.cpp
 *
 *  Created on: 26-Oct-2015
 *      Author: Shashank_Ravindra
 */
#include "CMeasurementValue.h"
#include <iostream>
#include <iomanip>
#include "math.h"
#include "stdlib.h"
using namespace std;

CMeasurementValue::CMeasurementValue(double value, t_unit unit)
{
	m_value = value;
	m_unit = unit;
	m_time = 0;

//	cout << "The address of the Object is: " << this << endl;
}
void CMeasurementValue::setValue(double value, t_unit unit)
{
	m_value = value;
	m_unit = unit;
	m_time = 0;

//	cout << "The value is: " << m_value << " and the unit is " << m_unit
//			<< endl;
	cout << "The address of the Object is: " << this << endl;
}
void CMeasurementValue::print()
{
	cout << "The value is: " << m_value;

	switch (m_unit)
	{
	case A:
		cout << " and the unit is Amphere" << endl;
		break;
	case V:
		cout << " and the unit is Volts" << endl;
		break;
	case S:
		cout << " and the unit is seconds" << endl;
		break;
	case W:
		cout << " and the unit is Watts" << endl;
		break;
	default:
		cerr << " and the unit is invalid" << endl;
		break;
	}
}
void CMeasurementValue::setTime(unsigned short hh, unsigned short mm,
		unsigned short ss)
{

	unsigned short hours = hh;
	unsigned short min = mm;
	unsigned short sec = ss;

	if ((hours >= 0 && hours <= 23) && (min >= 0 && min <= 59)
			&& (sec >= 0 && sec <= 59))
	{
		m_value = (hours * 3600) + (min * 60) + sec;
	}
	else
	{
		cerr << "The time entered is wrong" << hours << ":" << min << ":" << sec
				<< endl;
	}
}
void CMeasurementValue::getTime(unsigned short& hh, unsigned short& mm,
		unsigned short& ss)
{
	unsigned short temp;
	temp = m_value;
	hh = m_value / 3600;
	temp = temp % 3600;
	mm = temp / 60;
	ss = temp % 60;

}
void CMeasurementValue::printWithTime()
{
	unsigned short hh, mm, ss;
	CMeasurementValue::getTime(hh, mm, ss);
	cout << "The actual time is:: " << setfill('0') << setw(2) << hh << ":"
			<< setfill('0') << setw(2) << mm << ":" << setfill('0') << setw(2)
			<< ss;
	cout << endl;
}
double CMeasurementValue::getValue()
{
	return m_value;
}

CMeasurementValue::~CMeasurementValue()
{

}

double createRandomValue(int min, int max)
{
	float r = (float) rand() / (float) RAND_MAX;
	return min + r * (max - min);
}

