#ifndef MENU_H
#define MENU_H

#include <iostream>

void printMenu() { 
    std::cout << "=========================" << std::endl;
    std::cout << "    WELCOME TO WORDLE    " << std::endl;
    std::cout << "=========================" << "\n" << "\n" << std::endl;
    std::cout << "1. Play Wordle" << std::endl;
    std::cout << "2. How to Play" << std::endl;
    std::cout << "3. Statistics Summary" << std::endl;
    std::cout << "4. Reset Statistics" << std::endl;
    std::cout << "5. Exit" << "\n" << "\n" << std::endl;
    std::cout << "Select an option: " << std::endl;
}
#endif