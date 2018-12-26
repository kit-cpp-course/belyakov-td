#include "HandlingDataFromFile.h"
#include "stdafx.h"

//Get numbers from the line and put their in array
void HandlingDataFromFile::MakeArray(string line, double* arr, int size) {
	int length = line.size(),
		i = 0,
		index = 0;
	string strValue = "";
	double dblValue;

	line += ' ';
	for (int i = 0; i <= length; i++) {
		if (line[i] != ' ') {
			strValue += line[i];
		}
		else {
			dblValue = atof(strValue.c_str());
			arr[index] = dblValue;
			index++;
			strValue = "";
		}
	}
}

//Count numbers in the line
int HandlingDataFromFile::CountElements(string line) {
	int length = line.size(),
		count = 1;

	for (int i = 0; i < length; i++) {
		if (line[i] == ' ') {
			count++;
		}
	}
	return count;
}