#include "include/clearConsole.hpp"

void clear()
{
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        // std::cout << "\0[1;1H\0[2J\0[3J";
        std::cout << "[H[2J[3J";
    #endif
}

void hold()
{
    char ch = '\0';
    std::cout << "\n\n(1) Go Back: ";
    std::cin >> ch;
}