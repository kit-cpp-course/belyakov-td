#pragma once
#include "stdafx.h"

//Class that contain value and its rank
class ValueAndRank {
	//Fields of class
	double value;
	double rank;
public:
	//Constructor without parameters
	ValueAndRank();
	//Methods which return value or rank
	double getValue();
	double getRank();
	//Methods which set value or rank
	void setValue(double);
	void setRank(double);
};