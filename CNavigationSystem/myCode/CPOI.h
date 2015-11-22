/*
 * CPOI.h
 *
 *  Created on: 02-Nov-2015
 *      Author: Shashank_Ravindra
 */

#ifndef CPOI_H_
#define CPOI_H_

#include "CWayPoint.h"

#include <iomanip>
using namespace std;

enum t_poi
{
	KINO,RESTAURANT, SUPERMARKET, HOSTEL, HOTEL, NONE
};

class CPOI: public CWayPoint
{
private:
	t_poi m_type;
	string m_description;

public:
	void print();
	CPOI(t_poi type = NONE, string name = "", string description = " ", double latitude = 0.0,
			double longitude = 0.0);
	void set(t_poi type = NONE, string name = "", string description = " ", double latitude = 0.0,
				double longitude = 0.0);

};

#endif /* CPOI_H_ */
