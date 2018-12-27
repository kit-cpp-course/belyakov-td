#pragma once
#include "stdafx.h"

//Handling data from file 
class HandlingDataFromFile{
private:
	static bool String2Double(string);
public:	
	static bool MakeArray(string, double*, int);
	static int CountElements(string);
};