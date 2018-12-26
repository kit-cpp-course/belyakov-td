#pragma once
#include "stdafx.h"
#include "SpearmanCoeff.h"
#include "HandlingDataFromFile.h"

int main(size_t count, char** arg) {

	ifstream file(arg[0]);

	if (file.is_open()) {
		string line1, line2; //two lines of our values

		getline(file, line1);
		getline(file, line2);

		file.close();

		int size1 = HandlingDataFromFile::CountElements(line1), //knowing the size of future arrays
			size2 = HandlingDataFromFile::CountElements(line2);

		//Checking correctness of the number of the values
		if (size1 <= 2 || size2 <= 2) {
			cout << "Number of values must be more than 2!" << endl;
			return 0;
		}

		if (size1 == size2) {
			double* array1 = new double[size1]; //two working arrays of data
			double* array2 = new double[size1];

			HandlingDataFromFile::MakeArray(line1, array1, size1); //fill arrays by data from the file
			HandlingDataFromFile::MakeArray(line2, array2, size1);

			//Calculate coefficient
			double rank;
			rank = SpearmanCoeff::CalculateCoeff(array1, array2, size1);
			cout << "Spearman's rank correlation coefficient: ";
			cout.precision(3);
			cout << rank << endl;

			delete[] array1;
			delete[] array2;
		}
		else {
			cout << "Number of values doesn't match!" << endl;
		}
	}
	else {
		cout << "File not found!" << endl;
	}

	system("pause");
	return 0;
}