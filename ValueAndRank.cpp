#include "ValueAndRank.h"
#include "stdafx.h"

ValueAndRank::ValueAndRank() {}

double ValueAndRank::getValue() {
	return value;
}

double ValueAndRank::getRank() {
	return rank;
}

void ValueAndRank::setValue(double argVal) {
	this->value = argVal;
}

void ValueAndRank::setRank(double argRnk) {
	this->rank = argRnk;
}