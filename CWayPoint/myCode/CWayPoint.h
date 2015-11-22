/*
 * CWayPoint.h
 *
 *  Created on: 29-Oct-2015
 *      Author: Shashank_Ravindra
 */
#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_

#include <string>
using namespace std;

class CWayPoint
{
private:
	string m_name;
	double m_latitude;
	double m_longitude;

public:
	CWayPoint(string name = " ", double latitude = 0, double longitude = 0);
	void set(string name, double latitude, double longitude);
	string getName();
	double getLatitude();
	double getLongitude();
	void getAllDataByPointer(string* pname, double* platitude,
			double* plongitude);
	void getAllDataByReference(string& name, double& latitude,
			double& longitude);
	double calculateDistance(CWayPoint const& wp);
	void print(int format);
	double less(CWayPoint const& wp_right);
	CWayPoint* add(CWayPoint const& wp_right);
	~CWayPoint();

private:
	void transformLongitude2degmmss(int& deg, int& mm, double& ss);
	void transformLatitude2degmmss(int& deg, int& mm, double& ss);
};

double maxDistance(double x, double y, double z);

#endif /* CWAYPOINT_H_ */
