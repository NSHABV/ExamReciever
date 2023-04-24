#include <sstream>
#include <iomanip>
#include "examinatorClass.h"

Sn_Examinator::Sn_Examinator(const std::string& fileName)
{
    std::ifstream extractionFile(fileName);
    std::string readLine;
    std::vector<std::string> extractedVec;

    if (!extractionFile.is_open())
    {
        std::cout << "Failed to open file " + fileName + "\n";
        return;
    }

    int currEq = 0;
    while (std::getline(extractionFile, readLine, '\n'))
    {
        std::vector<double> nums;
        std::stringstream strStream;
        strStream << readLine;

        std::string temp;
        int extractedNum;
        while (!strStream.eof()) {

            strStream >> temp;

            if (std::stringstream(temp) >> extractedNum)
                nums.push_back(extractedNum);

            temp = "";
        }

        if (nums.size() == 3)
        {
            Sn_Equation addEquation(nums.at(0), nums.at(1), nums.at(2));
            Sn_Student addStudent(addEquation, "JohnDoe " + std::to_string(currEq));

            m_students.push_back(std::make_pair(addStudent, addEquation));
        }
        currEq++;
    }

    extractionFile.close();
}

bool Sn_Examinator::checkStudent(int studentIndex)
{
    if (studentIndex > m_students.size() - 1)
        return false;

    auto currPair = m_students.at(studentIndex);
    auto rootsFirst = currPair.first.solveEquation();
    auto rootsTrue = currPair.second.getRoots();

    return compareRoots(rootsFirst, rootsTrue);
}

bool Sn_Examinator::compareRoots(const rootStruct& root1, const rootStruct& root2)
{
    if (root1.rootCount != root2.rootCount)
        return false;
    
    if (root1.rootCount == 0)
        return true;

    if (root1.firstRoot != root2.firstRoot || root1.secondRoot != root2.secondRoot)
        return false;

    return true;
}

void Sn_Examinator::printTable()
{
    std::cout << std::setw(4) << "ID";
    std::cout << " | " << std::setw(30) << "NAME";
    std::cout << " | " << std::setw(6) << "RESULT";
    std::cout << std::endl;
    for (int i = 0; i < m_students.size(); i++)
    {
        bool result = checkStudent(i);
        auto name = m_students.at(i).first.m_studentName;
        std::cout << std::setw(4) << i;
        std::cout << " | " << std::setw(30) << name;
        if (result)
            std::cout << " | " << std::setw(6) << "true";
        else
            std::cout << " | " << std::setw(6) << "false";
        std::cout << std::endl;
    }
}
//coeffStruct m_coefficients;
//std::vector<CheckStruct> m_students;