#include "consoleController.h"

Sn_Controller::Sn_Controller(const std::string& fileName) : m_examinator(fileName)
{
}

void Sn_Controller::handleConsole()
{
	while (true)
	{
		std::string str;
		outputMenu();
		std::cin >> str;
		try
		{
			int answer = std::stoi(str);
			if (answer == 0)
				return;
			else if (answer == 1)
			{
				printTable();
				std::cout << std::endl;
			}
			else
				std::cout << "Incorrect input. Please choose one of the available options." << std::endl;
		}
		catch (std::invalid_argument const& ex)
		{
			std::cout << "Incorrect input. Please choose one of the available options." << std::endl;
			continue;
		}
	}
}

void Sn_Controller::outputMenu()
{
	std::cout << "Select your option:" << std::endl;
	std::cout << "Press 0 to exit program." << std::endl;
	std::cout << "Press 1 to output table with students' marks." << std::endl;
}

void Sn_Controller::printTable()
{
	m_examinator.printTable();
}