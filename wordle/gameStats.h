#ifndef GAME_STATS_H
#define GAME_STATS_H
#include <iostream>
#include <vector>
#include <string>


struct gameStats {
    int game;
    int timesPlayed;
    int averageAttempts;
    int winPercentage;
    int currentStreak;
    int longestStreak;
    std::vector<std::string> words;
    std::vector<std::string> wins;
    std::vector<int> attempts;
};

#endif