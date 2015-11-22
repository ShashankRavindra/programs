// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
// #include <string>
#include "CWayPoint.h"

#define MMSS 2
#define DEGREE 1

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
	cout << "CWayPoint gestarted." << endl << endl;

	CWayPoint* amsterdam = new CWayPoint("Amsterdam", 52.3667, 4.9);
	CWayPoint* darmstadt = new CWayPoint("Darmstadt", 49.8667, 8.65);
	CWayPoint* berlin = new CWayPoint("Berlin", 52.516, 13.3833);
	CWayPoint* tokyo = new CWayPoint("Tokyo", 35.68, 139.68);

	CWayPoint* newWayPoint = new CWayPoint("Bangalore", 12.9667, 77.5667);

	berlin->print(1);
	berlin->print(2);

	cout << endl;
	cout << endl;
	cout << "The name of the city is " << newWayPoint->getName()
			<< " is at latitude " << newWayPoint->getLatitude()
			<< " is at longitude " << newWayPoint->getLongitude() << endl;

	cout << "Let's enter some data" << endl;
	string name = "";
	double latitude = 0;
	double longitude = 0;

	cout << "Enter name ";
	cin >> name;
	cout << endl;
	cout << "Enter latitude ";
	cin >> latitude;
	cout << endl;
	cout << "Enter longitude ";
	cin >> longitude;
	cout << endl;

	newWayPoint->set(name, latitude, longitude);

	cout << "Distance Calculation" << endl;
	cout << "The distance between Berlin and Amsterdam is "
			<< berlin->calculateDistance(*amsterdam) << endl;
	cout << "The distance between Berlin and Tokyo is "
			<< berlin->calculateDistance(*tokyo) << endl;

	cout << "Testing" << endl;
	CWayPoint* addObject;
	addObject = berlin->add(*amsterdam);
	addObject->print(2);

	cout << endl;
	cout << endl;
	CWayPoint* newPoint = new CWayPoint("Origin", 0, 0);
	if (newPoint->less(*berlin) > newPoint->less(*amsterdam))
		cout << "Berlin is closer to Origin" << endl;
	else
		cout << "Amsterdam is closer to Origin" << endl;

	CWayPoint* newObject = new CWayPoint(*addObject);

	CWayPoint* array[10];

	array[0] = new CWayPoint("Bangalore", 12.9667, 77.5667);
	array[1] = new CWayPoint("Delhi", 28.6100, 77.2300);
	array[2] = new CWayPoint("Chennai", 13.0827, 80.2707);

	double BangaloreChennai = array[0]->calculateDistance(*array[2]);
	double BangaloreDelhi = array[0]->calculateDistance(*array[1]);
	double DelhiChennai = array[1]->calculateDistance(*array[2]);

	cout << endl;
	cout << endl;
	cout << "The distance between Bangalore and Chennai is " << BangaloreChennai
			<< "KM" << endl;
	cout << "The distance between Bangalore and Delhi is " << BangaloreDelhi
			<< "KM" << endl;
	cout << "The distance between Delhi and Chennai is " << DelhiChennai << "KM"
			<< endl;

	cout << "Total trip is " << BangaloreChennai + BangaloreDelhi + DelhiChennai
			<< "KM" << endl;

	cout << "The Longest trip is "
			<< maxDistance(BangaloreChennai, BangaloreDelhi, DelhiChennai)
			<< "KM" << endl;

	return 0;
}
