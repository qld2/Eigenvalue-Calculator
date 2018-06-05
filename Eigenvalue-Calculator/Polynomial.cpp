#include "stdafx.h"
#include "Polynomial.h"
#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {
private:
	int termCount;
	int* coeffs, *powers;


	void combineLikeTerms() {

		int repeatCount = 0;

		for (int i = 0; i < termCount; i++) {
			for (int j = i + 1; j < termCount; j++) {
				if (powers[j] == powers[i]) {
					repeatCount++;
					break;
				}
			}
		}

		int newTermCount = termCount - repeatCount;
		int* newCoeffs = new int[newTermCount];
		int* newPowers = new int[newTermCount];

		int k = 1;
		newPowers[0] = powers[0];
		newCoeffs[0] = coeffs[0];
		for (int i = 1; i < termCount; i++) {

			bool found = false;

			for (int j = 0; j < k; j++) {
				if (powers[i] == newPowers[j]) {
					newCoeffs[j] += coeffs[i];
					found = true;
				}
			}

			if (!found) {
				newPowers[k] = powers[k];
				newCoeffs[k] = coeffs[k];
				k++;
			}
		}
	}

public:
	Polynomial()
	{
		termCount = 1;
		coeffs = new int[1];
		powers = new int[1];

		coeffs[0] = 0;
		powers[0] = 1;
	}

	Polynomial(int terms, int* c, int* p) {
		termCount = terms;
		coeffs = c;
		powers = p;

		//combineLikeTerms();
	}
	
	~Polynomial()
	{
		delete coeffs, powers;
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

		static int iterations = 100;

		if (iterations == 1) {
			iterations = 100;
			int approx = start_point - ((double) evalAtPoint(start_point))
				/ generateDerivative().evalAtPoint(start_point);

			if (abs(approx) < 1e-7) {
				approx = 0;
			}

			return approx;
		}

		iterations--;
		return findRoot(start_point - ((double) evalAtPoint(start_point))
			/ generateDerivative().evalAtPoint(start_point));
	}

	/*
	Polynomial& operator + (const Polynomial& p) {
		const int* pCoeffs = p.getCoeffs();
		const int* pPowers = p.getPowers();

		int* rCoeffs = new int[termCount];
		int* rPowers = new int[termCount];

		for (int i = 0; i < termCount; i++) {
			for (int j = 0; j < termCount; j++) {
				rCoeffs[k] = coeffs[i] * pCoeffs[j];
				rPowers[k] = powers[i] + pPowers[j];
				cout << rCoeffs[k] << " " << rPowers[k] << endl;
			}
		}

		Polynomial* p2 = new Polynomial(termCount, rCoeffs, rPowers);
		return (*p2);
	}
	*/

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

	Polynomial& operator * (double scalar) {

		int* rCoeffs = new int[termCount];
		int* rPowers = new int[termCount];

		for (int i = 0; i < termCount; i++) {
			rPowers[i] = powers[i];
			rCoeffs[i] = coeffs[i] * scalar;
		}

		Polynomial* p2 = new Polynomial(termCount, rCoeffs, rPowers);
		return (*p2);
	}

	friend ostream& operator << (ostream &s, Polynomial& p) {
		for (int i = 0; i < termCount; i++) {
			s << coeffs[i] << " x^" << powers[i] << " ";

			if (i != termCount - 1) {
				s << "+ ";
			}
		}

		s << endl;

		return s;
	}
};


