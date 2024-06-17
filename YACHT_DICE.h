#ifndef YACHT_DICE_H
#define YACHT_DICE_H

#include <vector>
#include <string>

class YahtzeeGame {
private:
    int n;
    int l; //loser~~~~~~~~~~~~~~~~`
    static const int NUM_DICE = 5;
    static const int NUM_ROUNDS = 3;
    std::vector<int> dice;
    int rollCount;
    std::vector<std::string> players;
    std::vector<int> scores;

    void rollDice();
    void rerollDice(const std::vector<bool>& keep);
    void printDice() const;
    int calculateScore();
    int bonusPoints();

public:
    void explain();
    int getloser(); //getloser~~~~~~~~~~~~~~~~~~~~~~~`
    YahtzeeGame(int);
    void initializeGame();
    void playRound(int playerIndex);
    void printScores() const;
    void playGame();
};

#endif