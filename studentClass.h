#pragma once

#include <random>
#include "eqClass.h"

class Sn_Student
{
public:
	Sn_Student(const Sn_Equation &equ, const std::string& name, int isBadPercentage = 30, int isGoodPercentage = 30);

	virtual rootStruct solveEquation();
	std::string m_studentName = "John Doe";
protected:
	Sn_Equation m_assignedEquation;
	std::mt19937 m_randomGen;
};

class Sn_AverageStudent : public Sn_Student
{
public:
	Sn_AverageStudent(const Sn_Equation& equ, const std::string& name, int isBadPercentage = 30, int isGoodPercentage = 30)
	: Sn_Student(equ, name, isBadPercentage, isGoodPercentage)
	{
	}

	rootStruct solveEquation();
	std::string m_studentName = "John Doe";
};

class Sn_StupidStudent : public Sn_Student
{
public:
	Sn_StupidStudent(const Sn_Equation& equ, const std::string& name, int isBadPercentage = 30, int isGoodPercentage = 30)
	: Sn_Student(equ, name, isBadPercentage, isGoodPercentage)
	{
	}

	rootStruct solveEquation();
	std::string m_studentName = "John Doe";
};

class Sn_SmartStudent : public Sn_Student
{
public:
	Sn_SmartStudent(const Sn_Equation& equ, const std::string& name, int isBadPercentage = 30, int isGoodPercentage = 30)
	: Sn_Student(equ, name, isBadPercentage, isGoodPercentage)
	{
	}

	rootStruct solveEquation();
	std::string m_studentName = "John Doe";
};