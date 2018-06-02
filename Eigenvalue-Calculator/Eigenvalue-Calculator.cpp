// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {
private:
	int termCount;
	int* coeffs, *powers;

public:
	Polynomial(int terms, int* c, int* p) {
		this->termCount = terms;
		coeffs = c;
		powers = p;
	}

	const int* const getCoeffs() const {
		return coeffs;
	}

	const int* const getPowers() const {
		return powers;
	}

	const int const getTermCount() const {
		return termCount;
	}

	double evalAtPoint(double point) {
		double sum = 0;
		for (int i = 0; i < termCount; i++) {
			sum += coeffs[i] * pow(point, powers[i]);
		}
		return sum;
	}

	Polynomial generateDerivative() {
		int* c = new int[termCount];
		int* p = new int[termCount];

		for (int i = 0; i < termCount; i++) {
			c[i] = coeffs[i] * powers[i];
			p[i] = powers[i] - 1;
		}

		return Polynomial(termCount, c, p);
	}

	double findRoot(double start_point) {

		cout << start_point << endl;

		static int iterations = 100;

		if (iterations == 1) {
			iterations = 100;
			int approx = start_point - ((double)evalAtPoint(start_point))
				/ generateDerivative().evalAtPoint(start_point);

			if (abs(approx) < 1e-7) {
				approx = 0;
			}

			return approx;
		}

		iterations--;
		return findRoot(start_point - ((double)evalAtPoint(start_point))
			/ generateDerivative().evalAtPoint(start_point));
	}

	Polynomial& operator * (const Polynomial& p) {
		const int* pCoeffs = p.getCoeffs();
		const int* pPowers = p.getPowers();
		const int pTermCount = p.getTermCount();

		int* rCoeffs = new int[termCount * pTermCount];
		int* rPowers = new int[termCount * pTermCount];

		int k = 0;
		for (int i = 0; i < termCount; i++, k++) {
			for (int j = 0; j < pTermCount; j++, k++) {
				rCoeffs[k] = coeffs[i] * pCoeffs[j];
				rPowers[k] = powers[i] + pPowers[j];
				cout << rCoeffs[k] << " " << rPowers[k] << endl;
			}
		}

		Polynomial* p2 = new Polynomial(termCount * pTermCount, rCoeffs, rPowers);
		return (*p2);
	}

};

int main()
{
	int t;

	cout << "How many terms in polynomial?" << endl;
	cin >> t;

	int* c = new int[t];
	int* p = new int[t];

	for (int i = 0; i < t; i++) {
		cout << "Enter coefficient" << endl;
		cin >> c[i];
		cout << "Enter power" << endl;
		cin >> p[i];
	}

	Polynomial poly(t, c, p);

	Polynomial p2 = poly * poly;
	cout << p2.evalAtPoint(3);

	cin.get();
	cin.get();
	return 0;
}