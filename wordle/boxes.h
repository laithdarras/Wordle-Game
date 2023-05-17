#ifndef BOXES_H
#define BOXES_H

#include <iostream>
#include <string>
#include <vector>

#define GREEN "\033[032m"
#define RESET "\033[0m"
#define GRAY "\033[090m"
#define YELLOW "\033[033m"

void printTopBox(std::string color) {
    std::cout << color << " --- " << RESET;
}

void printMiddleBox(char c, std::string color) {
    std::cout << color << "| " << c << " |" << RESET;
}

void printBottomBox(std::string color) {
    std::cout << color << " --- " << RESET;
}

void printBox(std::vector<std::string> guesses, std::string answer, std::string game, std::vector<std::vector<std::string>> colors) {
    system("clear");

    for (int i = 0; i < guesses.size(); i++) {
        
        for (int j = 0; j < 5; j++) {
            printTopBox(colors[i][j]);
        }

        std::cout << '\n';

        for (int j = 0; j < 5; j++) {
            printMiddleBox(guesses[i][j], colors[i][j]);
        }
        std::cout << '\n';

        for (int j = 0; j < 5; j++) {
            printBottomBox(colors[i][j]);
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';

    if (game == "win") {
        std::cout << '\n';
        std::cout << "Splendid!" << std::endl;
        std::cout << '\n';
        std::cout << "Please press [enter] to continue. " << std::endl;
    } else if (game == "lose") {
        std::cout << '\n';
        std::cout << "The word was " << answer << std::endl;
        std::cout << '\n';
        std::cout << "Better luck next time!" << std::endl;
        std::cout << '\n';
        std::cout << "Please press [enter] to continue. " << std::endl;
    }
}

#endif