#pragma once
#include "stdafx.h"
#include "ValueAndRank.h"

class SpearmanCoeff {
private:
	static void CopyArray(double*, double*, int);
	static void SelectSort(double*, int);
	static int FindMinIndex(double*, int, int);
	static int CountUniqueElements(double*, int);
	static void InitialArrayByValues(ValueAndRank*, double*, int);
	static void InitialArrayByRanks(ValueAndRank*, double*, int, int);
	static double FindRankByValue(ValueAndRank*, double, int);
public:
	static double CalculateCoeff(double*, double*, int);	
};
