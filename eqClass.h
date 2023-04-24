#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct rootStruct
{
	int rootCount;
	double firstRoot, secondRoot;
};

struct coeffStruct
{
	double squareXCoeff = 0;
	double regXCoeff = 0;
	double constantCoeff = 0;

	bool failureFlag = 0;
};

class Sn_Equation
{
public:
	Sn_Equation(const std::string &fileName);
	Sn_Equation(double squareXCoeff, double regXCoeff, double constantCoeff);

	bool outputRootsToFile(const std::string &fileName);
	rootStruct getRoots();
	double calculateDeterminant();
private:
	coeffStruct m_coefficients;
};