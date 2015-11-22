/*
 * CFraction.cpp
 *
 *  Created on: 16-Nov-2015
 *      Author: Shashank_Ravindra
 */
#include "CFraction.h"

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

CFraction::CFraction(long numerator, long denominator)
{
	if (denominator == 0)
	{
		numerator = 0;
		denominator = 1;
	}
	else
	{
		this->m_numerator = numerator;
		this->m_denominator = denominator;
		this->shorten();
	}
}
CFraction::~CFraction()
{

}
void CFraction::set(long numerator, long denominator)
{
	this->m_numerator = numerator;
	if (denominator == 0)
	{
		cerr << "Attempting to divide by zero" << endl;
	}
	else
	{
		this->m_denominator = denominator;
	}
	this->shorten();
}
double CFraction::toDouble()
{

	double value = (double) m_numerator / (double) m_denominator;
	cout << "The fraction value is " << value << endl;
	return value;
}
void CFraction::print()
{

	cout << "CFraction[ m_numerator = " << this->m_numerator
			<< " , m_denominator = " << this->m_denominator << "]" << endl;
}
CFraction& CFraction::operator++()
{
	++m_numerator;
	m_denominator++;
	return *this;
}
CFraction CFraction::operator++(int)
{
	CFraction value = *this;
	++*this;
	return value;

}

void CFraction::shorten()
{
	int n;
	if (m_denominator == 0 || m_numerator == 0)
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	if (m_denominator < 0)
	{
		m_numerator *= -1;
		m_denominator *= -1;
	}
	if (m_denominator != 0 && m_numerator != 0)
	{
		n = gcf(m_numerator, m_denominator);
	}
	m_numerator /= n;
	m_denominator /= n;
}

int CFraction::gcf(int num, int den)
{
	while (num != den)
	{
		if (num > den)
		{
			num = num - den;
		}
		else
		{
			den = den - num;
		}
	}
	return num;
}

ostream& operator<<(ostream &out, const CFraction &c)
{
	out << "(" << c.m_numerator << "," << c.m_denominator << ")";
	return out;
}

CFraction CFraction::operator+(const CFraction &a)
{
	CFraction sum;

	sum.m_numerator = this->m_numerator * a.m_denominator
			+ a.m_numerator * this->m_denominator;
	sum.m_denominator = this->m_denominator * a.m_denominator;
	sum.shorten();
	return sum;
}
CFraction CFraction::operator+(const int lop)
{
	CFraction sum;
	sum.m_numerator = this->m_numerator + lop * this->m_denominator;
	sum.m_denominator = this->m_denominator;
	sum.shorten();
	return sum;
}
CFraction operator+(const int lop, CFraction &a)
{
	CFraction sum;
	sum.m_numerator = lop * a.m_denominator + a.m_numerator;
	sum.m_denominator = a.m_denominator;
	sum.shorten();
	return sum;
}

CFraction CFraction::operator-(const CFraction &a)
{
	CFraction diff;

	diff.m_numerator = this->m_numerator * a.m_denominator
			- a.m_numerator * this->m_denominator;
	diff.m_denominator = this->m_denominator * a.m_denominator;
	diff.shorten();
	return diff;
}
CFraction CFraction::operator-(const int lop)
{
	CFraction diff;
	diff.m_numerator = this->m_numerator - lop * this->m_denominator;
	diff.m_denominator = this->m_denominator;
	diff.shorten();
	return diff;
}
CFraction operator-(const int lop, CFraction &a)
{
	CFraction diff;
	diff.m_numerator = lop * a.m_denominator - a.m_numerator;
	diff.m_denominator = a.m_denominator;
	diff.shorten();
	return diff;
}

CFraction CFraction::operator*(const CFraction &a)
{
	CFraction mul;

	mul.m_numerator = this->m_numerator * a.m_numerator;
	mul.m_denominator = this->m_denominator * a.m_denominator;
	mul.shorten();
	return mul;
}
CFraction CFraction::operator*(const int lop)
{
	CFraction mul;
	mul.m_numerator = this->m_numerator * lop;
	mul.m_denominator = this->m_denominator;
	mul.shorten();
	return mul;

}
CFraction operator*(const int lop, CFraction &a)
{
	CFraction mul;
	mul.m_numerator = lop * a.m_numerator;
	mul.m_denominator = a.m_denominator;
	mul.shorten();
	return mul;
}

CFraction CFraction::operator/(const CFraction &a)
{
	CFraction div;

	div.m_numerator = this->m_numerator * a.m_denominator;
	div.m_denominator = this->m_denominator * a.m_numerator;
	div.shorten();
	return div;
}
CFraction CFraction::operator/(const int lop)
{
	CFraction div;
	div.m_numerator = this->m_denominator * lop;
	div.m_denominator = this->m_numerator;
	div.shorten();
	return div;

}
CFraction operator/(const int lop, CFraction &a)
{
	CFraction div;
	div.m_numerator = lop * a.m_denominator;
	div.m_denominator = a.m_numerator;
	div.shorten();
	return div;
}
