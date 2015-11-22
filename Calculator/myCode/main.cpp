// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
// #include <string>

using namespace std;
// Erspart den scope vor Objekte der
// C++-Standard-Bibliothek zu schreiben
// z.B. statt "std::cout" kann man "cout" schreiben

// Inkludieren Sie hier die Header-Files Ihrer Klassen, z.B.
// #include "CFraction.h"

#include "CFraction.h"
// Hauptprogramm
// Dient als Testrahmen, von hier aus werden die Klassen aufgerufen
int main(void)
{
	// TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "Calculator gestarted." << endl << endl;

	CFraction f1;
	CFraction f2(1, 3);
	CFraction f3(2, 5);
	f1.print();
	f2.print();
	f3.print();
	f2.toDouble();

	cout << endl << endl;
	cout << "addition" << endl;
	CFraction sum;
	sum = f2 + f3;
	sum.print();
	sum = 5 + f2;
	sum.print();
	sum = f3 + 9;
	sum.print();

	cout << endl << endl;
	cout << "Subtraction" << endl;
	CFraction diff;
	diff = f2 - f3;
	diff.print();
	diff = 5 - f2;
	diff.print();
	diff = f3 - 9;
	diff.print();

	cout << endl << endl;
	cout << "Multiplication" << endl;
	CFraction mul;
	mul = f2 * f3;
	mul.print();
	mul = 5 * f2;
	mul.print();
	mul = f3 * 9;
	mul.print();

	cout << endl << endl;
	cout << "Division" << endl;
	CFraction div;
	div = f2 / f3;
	div.print();
	div = 5 / f2;
	div.print();
	div = f3 / 9;
	div.print();

	cout << endl << endl;
	cout << "Overloaded << " << endl;
	cout << CFraction(2 / 3) + CFraction(9 / 6) << endl;
	cout << CFraction(2 / 3) - CFraction(9 / 6) << endl;
	cout << CFraction(2 / 3) * CFraction(9 / 6) << endl;
	cout << CFraction(2 / 3) / CFraction(9 / 6) << endl;

	CFraction f(1, 3);
	CFraction g;
	g = ++f;
	cout << "++f == " << f << "; (g=++f) == " << g << endl;
	f.set(1,3);
	g = f++;
	cout << "f++ == " << f << "; (g=f++) == " << g << endl;

	return 0;
}
