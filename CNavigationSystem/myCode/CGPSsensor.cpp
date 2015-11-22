/*
 * CGPSsensor.cpp
 *
 *  Created on: 02-Nov-2015
 *      Author: Shashank_Ravindra
 */
#include "CGPSsensor.h"
#include "CWayPoint.h"

#include <iostream>
#include <iomanip>
using namespace std;

CGPSsensor::CGPSsensor()
{

}
CWayPoint CGPSsensor::getCurrentPosition()
{
	string name = "";
	double latitude = 0;
	double longitude = 0;

	cout << "Enter name ";
	cin >> name;
	cout << endl;
	cout << "Enter latitude ";
	cin >> latitude;
	cout << endl;
	cout << "Enter longitude ";
	cin >> longitude;
	cout << endl;
	CWayPoint newPoint(name, latitude, longitude);
	return newPoint;
}
