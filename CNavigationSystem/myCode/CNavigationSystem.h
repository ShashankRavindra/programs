
#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

#include "CGPSsensor.h"
#include "CRoute.h"
#include "CPOIDatabase.h"

class CNavigationSystem
{
private:
	CGPSsensor m_GPSsensor;
	CRoute m_route;
	CPOIDatabase m_PoiDatabase;

public:
	CNavigationSystem();
	void run();

private:
	void enterRoute();
	void printRoute();
	void printDistanceCurPosNextPoi();

};

#endif
