#ifndef STATISTICS_SCREEN_H
#define STATISTICS_SCREEN_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


void displayStats(int length) {
    int timesPlayed;
    int averageAttempts;
    int winPercentage;
    int currentStreak;
    int longestStreak;
    std::vector<std::string> words;
    std::vector<int> attempts;
    std::vector<std::string> wins;

    // std::cout << "==========================" << std::endl;
    // std::cout << "    STATISTICS SUMMARY    " << std::endl;
    // std::cout << "==========================" << std::endl;
    // std::cout << "Times Played:       " << std::setw(13) << std::right << timesPlayed << std::endl;
    // std::cout << "Average Attempts:   " << std::setw(9) << std::right << averageAttempts << std::endl;
    // std::cout << "Win Percentage:     " << std::setw(10) << std::right << winPercentage << "%" <<std::endl;
    // std::cout << "Current Streak:     " << std::setw(11) << std::right << currentStreak << std::endl;
    // std::cout << "Longest Streak:     " << std::setw(11) << std::right << longestStreak << "\n" << std::endl;
    // std::cout << "--------------------------" << std::endl;
    // std::cout << "WORD     ATTEMPTS      WIN" << std::endl;
    // std::cout << "--------------------------" << std::endl;

    // Change the setw to make it dynamic
    std::cout << "==========================" << std::endl;
    std::cout << "    STATISTICS SUMMARY    " << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Times Played:       " << std::setw(length -5) << std::right << timesPlayed << std::endl;
    std::cout << "Average Attempts:   " << std::setw(length -5) << std::right << averageAttempts << std::endl;
    std::cout << "Win Percentage:     " << std::setw(length -5) << std::right << winPercentage << "%" <<std::endl;
    std::cout << "Current Streak:     " << std::setw(length -5) << std::right << currentStreak << std::endl;
    std::cout << "Longest Streak:     " << std::setw(length -5) << std::right << longestStreak << "\n" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "WORD     ATTEMPTS      WIN" << std::endl;
    std::cout << "--------------------------" << std::endl;

    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << std::setw(12) << attempts[i] << std::setw(9) << wins[i] << std::endl;
    }

    std::cout << "\n" << "\n";
    std::cout << "Please [enter] to continue " << std::endl;
}
#endif