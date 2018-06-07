#pragma once
#include <iostream>

using namespace std;

class Polynomial{
	friend ostream& operator << (ostream &s, Polynomial& p);
private:
	int termCount;
	int * coeffs, * powers;
	
	void combineLikeTerms();
public:
	Polynomial();
	~Polynomial();
	Polynomial(int terms, int* c, int* p);
	
	const int* const getCoeffs() const;
	const int* const getPowers() const;
	const int getTermCount() const;

	double evalAtPoint(double point);
	Polynomial generateDerivative();
	double findRoot(double start_point);

	Polynomial& operator + (const Polynomial& p);
	Polynomial& operator += (const Polynomial& p);
	Polynomial& operator - (const Polynomial& p);
	Polynomial& operator * (const Polynomial& p);
	Polynomial& operator * (double scalar);
	
};

