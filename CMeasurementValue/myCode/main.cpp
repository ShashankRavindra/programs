// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include "stdlib.h"
#include <iomanip>
#include "CMeasurementValue.h"
// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
// #include <string>

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
	cout << "CMeasurementValue gestarted." << endl << endl;

	CMeasurementValue* value = new CMeasurementValue(320, A);
	value->setValue(230, V);
	value->print();
	value->setTime(10, 05, 22);
	value->printWithTime();

//	value->setTime(25, 05, 22);
//	value->printWithTime();

	double random[20];

	for (int i = 0; i < 20; i++)
	{

		random[i] = createRandomValue(-380, 380);
		cout << "The random number created at " << i << " is " << fixed
				<< setprecision(1) << random[i] << endl;
		value->setTime(10, i, 00);
		value->printWithTime();
	}
	double maxValue = -380, index;

	for (int j = 0; j < 20; j++)
	{

		if (random[j] > maxValue)
		{
			maxValue = random[j];
			index = j;
		}
	}
	cout << "The maximum value is " << maxValue << " and is at " << index
			<< endl;

	return 0;
}
