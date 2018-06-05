#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "Polynomial.cpp"

using namespace std;
/*
Polynomial determinant(Polynomial** matrix, int size) {
		
	Polynomial* result = new Polynomial();
	if (size == 2) {
		result = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else {
		for (int j = 0; j < size; j++) {
			result += matrix[0][j] * getCofactorAt(0, j);
		}
	}
	return result;
}

Polynomial getCofactorAt(Polynomial** matrix, int size, int row, int col) {
	bool rowOdd = false, colOdd = false;
	if (row % 2 == 1) {
		rowOdd = true;
	}
	if (col % 2 == 1) {
		colOdd = true;
	}

	if (rowOdd == colOdd) {
		return minor(matrix, size, row, col);
	}
	else {
		return -1 * minor(matrix, size, row, col);
	}

}

Polynomial minor(Polynomial** matrix, int size, int row, int col) {
	
	Polynomial** result = new double*[size - 1];
	for (int i = 0; i < size - 1; i++) {
		result[i] = new double[size - 1];
	}

	int x = 0, y = 0;

	for (int i = 0; i < size; i++) {
		if (i == row) {
			i++;
		}

		y = 0;

		for (int j = 0; j < size; j++) {
			if (j == col) {
				j++;
			}

			if (x < size && y < size) {
				result[x][y] = matrix[i][j];
			}

			y++;
		}
		x++;
	}
	
	return determinant(result, size - 1);
}

Polynomial** polyMatrix(double** matrix, int size) {
	Polynomial** result = new Polynomial*[size];
	for (int i = 0; i < size; i++) {
		result[i] = new Polynomial[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int* c, * p;
			
			if (i == j) {
				c = new int[2];
				p = new int[2];

				c[0] = matrix[i][j];
				c[1] = -1;
				p[0] = 0;
				p[1] = 1;

				result[i][j] = Polynomial(2, c, p);
			}
			else {
				c = new int[1];
				p = new int[1];

				c[0] = matrix[i][j];
				p[0] = 0;

				result[i][j] = Polynomial(1, c, p);
			}
		}
	}

	return result;
}
*/


int main()
{
	int t;

	cout << "How many terms in polynomial? YOU FAG" << endl;
	cin >> t;

	int* c = new int[t];
	int* p = new int[t];

	for (int i = 0; i < t; i++) {
		cout << "Enter coefficient" << endl;
		cin >> c[i];
		cout << "Enter power" << endl;
		cin >> p[i];
	}

	//Polynomial poly(t, c, p);

	//cout << poly;

	cin.get();
	return 0;
}