#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "Polynomial.cpp"

using namespace std;

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

	cin.get();
	cin.get();
	return 0;
}