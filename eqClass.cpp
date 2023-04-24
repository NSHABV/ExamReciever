#include <string>
#include "eqClass.h"

Sn_Equation::Sn_Equation(const std::string &fileName)
{
    std::ifstream extractionFile(fileName);
    std::string readLine;
    std::vector<std::string> extractedVec;

    if (!extractionFile.is_open())
    {
        std::cout << "Failed to open file " + fileName + "\n";
        m_coefficients.failureFlag = 1;
        return;
    }

    while (std::getline(extractionFile, readLine, ' '))
        extractedVec.push_back(readLine);

    extractionFile.close();

    auto vecSize = extractedVec.size();
    switch (vecSize)
    {
    case 2:
        try
        {
            m_coefficients.constantCoeff = std::stod(extractedVec.at(1));
            m_coefficients.regXCoeff = std::stod(extractedVec.at(0));
            m_coefficients.squareXCoeff = 0;
            m_coefficients.failureFlag = 0;
        }
        catch (std::invalid_argument const& ex)
        {
            m_coefficients.constantCoeff = 0;
            m_coefficients.regXCoeff = 0;
            m_coefficients.squareXCoeff = 0;
            m_coefficients.failureFlag = 1;
            return;
        }
        return;
    case 3:
        try
        {
            m_coefficients.constantCoeff = std::stod(extractedVec.at(2));
            m_coefficients.regXCoeff = std::stod(extractedVec.at(1));
            m_coefficients.squareXCoeff = std::stod(extractedVec.at(0));
            m_coefficients.failureFlag = 0;
        }
        catch (std::invalid_argument const& ex)
        {
            m_coefficients.constantCoeff = 0;
            m_coefficients.regXCoeff = 0;
            m_coefficients.squareXCoeff = 0;
            m_coefficients.failureFlag = 1;
            return;
        }
        return;
    default:
        std::cout << "Input parameters inconclusive.\n";

        m_coefficients.constantCoeff = 0;
        m_coefficients.regXCoeff = 0;
        m_coefficients.squareXCoeff = 0;
        m_coefficients.failureFlag = 1;
        return;
    }
}

Sn_Equation::Sn_Equation(double squareXCoeff, double regXCoeff, double constantCoeff)
{
    m_coefficients.constantCoeff = constantCoeff;
    m_coefficients.regXCoeff = regXCoeff;
    m_coefficients.squareXCoeff = squareXCoeff;
    m_coefficients.failureFlag = 0;
}

double Sn_Equation::calculateDeterminant()
{
    if (m_coefficients.failureFlag)
        return 0;
   
    if (!m_coefficients.squareXCoeff == 0)
    {
        double preSqrt = m_coefficients.regXCoeff * m_coefficients.regXCoeff - 4 * m_coefficients.squareXCoeff * m_coefficients.constantCoeff;
        if (preSqrt < 0)
            return -1;

        double det = std::sqrt(preSqrt);
        return det;
    }
    else
        return -1;
}

rootStruct Sn_Equation::getRoots()
{
    rootStruct calcedRoots;

    if (m_coefficients.failureFlag)
    {
        std::cout << "Equation failed to initialize - impossible to solve.\n";
        calcedRoots.rootCount = 0;
        return calcedRoots;
    }

    float det = calculateDeterminant();
    if (det < 0 && m_coefficients.squareXCoeff != 0)
    {
        calcedRoots.rootCount = 0;
        return calcedRoots;
    }

    if (m_coefficients.squareXCoeff != 0)
    {
        float det = calculateDeterminant();
        if (det == 0)
        {
            calcedRoots.rootCount = 1;
            calcedRoots.firstRoot = -1 * m_coefficients.regXCoeff * 0.5 / m_coefficients.squareXCoeff;
            return calcedRoots;
        }
        else
        {
            calcedRoots.rootCount = 2;
            calcedRoots.firstRoot = (-1 * m_coefficients.regXCoeff + det) * 0.5 / m_coefficients.squareXCoeff;
            calcedRoots.secondRoot = (-1 * m_coefficients.regXCoeff - det) * 0.5 / m_coefficients.squareXCoeff;
            return calcedRoots;
        }
    }
    else if (m_coefficients.regXCoeff != 0)
    {
        calcedRoots.rootCount = 1;
        calcedRoots.firstRoot = -1 * m_coefficients.constantCoeff / m_coefficients.regXCoeff;
        return calcedRoots;
    }
    else
    {
        std::cout << "Equation cannot be solved due to lack of coefficients.\n";
        calcedRoots.rootCount = 0;
        return calcedRoots;
    }
}

bool Sn_Equation::outputRootsToFile(const std::string &fileName)
{
    if (m_coefficients.failureFlag)
    {
        std::cout << "Equation failed to initialize - impossible to solve.\n";
        return false;
    }

    std::ofstream writeFile(fileName, std::ofstream::trunc);
    if (!writeFile.is_open())
    {
        std::cout << "Failed to open file " + fileName + "\n";
        return false;
    }

    rootStruct calcedRoots = getRoots();
    switch (calcedRoots.rootCount)
    {
    case 1:
        writeFile << calcedRoots.firstRoot;
        writeFile.close();
        return true;
    case 2:
        writeFile << std::to_string(calcedRoots.firstRoot);
        writeFile << " ";
        writeFile << std::to_string(calcedRoots.secondRoot);
        writeFile.close();
        return true;
    default:
        writeFile << "No roots.";
        writeFile.close();
        return true;
    }
}

/*
void main(void)
{
    auto extractedCoeffs = initFromFile("input.txt");

    if (extractedCoeffs.failureFlag == 1)
    {
        std::cout << "Equation initialization failure.\n";
        return;
    }

    auto calculatedRoots = getRoots(extractedCoeffs.squareXCoeff, extractedCoeffs.regXCoeff, extractedCoeffs.constantCoeff);
    if (outputRootsToFile("output.txt", calculatedRoots))
    {
        std::cout << "Successfully wrote roots into output file: ";
        std::cout << "output.txt\n";
    }
    else
        std::cout << "Failed to output roots.\n";
}
*/