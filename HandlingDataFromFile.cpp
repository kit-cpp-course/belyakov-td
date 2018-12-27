#include "HandlingDataFromFile.h"
#include "stdafx.h"

//Get numbers from the line and put their in array
bool HandlingDataFromFile::MakeArray(string line, double* arr, int size) {
	int length = line.size(),
		arrIndex = 0,
		lineIndex = 0;
	string strValue = "";
	double dblValue;

	line += ' ';
	while (line[lineIndex] == ' ') {
		lineIndex++;
	}
	for (int i = lineIndex; i <= length; i++) {
		if (line[i] != ' ') {
			strValue += line[i];
		}
		else if (String2Double(strValue)) {
				dblValue = stod(strValue);
				arr[arrIndex] = dblValue;
				arrIndex++;
				strValue = "";
		}
		else {
			return false;
		}
	}
	return true;
}

//Converting from string to double (return false if unsuccessful)
bool HandlingDataFromFile::String2Double(string strValue) {
	int length = strValue.size();
	int temp;
	for (int i = 0; i < length; i++) {
		if (strValue[i] == '.') {
			continue;
		}
		if (int(strValue[i]) < 48 || int(strValue[i]) > 57) {
			return false;
		}
	}
	return true;
}

//Count numbers in the line
int HandlingDataFromFile::CountElements(string line) {
	int length = line.size(),
		count = 1,
		lineIndex = 0;

	while (line[lineIndex] == ' ') {
		lineIndex++;
	}
	for (int i = lineIndex; i < length; i++) {
		if (line[i] == ' ') {
			count++;
		}
	}
	return count;
}