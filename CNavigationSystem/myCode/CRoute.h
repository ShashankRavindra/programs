/*
 * CRoute.h
 *
 *  Created on: 02-Nov-2015
 *      Author: Shashank_Ravindra
 */

#ifndef CROUTE_H_
#define CROUTE_H_

#include "CWayPoint.h"
#include "CPOIDatabase.h"

#include <iomanip>
using namespace std;

class CRoute
{
private:
	CWayPoint* m_pWaypoint;
	unsigned int m_maxWp;
	unsigned int m_nextWp;
	CPOI** m_pPoi;
	unsigned int m_maxPoi;
	unsigned int m_nextPoi;
	CPOIDatabase* m_pPoiDatabase;
	CWayPoint m_numWp[];
	CPOI* m_numPoi[];

public:
	CRoute(unsigned int maxWp = 0, unsigned int maxPoi = 0);
	CRoute(CRoute const& origin);
	~CRoute();
	void connectToPoiDatabase(CPOIDatabase* pPoiDB);
	void addWaypoint(CWayPoint const& wp);
	void addPoi(string namePoi);
	double getDistanceNextPoi(CWayPoint& wp, CPOI& poi);
	void print();
};

#endif /* CROUTE_H_ */
