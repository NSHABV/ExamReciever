#include "studentClass.h"

Sn_Student::Sn_Student(const Sn_Equation& equ, const std::string& name, int isBadPercentage, int isGoodPercenage) : m_assignedEquation(equ)
{
	std::random_device device;
	m_randomGen.seed(device());
	std::uniform_int_distribution<int> range(0, 100);

	m_assignedEquation = equ;
	m_studentName = name;

	int rolledChance = range(m_randomGen);
}

rootStruct Sn_Student::solveEquation()
{
	rootStruct returnedRoots;
	returnedRoots.firstRoot = 999;
	returnedRoots.secondRoot = 999;
	returnedRoots.rootCount = 1;
	return returnedRoots;
}

rootStruct Sn_StupidStudent::solveEquation()
{
	rootStruct returnedRoots;
	returnedRoots.firstRoot = 0;
	returnedRoots.secondRoot = 0;
	returnedRoots.rootCount = 1;
	return returnedRoots;
}

rootStruct Sn_SmartStudent::solveEquation()
{
	return m_assignedEquation.getRoots();
}

rootStruct Sn_AverageStudent::solveEquation()
{
	std::uniform_int_distribution<int> range(0, 100);
	int rolledChance = range(m_randomGen);

	if (rolledChance > 50)
		return m_assignedEquation.getRoots();
	else
	{
		rootStruct returnedRoots;
		returnedRoots.firstRoot = 0;
		returnedRoots.secondRoot = 0;
		returnedRoots.rootCount = 1;
		return returnedRoots;
	}
}