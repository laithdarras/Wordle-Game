#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#define GREEN "\033[032m"
#define RESET "\033[0m"
#define GRAY "\033[090m"
#define YELLOW "\033[033m"

#include <iostream>

void displayInstructions() {
    std::cout << "=============================================" << std::endl;
    std::cout << "                 HOW TO PLAY                 " << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "Guess the Wordle in 6 tries." << std::endl;
    std::cout << "\n" << "\n";
    std::cout << "HOW TO PLAY:" << std::endl;
    std::cout << "- Each guess must be a valid 5 letter word." << std::endl;
    std::cout << "- The color of the tiles will change to show you how close your guess was to the word." << std::endl;
    std::cout << "\n" << "\n";
    std::cout << GREEN << " --- " << RESET << " ---  ---  ---  --- " << std::endl;
    std::cout << GREEN << "| R |" << RESET << "| O || C || K || Y |" << std::endl;
    std::cout << GREEN << " --- " << RESET << " ---  ---  ---  --- " << std::endl;
    std::cout << "R is in the word and in the correct spot." << "\n" << std::endl;
    std::cout << " --- " << YELLOW << " --- " << RESET << " ---  ---  --- " << std::endl;
    std::cout << "| W |" << YELLOW << "| A |" << RESET << "| T || E || R |" << std::endl;
    std::cout << " --- " << YELLOW << " --- " << RESET << " ---  ---  --- " << std::endl;
    std::cout << "A is in the word but not in the correct spot." << "\n" << std::endl;
    std::cout << " --- " << " --- " << GRAY << " --- " << RESET " ---  --- " << std::endl;
    std::cout << "| R |" << "| O |" << GRAY << "| G |" << RESET "| U || E |" << std::endl;
    std::cout << " --- " << " --- " << GRAY << " --- " << RESET " ---  --- " << std::endl;
    std::cout << "G is not in the word in any spot." << "\n" << "\n" << std::endl;
    std::cout << "Press [enter] to continue" << std::endl;
}
#endif