#pragma once
#include "stdafx.h"

//Make handling data from file 
class HandlingDataFromFile {
private:
	//Do conversion from string to double
	static bool String2Double(std::string);
public:
	//If it's possible fill array with values from the line and return true, in the other way return false
	static bool MakeArray(std::string, double*, int);
	//Count elements in the line
	static int CountElements(std::string);

};
