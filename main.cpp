// A Small program for modelling a mathematics exam.
// Input: An "input.txt" text file located at ".../ExamReciever/" formatted like this: "x y z", where x, y, z are equation coefficients in double. You may add multiple rows, each corresponding to a different equation for a different student.
// Made by Shabanov Nikita, 24th April 2023.

#include <iostream>
#include <string>
#include "consoleController.h"

int main()
{
    Sn_Controller controller("input.txt");
    controller.handleConsole();
}
