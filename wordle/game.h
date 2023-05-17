#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include <bits/stdc++.h>
#include <unordered_set>
#include <limits>
#include <random>
#include "boxes.h"
#include "gameStats.h"
#define GREEN "\033[032m"
#define RESET "\033[0m"
#define GRAY "\033[090m"
#define YELLOW "\033[033m"


std::string getRandomWord() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr(0, 2315);

    int number = distr(gen);
    std::string lower;

    std::ifstream wordsFile("words.txt");

    for (int i = 0; i < number; i++) {
        getline(wordsFile, lower);
    }
    wordsFile.close();
    return lower;
}



std::vector<std::string> checkGuess(std::string guess, std::string word, int length) {
    std::vector<std::string> color = {GRAY, GRAY, GRAY, GRAY, GRAY};

    for (int i = 0; i < 10; i++) {
        size_t index = word.find(guess[i % length]);

        if (floor((float) i / float(length)) == 0) {
            
            if (index != std::string::npos && index == (i % length)) {
                color[index] = GREEN;
            }
        } else {
            if (index != std::string::npos) {
                color[i % length] = YELLOW;
                word[index] = ' ';
            }
        }
    }

    return color;
}


void getColorString(std::vector<std::vector<std::string>> colors, std::string guess, int length) {
    std::string gray;
    std::string yellow;
    std::string green;

    std::ifstream keyboard_file_in("keyboard.txt");
    
    if (keyboard_file_in.is_open()) {
        std::string colorString;
        getline(keyboard_file_in, colorString);
        gray = colorString + std::string(length, ' ');
        getline(keyboard_file_in, colorString);
        yellow = colorString + std::string(length, ' ');
        getline(keyboard_file_in, colorString);
        green = colorString + std::string(length, ' ');
    } else {
        std::cerr << "Error: Failed to open keyboard file for reading. " << std::endl;
    }
    keyboard_file_in.close();

    std::ofstream keyboard_file_out("keyboard.txt", std::ios::trunc);

    if (keyboard_file_out.is_open()) {
        
        for (int i = 0; i < length; i++) {
            if (colors.back()[i] == GRAY) {
                gray[gray.size() -length +i] = guess[i];
            } else if (colors.back()[i] == YELLOW) {
                yellow[yellow.size() -length +i] = guess[i];
            } else if (colors.back()[i] == GREEN) {
                green[green.size() -length +i] = guess[i];
            }
        }

        keyboard_file_out << gray << '\n' << yellow << '\n' << green;
    } else {
        std::cerr << "Error: Failed to open keyboard file for writing. " << std::endl;
    }

    keyboard_file_out.close();
}


void playGame(gameStats& stats, int length) {

    std::vector<std::string> guesses;
    std::vector<std::vector<std::string>> colors;
    std::string game = "active";

    bool validGuess = false;
    std::string answer = getRandomWord();
    std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

    while (game == "active") {
        bool validGuess = false;
        std::string guess;
        std::string line;

        while (!validGuess) {
            std::ifstream allowedWords("allowed.txt");
            std::ifstream wordsFile("words.txt");
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            while (getline(allowedWords, line) || getline(wordsFile, line)) {
                if (line.find(guess) != std::string::npos && guess.size() == length) {
                    validGuess = true;
                    break;
                }
            }

            allowedWords.close();
            wordsFile.close();
        }

        std::transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        guesses.push_back(guess);
        colors.push_back(checkGuess(guess, answer, length));
        getColorString(colors, guess, length);

        if (guess == answer) {
            game = "win";
        } else if (guesses.size() == 6) {
            game = "lose";
        }
        printBox(guesses, answer, game, colors);
    }

    stats.words.push_back(answer);
    stats.attempts.push_back(guesses.size());
    stats.wins.push_back((game = "win" ? "Yes" : "No"));
    std::cin.ignore();

    while (!game.empty()) {
        getline(std::cin, game);
    }
}

#endif