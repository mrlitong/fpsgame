#pragma once
//MathLib.h

#ifndef _MATHLIB_
#define _MATHLIB_

//Make some change to check if new branch is created.

#include <iostream>

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



#endif