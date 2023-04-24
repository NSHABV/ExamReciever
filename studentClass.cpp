#include "studentClass.h"

Sn_Student::Sn_Student(const Sn_Equation& equ, const std::string& name, int isBadPercentage, int isGoodPercenage) : m_assignedEquation(equ)
{
	std::random_device device;
	m_randomGen.seed(device());
	std::uniform_int_distribution<int> range(0, 100);

	m_assignedEquation = equ;
	m_studentName = name;

	int rolledChance = range(m_randomGen);
	if (rolledChance > 100 - isGoodPercenage)
	{
		m_isStupid = Sn_StudentStatus::SmartStudent;
		return;
	}
	else if (rolledChance < isBadPercentage)
	{
		m_isStupid = Sn_StudentStatus::StupidStudent;
		return;
	}
	else
	{
		m_isStupid = Sn_StudentStatus::AverageStudent;
		return;
	}
}

rootStruct Sn_Student::solveEquation()
{
	if (m_isStupid == Sn_StudentStatus::StupidStudent)
	{
		rootStruct returnedRoots;
		returnedRoots.firstRoot = 0;
		returnedRoots.secondRoot = 0;
		returnedRoots.rootCount = 1;
		return returnedRoots;
	}
	else if (m_isStupid == Sn_StudentStatus::SmartStudent)
		return m_assignedEquation.getRoots();
	else
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
}