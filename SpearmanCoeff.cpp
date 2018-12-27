#include "SpearmanCoeff.h"
#include "ValueAndRank.h"
#include "stdafx.h"

/*
	Ñoefficient calculation method:
	ArrX, ArrY - input arrays
	size - size of two arrays
*/
double SpearmanCoeff::CalculateCoeff(double* ArrX, double* ArrY, int size) {
	double* TempArrX = new double[size];
	double* TempArrY = new double[size];

	CopyArray(ArrX, TempArrX, size);
	CopyArray(ArrY, TempArrY, size);

	SelectSort(TempArrX, size);
	SelectSort(TempArrY, size);

	int SizeOfX = CountUniqueElements(TempArrX, size); //count unique elements to know the size of new ValueAndRank* arrays
	int SizeOfY = CountUniqueElements(TempArrY, size);

	ValueAndRank* X = new ValueAndRank[SizeOfX]; //arrays of ValueAndRank* type, where we keep values(data from the user) and their ranks
	ValueAndRank* Y = new ValueAndRank[SizeOfY];

	InitialArrayByValues(X, TempArrX, size); // fill arrays by ordered values
	InitialArrayByValues(Y, TempArrY, size);

	InitialArrayByRanks(X, TempArrX, SizeOfX, size); // fill same arrays by ranks
	InitialArrayByRanks(Y, TempArrY, SizeOfY, size);

	double Res = 0, Xi, Yi;

	for (int i = 0; i < size; i++) {
		Xi = FindRankByValue(X, ArrX[i], SizeOfX); // find rank in arrays of ValueAndRank* type
		Yi = FindRankByValue(Y, ArrY[i], SizeOfY);
		Res = Res + (Xi - Yi)*(Xi - Yi);
	}

	delete[] TempArrX;
	delete[] TempArrY;
	delete[] X;
	delete[] Y;

	return 1 - (6 * Res / (size*(size*size - 1)));
}


//Copy method
void SpearmanCoeff::CopyArray(double* Arr, double* CopyArr, int size) {
	for (int i = 0; i < size; i++) {
		CopyArr[i] = Arr[i];
	}
}

//Count the number of unique elements in array
int SpearmanCoeff::CountUniqueElements(double* Arr, int size) {
	int count = 1;
	for (int i = 1; i < size; i++) {
		if (Arr[i] != Arr[i - 1]) count++;
	}
	return count;
}

//Fill array by ordered values
void SpearmanCoeff::InitialArrayByValues(ValueAndRank* Arr, double* ArrValues, int SizeOfArrValues) {
	int index = 1;
	Arr[0].setValue(ArrValues[0]);
	for (int i = 1; i < SizeOfArrValues; i++) {
		if (ArrValues[i] != ArrValues[i - 1]) {
			Arr[index].setValue(ArrValues[i]);
			index++;
		}
	}
}

//Fill array by ranks
void SpearmanCoeff::InitialArrayByRanks(ValueAndRank* Arr, double* ArrValues, int SizeOfArr, int SizeOfArrValues) {
	double sum, rank, count;
	int index = -1;

	for (int i = 0; i < SizeOfArr; i++) {
		index++;
		sum = index + 1;
		count = 1;	
		for (int j = index; j < SizeOfArrValues; j++) {
			if (ArrValues[j] == ArrValues[j + 1]) {
				sum = sum + j + 2;
				count++;
				index++;
			}
			else break;
		}
		if (sum == index + 1) {
			Arr[i].setRank(sum);
		}
		else {
			rank = sum / count;
			Arr[i].setRank(rank);
		}
	}
}

//Sorting of array
void SpearmanCoeff::SelectSort(double* arr, int size) {
	double temp;
	int minIndex;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			minIndex = FindMinIndex(arr, size, j);
			if (arr[i] > arr[minIndex]) {
				temp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = temp;
				break;
			}
		}
	}
}

//Auxiliary method for SelectSort
int SpearmanCoeff::FindMinIndex(double* arr, int size, int index) {
	int minElem = arr[index];
	int minIndex = index;
	int iter = index++;

	for (iter; iter < size; iter++) {
		if (arr[iter] < minElem) {
			minElem = arr[iter];
			minIndex = iter;
		}
	}
	return minIndex;
}

//Get necessary rank
double SpearmanCoeff::FindRankByValue(ValueAndRank* arr, double value, int size) {
	int i = 0;
	while (arr[i].getValue() != value) {
		i++;
	}
	return arr[i].getRank();
}