/*
 * CPOI.cpp
 *
 *  Created on: 02-Nov-2015
 *      Author: Shashank_Ravindra
 */
#include "CPOI.h"
#include "CWayPoint.h"

#include <iostream>
#include <iomanip>
using namespace std;

void CPOI::print()
{
	switch (m_type)
	{
	case RESTAURANTS:
		cout << " Restuarant " << this->m_description << endl;
		break;
	case SUPERMARKETS:
		cout << " Supermarket " << this->m_description << endl;
		break;
	case ICECAFE:
		cout << " IceCafe " << this->m_description << endl;
		break;
	case PARK:
		cout << " Park " << this->m_description << endl;
		break;
	default:
		cerr << " Error!!! Not a valid POI " << endl;
		break;
	}
	CWayPoint::print(2);
}

CPOI::CPOI(t_poi type, string name, string description, double latitude,
		double longitude)
{
	type = this->m_type;
	description = this->m_description;

}

void CPOI::set(t_poi type, string name, string description, double latitude,
		double longitude)
{
	type = this->m_type;
	description = this->m_description;

}
