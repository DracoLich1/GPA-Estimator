#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include "clearConsole.hpp"
#include "arithmatic.hpp"

bool isInputValid();

class Interface
{
private:
    int choice = -1;
    Arithmatic arithmatic;
    bool quit = false;
public:
    Interface() {}
    ~Interface() {}

    void startUp();
    void calculate();
    void estimate();
};