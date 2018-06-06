#pragma once

class Polynomial{
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
	const int getTermCount();

	double evalAtPoint(double point);
	Polynomial generateDerivative();
	double findRoot(double start_point);

	friend ostream& operator << (ostream &s, Polynomial& p);
};

