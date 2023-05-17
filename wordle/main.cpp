#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#define GREEN "\033[032m"
#define RESET "\033[0m"
#define GRAY "\033[090m"
#define YELLOW "\033[033m"

#include "game.h"
#include "statistics.h"
#include "menu.h"
#include "statistics_screen.h"
#include "instructions.h"
#include "gameStats.h"

using namespace std;

// struct gameStats {
//     int game;
//     int timesPlayed;
//     int averageAttempts;
//     int winPercentage;
//     int currentStreak;
//     int longestStreak;
//     vector<string> words;
//     vector<string> wins;
//     vector<int> attempts;
// };

int main(int argc, char* argv[]) {
    int length;
    std::string wordsName;
    std::string allowedName;
    if (argc == 4) {
        length = stoi(argv[1]);
        wordsName = argv[2];
        allowedName = argv[3]; 
    } else {
        length = 5;
        wordsName = "5-words.txt";
        allowedName = "5-allowed.txt";
    }

    if (argc > 2) {
        cerr << "Error: Ivalid number of arguments" << endl;
        return 1;
    }
    
    gameStats stats;
    string userInput;

    system("clear");
    loadStatsToFile(stats);
    saveStatsToFile(stats);
    printMenu();

    while (cin >> userInput) {
        cin.ignore();
        if (userInput == "5") {
            stats.game = 0;
            saveStatsToFile(stats);
            playGame(stats);
            stats.game = 1;
            saveStatsToFile(stats);
        } else if (userInput == "1") {
            system("clear");
            stats.game = 2;
            saveStatsToFile(stats);
            playGame(stats);
            stats.game = 1;
            saveStatsToFile(stats);
        } else if (userInput == "2") {
            while (!userInput.empty()) {
                system("clear");
                displayInstructions();
            }
            getline(cin, userInput);
        } else if (userInput == "3") {
            while (!userInput.empty()) {
                system("clear");
                displayStats(stats.timesPlayed);
                displayStats(stats.averageAttempts);
                displayStats(stats.winPercentage);
                displayStats(stats.currentStreak);
                displayStats(stats.longestStreak);
                displayStats(stats.words);
                displayStats(stats.attempts);
                displayStats(stats.wins);
            }
            getline(cin, userInput);
        } else if (userInput == "4") {
            resetStats();
            loadStatsToFile();
            while(!userInput.empty()) {
                system("clear");
                displayStats(stats.timesPlayed);
                displayStats(stats.averageAttempts);
                displayStats(stats.winPercentage);
                displayStats(stats.currentStreak);
                displayStats(stats.longestStreak);
                displayStats(stats.words);
                displayStats(stats.attempts);
                displayStats(stats.wins);
            }
            getline(cin, userInput);
        } 
        
        system("clear");
        printMenu();
    }

    return 0;
}