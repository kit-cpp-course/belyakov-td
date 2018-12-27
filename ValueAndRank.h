#pragma once
#include "stdafx.h"

//Class that contain value and its rank
class ValueAndRank {
	double value;
	double rank;
public:
	ValueAndRank();
	double getValue();
	double getRank();
	void setValue(double);
	void setRank(double);
};
