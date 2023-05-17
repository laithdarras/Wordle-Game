#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#define GREEN "\033[032m"
#define RESET "\033[0m"
#define GRAY "\033[090m"
#define YELLOW "\033[033m"

void displayKeyboard(std::vector<std::string> color, std::vector<int> index) {
    for (int i = 0; i < index.size(); i++) {
        color[index[i]] = GREEN;
    }

    std::cout << color[int('Q') -65] << " --- " << RESET << color[int('W') -65] << " --- " << RESET << color[int('E') -65] << " --- " << RESET << color[int('R') -65] << " --- " << RESET << color[int('T') -65] 
    << " --- " << RESET << color[int('Y') -65] << " --- " << RESET << color[int('U') -65] << " --- " << RESET << color[int('I') -65] << " --- " << RESET << color[int('O') -65] << " --- " << RESET << color[int('P') -65] << " --- " << RESET << std::endl;

    std::cout << color[int('Q') -65] << "| Q |" << RESET << color[int('W') -65] << "| W |" << RESET << color[int('E') -65] << "| E |" << RESET << color[int('R') -65] << "| R |" << RESET << color[int('T') -65] 
    << "| T |" << RESET << color[int('Y') -65] << "| Y |" << RESET << color[int('U') -65] << "| U |" << RESET << color[int('I') -65] << "| I |" << RESET << color[int('O') -65] << "| O |" << RESET << color[int('P') -65] << "| P |" << RESET << std::endl;

    std::cout << color[int('Q') -65] << " --- " << RESET << color[int('W') -65] << " --- " << RESET << color[int('E') -65] << " --- " << RESET << color[int('R') -65] << " --- " << RESET << color[int('T') -65] 
    << " --- " << RESET << color[int('Y') -65] << " --- " << RESET << color[int('U') -65] << " --- " << RESET << color[int('I') -65] << " --- " << RESET << color[int('O') -65] << " --- " << RESET << color[int('P') -65] << " --- " << RESET << std::endl;



    std::cout << color[int('A') -65] << "   --- " << RESET << color[int('S') -65] << " --- " << RESET << color[int('D') -65] << " --- " << RESET << color[int('F') -65] << " --- " << RESET << color[int('G') -65] 
    << " --- " << RESET << color[int('H') -65] << " --- " << RESET << color[int('J') -65] << " --- " << RESET << color[int('K') -65] << " --- " << RESET << color[int('L') -65] << " ---" << RESET << std::endl;

    std::cout << color[int('A') -65] << "| A |" << RESET << color[int('S') -65] << "| S |" << RESET << color[int('D') -65] << "| D |" << RESET << color[int('F') -65] << "| F |" << RESET << color[int('G') -65] 
    << "| G |" << RESET << color[int('H') -65] << "| H |" << RESET << color[int('J') -65] << "| J |" << RESET << color[int('K') -65] << "| K |" << RESET << color[int('L') -65] << "| L |" << RESET << std::endl;

    std::cout << color[int('A') -65] << "   --- " << RESET << color[int('S') -65] << " --- " << RESET << color[int('D') -65] << " --- " << RESET << color[int('F') -65] << " --- " << RESET << color[int('G') -65] 
    << " --- " << RESET << color[int('H') -65] << " --- " << RESET << color[int('J') -65] << " --- " << RESET << color[int('K') -65] << " --- " << RESET << color[int('L') -65] << " ---" << RESET << std::endl;



    std::cout << color[int('Z') -65] << "        --- " << RESET << color[int('X') -65] << " --- " << RESET << color[int('C') -65] << " --- " << RESET << color[int('V') -65] << " --- " << RESET << color[int('B') -65] 
    << " --- " << RESET << color[int('N') -65] << " --- " << RESET << color[int('M') -65] << " --- " << RESET << std::endl;

    std::cout << color[int('Z') -65] << "       | Z |" << RESET << color[int('X') -65] << "| X |" << RESET << color[int('C') -65] << "| C |" << RESET << color[int('V') -65] << "| V |" << RESET << color[int('B') -65] 
    << "| B |" << RESET << color[int('N') -65] << "| N |" << RESET << color[int('M') -65] << "| M |" << RESET << std::endl;

    std::cout << color[int('Z') -65] << "        --- " << RESET << color[int('X') -65] << " --- " << RESET << color[int('C') -65] << " --- " << RESET << color[int('V') -65] << " --- " << RESET << color[int('B') -65] 
    << " --- " << RESET << color[int('N') -65] << " --- " << RESET << color[int('M') -65] << " --- " << RESET << std::endl;

    return;

}

#endif