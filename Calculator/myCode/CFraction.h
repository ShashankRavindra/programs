/*
 * CFraction.h
 *
 *  Created on: 16-Nov-2015
 *      Author: Shashank_Ravindra
 */

#ifndef CFRACTION_H_
#define CFRACTION_H_

#include <string>
using namespace std;
class CFraction
{
public:
	friend CFraction operator+(const int lop, CFraction &a);
	friend CFraction operator-(const int lop, CFraction &a);
	friend CFraction operator*(const int lop, CFraction &a);
	friend CFraction operator/(const int lop, CFraction &a);
	friend ostream& operator<<(ostream &out, const CFraction &c);

private:
	long m_numerator;
	long m_denominator;

	void shorten();
	int gcf(int numerator, int denominator);

public:
	CFraction(long numerator = 0, long denominator = 1);
	~CFraction();
	void set(long numerator, long denominator);
	double toDouble();
	void print();
	CFraction& operator++();
	CFraction operator++(int);

	CFraction operator*(const CFraction &a);
	CFraction operator*(const int lop);
	CFraction operator/(const CFraction &a);
	CFraction operator/(const int lop);
	CFraction operator-(const CFraction &a);
	CFraction operator-(const int lop);
	CFraction operator+(const CFraction &a);
	CFraction operator+(const int lop);

};

#endif /* CFRACTION_H_ */
