#pragma once
#include "stdafx.h"

//Abstract class of any correlation coefficient
class CorrelCoeff {
	std::string Name;
protected:
	//Two sets of values and its size
	double* dataX;
	double* dataY;
	int SizeOfData;
public:
	//Constructor
	CorrelCoeff(double* X, double*Y, int size, std::string name) : SizeOfData(size), Name(name) {
		dataX = new double[size];
		dataY = new double[size];
		for (int i = 0; i < size; i++) {
			dataX[i] = X[i];
			dataY[i] = Y[i];
		}
	}
	//Destructor
	~CorrelCoeff() {
		delete[] dataX;
		delete[] dataY;
	}
	//Method that calculate coefficient
	virtual double CalculateCoeff() = 0;
};
