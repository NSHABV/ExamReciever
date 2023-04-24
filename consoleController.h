#pragma once

#include "examinatorClass.h"

class Sn_Controller
{
public:
	Sn_Controller(const std::string& fileName);

	void outputMenu();
	void printTable();
	void handleConsole();
private:
	Sn_Examinator m_examinator;
};