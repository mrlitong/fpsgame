#pragma once
//MathLib.h

#ifndef _MATHLIB_
#define _MATHLIB_

//Make some change to check if new branch is created.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//------------------------------------------------------------
double integral(double(*f)(double), double a = 0, double b = 1, double tol = 1e-5, long n = 50);
//------------------------------------------------------------
double limit(double(*f)(double), double a = 0, double b = 1, double tol = 1e-5, long n = 1);
//------------------------------------------------------------
double diff(double(*f)(double), double a = 0, double b = 1, double tol = 1e-5, long n = 1);
//------------------------------------------------------------
#define PLOT_WIDTH 60
double plot(double x[], int n, char c = '*');
//------------------------------------------------------------
double fplot(double(*f)(double), double a = 0, double b = 1, int n = 25, char c = '*');
//------------------------------------------------------------
int subset(double *a, int i, int j);

void subsort(double *a, int i, int j);
//------------------------------------------------------------
void shellsort(double *a, int n);
//------------------------------------------------------------
void cmpsort(double *a, int n);
//------------------------------------------------------------
void rollsort(double *a, int n);
//------------------------------------------------------------

int sgn(double x);

int sign(double x);
//------------------------------------------------------------

#define FORMAT_STD 1
#define FORMAT_EXP 0
#define MATHLIB_PI 3.14159265

class complex
{
protected:
	double real;
	double imag;
	double len;
	double arg;
public:
	complex(double r = 0, double i = 0, int format = FORMAT_STD);

	void set(double r = 0, double i = 0, int format = FORMAT_STD);
	void output(int format = FORMAT_STD);
	void input(int format = FORMAT_STD);

	friend void set(complex &c, double r = 0, double i = 0, int format = FORMAT_STD);
	friend void output(complex &c, int format = FORMAT_STD);
	friend void input(complex &c, int format = FORMAT_STD);
	friend ostream & operator <<(ostream &out, complex &c);
	friend istream & operator <<(istream &in, complex &c);

	double getreal();
	double getimag();
	double getlen();
	double getarg();

	operator double() { return sgn(real)*len; }
	complex operator ~();
	complex operator !();
	complex operator -();
	complex operator +();

	friend complex operator +(const complex &, const complex &);
	friend complex operator -(const complex &, const complex &);
	friend complex operator *(const complex &, const complex &);
	friend complex operator /(const complex &, const complex &);
	friend complex operator &(const complex &, const complex &);
	friend complex operator |(const complex &, const complex &);
	friend complex operator ^(const complex &, const double);

	friend complex operator +=(complex &, const complex &);
	friend complex operator -=(complex &, const complex &);
	friend complex operator *=(complex &, const complex &);
	friend complex operator /=(complex &, const complex &);
	friend complex operator &=(complex &, const complex &);
	friend complex operator |=(complex &, const complex &);
	friend complex operator ^=(complex &, const double);

	friend int operator ==(const complex &, const complex &);
	friend int operator !=(const complex &, const complex &);
	friend int operator <(const complex &, const complex &);
	friend int operator <=(const complex &, const complex &);
	friend int operator >(const complex &, const complex &);
	friend int operator >=(const complex &, const complex &);


	friend complex exp(const complex &);
	friend complex log(const complex &);
	friend complex sin(const complex &);
	friend complex cos(const complex &);
	friend double arg(const complex &);
	friend double abs(const complex &);
}
#endif		//_MATHLIB_