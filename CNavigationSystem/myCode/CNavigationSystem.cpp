/*
 * CNavigationSystem.cpp
 *
 *  Created on: 02-Nov-2015
 *      Author: Shashank_Ravindra
 */

#include "CNavigationSystem.h"
#include "CGPSsensor.h"
#include "CRoute.h"
#include "CPOIDatabase.h"

CNavigationSystem::CNavigationSystem()
{

}
void CNavigationSystem::run()
{

	m_PoiDatabase.addPoi(RESTAURANT, "Vapino",
			"Expensive and famous for Italian dishes.", 51.55, 12.33);
	m_PoiDatabase.addPoi(RESTAURANT, "HDA Mensa",
			"Cheap and good place to eat.", 52.00, 13.333);
	m_PoiDatabase.addPoi(SUPERMARKET, "Aldi", "Cheap supermarket", 52.00,
			13.333);
	m_PoiDatabase.addPoi(HOTEL, "Hotel Intercontinental", "5 Star hotel", 58.33,
			4.05);
	m_PoiDatabase.addPoi(HOSTEL, "Ibis", "3 Star hotel", 62.00, 18.333);
	m_PoiDatabase.addPoi(RESTAURANT, "Indian Restaurant",
			"Best place to have Indian food", 50.117, 8.6858);
	m_PoiDatabase.addPoi(SUPERMARKET, "KaDeWe",
			"Best and biggest shopping mall", 60.55, 15.98);
	m_PoiDatabase.addPoi(KINO, "Cinestar", "Best place to watch English movies",
			65.00, 20.333);
	m_PoiDatabase.addPoi(RESTAURANT, "Mensa", "The Best Mensa in the World",
			10.0, 20.0);
	m_PoiDatabase.addPoi(HOTEL, "dolomiti", "The best icecream in germany",
			20.89, 39.54);
	m_route.connectToPoiDatabase(&m_PoiDatabase);
}

void CNavigationSystem::enterRoute()
{
	CWayPoint* amsterdam = new CWayPoint("Amsterdam", 52.3667, 4.9);
	CWayPoint* darmstadt = new CWayPoint("Darmstadt", 49.8667, 8.65);
	CWayPoint* berlin = new CWayPoint("Berlin", 52.516, 13.3833);

	m_route.addWaypoint(*berlin);
	m_route.addWaypoint(*darmstadt);
	m_route.addWaypoint(*amsterdam);
	m_route.addPoi("mensa");
	m_route.addPoi("dolomiti");
}
void CNavigationSystem::printRoute()
{
	m_route.print();
}
void CNavigationSystem::printDistanceCurPosNextPoi()
{
	CWayPoint curPos = m_GPSsensor.getCurrentPosition();
	CPOI nextPoi;
	double dist = m_route.getDistanceNextPoi(curPos, nextPoi);
	nextPoi.print();
	cout << "dist " << dist << " km" << endl;
}
