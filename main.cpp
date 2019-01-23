#include "stdafx.h"
#include "SpearmanCoeff.h"
#include "CorrelCoeff.h"
#include "HandlingDataFromFile.h"

using namespace std;

int main(size_t count, char* arg[]) {
	string inFile = "", outFile = "";

	if (count == 5) {
		for (int i = 1; i < count; i++) {
			if (!strcmp(arg[i], "/in")) {
				inFile = arg[i + 1];
			}
			if (!strcmp(arg[i], "/out")) {
				outFile = arg[i + 1];
			}
		}
	}
	else
	{
		cout << "Enter data!" << count << endl;
		return 0;
	}

	ifstream inputFile(inFile);

	if (inputFile.is_open()) {
		string lineX, lineY; //two lines of our values

		getline(inputFile, lineX);
		getline(inputFile, lineY);

		inputFile.close();

		int sizeX = HandlingDataFromFile::CountElements(lineX), //knowing the size of future arrays
			sizeY = HandlingDataFromFile::CountElements(lineY);

		//Checking correctness of the number of the values
		if (sizeX <= 2 || sizeY <= 2) {
			cout << "Number of values must be more than 2!" << endl;
			return 0;
		}

		if (sizeX == sizeY) {
			double* arrayX = new double[sizeX]; //two working arrays of data
			double* arrayY = new double[sizeY];

			//If it's possible, fill arrays by data from the file
			if (!HandlingDataFromFile::MakeArray(lineX, arrayX, sizeX) || !HandlingDataFromFile::MakeArray(lineY, arrayY, sizeY)) {
				cout << "Uncorrect data!" << endl;
				delete[] arrayX;
				delete[] arrayY;
				return 0;
			};

			//Calculate coefficient
			ofstream outputFile(outFile, ios::app);
			CorrelCoeff * CrCoeff = new SpearmanCoeff(arrayX, arrayY, sizeX);
			outputFile << CrCoeff->getName() << ": " << CrCoeff->CalculateCoeff() << endl;
			cout << "The calculation was successful" << endl;

			delete CrCoeff;
			delete[] arrayX;
			delete[] arrayY;
		}
		else {
			cout << "Number of values doesn't match!" << endl;
		}
	}
	else {
		cout << "File not found!" << endl;
	}

	return 0;
}