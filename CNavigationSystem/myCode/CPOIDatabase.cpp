/*
 * CPOIDatabase.cpp
 *
 *  Created on: 02-Nov-2015
 *      Author: Shashank_Ravindra
 */

#include "CPOIDatabase.h"
#include "CPOI.h"

#include <iostream>
#include <iomanip>
using namespace std;

CPOIDatabase::CPOIDatabase()
{
}
void CPOIDatabase::addPoi(t_poi type, string name, string description,
		double latitude, double longitude)
{

	if (m_noPoi < 10)
	{
		m_POI[m_noPoi].set(type, name, description, latitude, longitude);
		m_noPoi++;
	}
}

CPOI* CPOIDatabase::getPointerToPoi(string name)
{
	CPOI* poi = NULL;
	for (int i = 0; i <= 10; i++)
	{
		if (m_POI[i].getName() == name)
		{
			poi = &m_POI[i];
			break;
		}
	}
	return poi;
}

