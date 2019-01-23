#pragma once
#include "ValueAndRank.h"
#include "CorrelCoeff.h"

/*
	Class of Spearman's coefficient:
	Do its calculation
*/
class SpearmanCoeff : public CorrelCoeff {
private:
	//Count unique elements in the array
	int CountUniqueElements(double*, int);
	//Initial ValueAndRank* array by values
	void InitialArrayByValues(ValueAndRank*, double*, int);
	//Initial ValueAndRank* array by ranks
	void InitialArrayByRanks(ValueAndRank*, double*, int, int);
	//Get rank by value in the ValueAndRank* array
	double FindRankByValue(ValueAndRank*, double, int);
protected:
	//Make a copy of primary array
	void CopyArray(double*, double*, int);
	//Make a select sort of the array 
	void SelectSort(double*, int);
	//Find the index of minimal element in the array
	int FindMinIndex(double*, int, int);
public:
	//Constructor
	SpearmanCoeff(double*, double*, int);
	//Calculate the coefficient of correlation
	double CalculateCoeff() override;
};