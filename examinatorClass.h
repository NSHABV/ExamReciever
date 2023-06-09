#pragma once

#include "studentClass.h"

class Sn_Examinator
{
public:
	Sn_Examinator(const std::string& fileName);
	~Sn_Examinator();

	bool checkStudent(int studentIndex);
	bool compareRoots(const rootStruct& root1, const rootStruct& root2);
	void printTable();
private:
	std::vector<std::pair<Sn_Student*, Sn_Equation>> m_students;
	std::mt19937 m_randomGen;
};