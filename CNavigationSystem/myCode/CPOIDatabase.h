/*
 * CPOIDatabase.h
 *
 *  Created on: 02-Nov-2015
 *      Author: Shashank_Ravindra
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_

#include "CPOI.h"

#include <iomanip>
using namespace std;

class CPOIDatabase
{
private:
	CPOI m_POI[10];
	int m_noPoi;

public:
	CPOIDatabase();
	void addPoi(t_poi type, string name, string description, double latitude,
			double longitude);
	CPOI* getPointerToPoi(string name);
};

#endif /* CPOIDATABASE_H_ */
