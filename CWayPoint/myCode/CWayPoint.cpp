/*
 * CWayPoint.cpp
 *
 *  Created on: 29-Oct-2015
 *      Author: Shashank_Ravindra
 */

#include "CWayPoint.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "math.h"
using namespace std;

#define RADIUS 6378
#define MMSS 2
#define DEGREE 1
#define PI 3.1417

CWayPoint::CWayPoint(string name, double latitude, double longitude)
{
	this->m_name = name;
	this->m_latitude = latitude;
	this->m_longitude = longitude;

}
void CWayPoint::set(string name, double latitude, double longitude)
{
	if ((latitude >= -90 && latitude <= 90)
			&& (longitude >= -180 && longitude <= 180))
	{
		m_name = name;
		m_latitude = latitude;
		m_longitude = longitude;
	}
	else
	{
		m_name = "";
		m_latitude = 0;
		m_longitude = 0;
	}

	cout << m_name << " on latitude " << m_latitude << " on longitude "
			<< m_longitude << endl;

#ifdef SHOWADDRESS
#define SHOWADDRESS
	cout << "The name of the object is stored at address " << this
	<< " and latitude " << &m_latitude << " and longitude "
	<< &m_longitude << endl;
#endif

}
string CWayPoint::getName()
{
	return this->m_name;
}
double CWayPoint::getLatitude()
{
	return this->m_latitude;
}
double CWayPoint::getLongitude()
{
	return this->m_longitude;
}
void CWayPoint::getAllDataByPointer(string* pname, double* platitude,
		double* plongitude)
{
	*pname = m_name;
	*platitude = m_latitude;
	*plongitude = m_longitude;

#if SHOWADDRESS

	cout << "The address of the name is " << pname << " and the latitude "
	<< platitude << " and longitude " << plongitude << endl;

	cout << "The name is " << &pname << " and the latitude "
	<< &platitude << " and longitude " << &plongitude << endl;
#endif

}
void CWayPoint::getAllDataByReference(string& name, double& latitude,
		double& longitude)
{
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;

#if SHOWADDRESS
	cout << "The address of the name is " << &name << " and the latitude "
	<< &latitude << " and longitude " << &longitude << endl;

	cout << "The name is " << name << " and the latitude "
	<< latitude << " and longitude " << longitude << endl;
#endif
}
double CWayPoint::calculateDistance(CWayPoint const& wp)
{
	double distance = RADIUS
			* acos(
					sin(m_latitude * PI / 180) * sin(wp.m_latitude * PI / 180)
							+ cos(m_latitude * PI / 180)
									* cos(wp.m_latitude * PI / 180)
									* cos(
											wp.m_longitude * PI / 180
													- m_longitude * PI / 180));
	return distance;
}
void CWayPoint::print(int format)
{
	int deg, mm;
	double ss;

	switch (format)
	{
	case DEGREE:
		set(m_name, m_latitude, m_longitude);
		break;
	case MMSS:
		cout << m_name;
		transformLatitude2degmmss(deg, mm, ss);
		transformLongitude2degmmss(deg, mm, ss);
		cout << endl;
		break;
	}
}
double CWayPoint::less(CWayPoint const& wp_right)
{
	double closer;
	closer = calculateDistance(wp_right);
	return closer;
}
CWayPoint* CWayPoint::add(CWayPoint const& wp_right)
{
	CWayPoint* newPoints;
	newPoints->m_name = this->m_name + " + " + wp_right.m_name;
	newPoints->m_latitude = this->m_latitude + wp_right.m_latitude;
	newPoints->m_longitude = this->m_longitude + wp_right.m_longitude;

	return newPoints;
}
void CWayPoint::transformLongitude2degmmss(int& deg, int& mm, double& ss)
{

	deg = (int) m_longitude;
	mm = (int) ((m_longitude - deg) * 60);
	ss = ((m_longitude - deg - (mm / 60)) * 3600) * PI / 180;

	cout << " on longitude " << deg << " deg " << mm << " mm " << ss << " ss ";
}
void CWayPoint::transformLatitude2degmmss(int& deg, int& mm, double& ss)
{
	deg = (int) m_latitude;
	mm = (int) ((m_latitude - deg) * 60);
	ss = ((m_latitude - deg - (mm / 60)) * 3600) * PI / 180;
	cout << " on latitude " << deg << " deg " << mm << " mm " << ss << " ss ";
}

double maxDistance(double x, double y, double z)
{
	double maxValue;
	if (x > y && x > z)
		maxValue = x;
	else if (y > x && y > z)
		maxValue = y;
	else
		maxValue = z;
	return maxValue;
}

CWayPoint::~CWayPoint()
{

}

