#include "include/interface.hpp"

void Interface::startUp()
{
    while(!quit)
    {
        clear();
        std::cout << "-------------------------WELCOME TO GPA ESTIMATER-------------------------\n\n";
        std::cout << "(1) Calculate SGPA\n";
        std::cout << "(2) Estimate SGPA\n";
        std::cout << "(3) Terminate/Exit\n";

        while (true)
        {
            std::cout << "Your choice: ";
            std::cin >> choice;
            if(!isInputValid()) continue;
            break;
        }

        switch(choice)
        {
        case 1:
            calculate();
            break;
        case 2:
            estimate();
            break;
        case 3:
            quit = true;
            break;
        default: break;
        }
    }
}

void Interface::calculate()
{
    bool quit = false;
    while(!quit)
    {
        clear();
        std::cout << "-------------------------------CALCULATE GPA-------------------------------\n\n";
        std::cout << "(1) Of a Subject?\n";
        std::cout << "(2) Of the whole semester?\n";
        std::cout << "(3) Or would you like to go back?\n";

        while (true)
        {
            std::cout << "Your choice: ";
            std::cin >> choice;
            if(!isInputValid()) continue;
            break;
        }

        float temp = 0;
        switch(choice)
        {
        case 1:
            temp = arithmatic.calculateSubjectGPA();
            std::cout << "The contribution of the subject of your choice to your total GPA is: " << temp << std::endl;
            break;
        case 2:
            temp = arithmatic.calculateTotalGPA();
            std::cout << "Your GPA for this semester is: " << temp << std::endl;
            break;
        case 3:
            quit = true;
            break;
        default: break;
        }
        hold();
    }
}

void Interface::estimate()
{
    bool quit = false;
    while(!quit)
    {
        clear();
        std::cout << "--------------------------------ESTIMATE GPA--------------------------------\n\n";
        std::cout << "(1) Of a Subject?\n";
        std::cout << "(2) Of the whole semester?\n";
        std::cout << "(3) Or would you like to go back?\n";
        
        while (true)
        {
            std::cout << "Your choice: ";
            std::cin >> choice;
            if(!isInputValid()) continue;
            break;
        }

        switch(choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            quit = true;
            break;
        default: break;
        }
        hold();
    }
}