#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_

#include "CWayPoint.h"

class CGPSsensor
{
public:
	CGPSsensor();
	CWayPoint getCurrentPosition();
};

#endif
