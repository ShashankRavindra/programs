/*
 * CRoute.cpp
 *
 *  Created on: 02-Nov-2015
 *      Author: Shashank_Ravindra
 */

#include "CRoute.h"
#include "CWayPoint.h"
#include "CPOIDatabase.h"

#include <iostream>
#include <iomanip>
using namespace std;

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi)
{
	maxWp = this->m_maxWp;
	maxPoi = this->m_maxPoi;
	m_pWaypoint = new CWayPoint[maxWp];
	m_pPoi = new CPOI*[maxPoi];
}
CRoute::CRoute(CRoute const& origin)
{
	m_maxPoi = origin.m_maxPoi;
	m_maxWp = origin.m_maxWp;
}
CRoute::~CRoute()
{

}
void CRoute::connectToPoiDatabase(CPOIDatabase* pPoiDB)
{
	m_pPoiDatabase = pPoiDB;
}
void CRoute::addWaypoint(CWayPoint const& wp)
{
	m_nextWp = 0;

	if (m_nextWp < m_maxWp)
	{
		m_pWaypoint[m_nextPoi] = wp;
		m_nextWp++;
	}
	else
	{
		cerr << "Could not find a Waypoint in the pool" << endl;
	}
}
void CRoute::addPoi(string namePoi)
{
	m_nextPoi = 0;

	if (m_nextPoi < m_maxPoi)
	{
		m_pPoi[m_nextPoi] = m_pPoiDatabase->getPointerToPoi(namePoi);
		m_nextPoi++;
	}
	else
	{
		cerr << "Could not find a Point of Interest in the pool" << endl;
	}
}
double CRoute::getDistanceNextPoi(CWayPoint &wp, CPOI &poi)
{
	double dist, min_dist;
	string name;
	double latitude, longitude;
	CWayPoint Temp_POI;

	m_pPoi[0]->getAllDataByReference(name, latitude, longitude);

	Temp_POI.set(name, latitude, longitude);
	dist = wp.calculateDistance(Temp_POI);
	min_dist = dist;
	poi = *(m_pPoi[0]);

	for (unsigned int i = 1; i < m_nextPoi; i++)
	{
		m_pPoi[0]->getAllDataByReference(name, latitude, longitude);
		Temp_POI.set(name, latitude, longitude);
		dist = wp.calculateDistance(Temp_POI);
		if (dist < min_dist)
		{
			min_dist = dist;
			poi = *(m_pPoi[i]);
		}
	}
	return min_dist;
}
void CRoute::print()
{
	cout << "Our route has 3 waypoints and 2 point of Interest" << endl;

	for (unsigned int i = 0; i < m_maxWp; i++)
	{
		m_pWaypoint[i].print(2);
	}
	for (unsigned int j = 0; j < m_maxPoi; j++)
	{
		m_pPoi[j]->print();
	}

}
