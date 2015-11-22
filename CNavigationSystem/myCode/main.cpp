// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
#include "CGPSsensor.h"

// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
// #include <string>
#include "CWayPoint.h"
#include "CPOI.h"
#include "CPOIDatabase.h"
#include "CRoute.h"

using namespace std;
// Erspart den scope vor Objekte der
// C++-Standard-Bibliothek zu schreiben
// z.B. statt "std::cout" kann man "cout" schreiben

// Inkludieren Sie hier die Header-Files Ihrer Klassen, z.B.
// #include "CFraction.h"

// Hauptprogramm
// Dient als Testrahmen, von hier aus werden die Klassen aufgerufen
int main(void)
{
	// TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "CNavigationSystem gestarted." << endl << endl;

	CWayPoint* amsterdam = new CWayPoint("Amsterdam", 52.3667, 4.9);
	CWayPoint* darmstadt = new CWayPoint("Darmstadt", 49.8667, 8.65);
	CWayPoint* berlin = new CWayPoint("Berlin", 52.516, 13.3833);

	CPOI* mensa = new CPOI(RESTAURANTS, "Mensa", "The Best Mensa in the World",
			10.0, 20.0);
	CPOI* dolomiti = new CPOI(ICECAFE, "dolomiti",
			"The best icecream in germany", 20.89, 39.54);

	CRoute* route = new CRoute();
	route->print();

	CGPSsensor* point = new CGPSsensor();
	point->getCurrentPosition();

	return 0;
}
