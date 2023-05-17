#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "gameStats.h"

void loadStatsToFile(gameStats& stats) {
    
    std::ifstream statsFile("stats.txt");
    if (statsFile) {
        stats.words.clear();
        stats.attempts.clear();
        stats.wins.clear();
        statsFile >> stats.game >> stats.timesPlayed >> stats.averageAttempts >> stats.winPercentage >> stats.currentStreak >> stats.longestStreak;
        std::string line;
        getline(statsFile, line);
        while (getline(statsFile, line)) {
            std::istringstream iss(line);
            std::string word;
            std::string win;
            int attempt;
            iss >> word >> attempt >> win;

            stats.words.push_back(word);
            stats.attempts.push_back(attempt);
            stats.wins.push_back(win);
        }

        stats.game = 1;
    } else {
        std::cerr << "Error: Failed to open stats file for writing" << std::endl;
    }
}


void saveStatsToFile(gameStats& stats) {

    std::ofstream statsFile("stats.txt", std::ios::trunc);
    if (statsFile.is_open()) {
        int numWins = 0;
        int totalAttempts = 0;
        int currentStreak = 0;
        int longestStreak = 0;
        for (std::string win : stats.wins) {
            if (win == "Yes") {
                numWins++;
                currentStreak++;
                
                if (currentStreak > longestStreak) {
                    longestStreak = currentStreak;
                }
            } else {
                currentStreak = 0;
            }
        }

        for (int i : stats.attempts) totalAttempts = totalAttempts + i;
            stats.timesPlayed = stats.words.size();
            stats.averageAttempts = stats.timesPlayed ? totalAttempts / stats.attempts.size() : 0;
            stats.winPercentage = stats.timesPlayed ? ((float) numWins / stats.wins.size()) * 100 : 0;
            stats.currentStreak = currentStreak;
            stats.longestStreak = longestStreak;
            statsFile << stats.game << ' ' << stats.timesPlayed << ' ' << stats.averageAttempts << ' ' << stats.winPercentage << ' ' << stats.currentStreak << ' ' << stats.longestStreak << '\n';

            for (int i = 0; i < stats.words.size(); i++) {
                statsFile << stats.words[i] << ' ' << stats.attempts[i] << ' ' << stats.wins[i] << '\n';
            }
            statsFile.close();
    } else {
        std::cerr << "Error: Failed to open stats file for writing" << std::endl;
    }
}

void resetStats() {
    std::ofstream statsFile("stats.txt", std::ios::trunc);
    if (statsFile.is_open()) {
        statsFile << "1 0 0 0 0 0";
        statsFile.close();
    } else {
        std::cerr << "Error: Failed to open stats file for writing" << std::endl;
    }
}
#endif