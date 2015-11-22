// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
// #include <string>
#include "CFraction.h"
#include "CLifoBuffer.h"
#include "CRpnCalculator.h"

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

	CLifoBuffer st(10);
	CFraction data;

	CRpnCalculator Calc;
	CFraction value;
	value.set(5, 2);
	Calc.pushValue(value);
	value.set(6, 5);
	Calc.pushValue(value);
	Calc.multiply();
	value.set(1, 2);
	Calc.pushValue(value);
	Calc.add();
	value.set(1, 3);
	Calc.pushValue(value);
	Calc.subtract();

	value.set(5, 1);
	Calc.pushValue(value);
	value.set(1, 6);
	Calc.pushValue(value);
	Calc.add();
	value.set(11, 4);
	Calc.pushValue(value);
	Calc.add();

	Calc.divide();
	Calc.popResult(value);

	cout << " (5/2)*(6/5)+(1/2)-(1/3)" << endl;
	cout << "--------------------------" << " = " << value << endl;
	cout << "      5+(1/6)+11/4		 " << endl;

	return 0;
}
