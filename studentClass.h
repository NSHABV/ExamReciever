#pragma once

#include <random>
#include "eqClass.h"

enum Sn_StudentStatus {
	StupidStudent,
	AverageStudent,
	SmartStudent
};

class Sn_Student
{
public:
	Sn_Student(const Sn_Equation &equ, const std::string& name, int isBadPercentage = 30, int isGoodPercentage = 30);

	rootStruct solveEquation();
	std::string m_studentName = "John Doe";
private:
	Sn_StudentStatus m_isStupid;
	Sn_Equation m_assignedEquation;
	std::mt19937 m_randomGen;
};